/*
;;;;;	THREADS.C
;;;;;	gmorra's philosophers
;;;;;	team created 2021-06-18 14:52 MSK:+0300
;;;;;	team locked 2021-06-19 12:20 MSK:+0300
*/

#include "philo_bonus.h"

static int	check_one_philo(t_state *state)
{
	if (state->philo_numbers == 1)
	{
		while (1)
		{
			if ((state->time_live - (get_time(*state->time)
						- state->philo_time)) <= 0)
			{
				printf("\033[0;35m[%zd]\033[0m %d \033[1;31mis dead\033[0m\n",
					get_time(*state->time),
					state->philo_score);
				return (1);
			}
		}
	}
	return (0);
}

void	*dead_thread(void *tmp_state)
{
	t_state		*state;
	int			i;

	state = (t_state *)tmp_state;
	if (check_one_philo(state) == 1)
		return (NULL);
	while (1)
	{
		i = -1;
		if ((state->time_live - (get_time(*state->time)
					- state->philo_time)) < 0
			&& state->philo_time != 0
			&& state->done_eat != 1)
		{
			sem_wait(state->write);
			printf("\033[0;35m[%zd]\033[0m %d \033[1;31mis dead\033[0m\n",
				get_time(*state->time), state->philo_score);
			// kill(*state->pids, 2);
			return (NULL);
		}
		// if (count_ate(global) == global->philo_num)
			// return (NULL);
	}
}

static	void	kill_all_processes(t_struct *global)
{
	int	i;

	i = -1;
	while (++i < global->philo_num)
		kill(global->pids[i], 9);
}

static	void	make_processes(t_struct *global, pthread_t *philo, int i)
{
	pthread_t	philo_dead;
	pthread_create(&philo_dead, NULL, dead_thread, (void *)&global->state[i]);
	pthread_create(&philo[i], NULL, start_eat, (void *)&global->state[i]);
	pthread_join(philo_dead, NULL);
	printf("ABOBA\n");
	pthread_detach(philo[i]);
	kill_all_processes(global);
}

void	processes_create(t_struct *global, pthread_t *philo)
{
	int			i;
	int			status;

	i = -1;
	// pthread_create(&philo_dead, NULL, dead_thread, (void *)global);
	while (++i < global->philo_num && !global->philo_dead)
	{
		global->pids[i] = fork();
		if (global->pids[i] == -1)
			ft_error("Fork Errror!\n");
		if (global->pids[i] == 0)
			make_processes(global, philo, i);
	}
	i = -1;
	while (++i < global->philo_num)
		waitpid(global->pids[i], &status, 0);
	// pthread_join(philo_dead, NULL);
	// i = -1;
	// while (++i < global->philo_num)
	// 	pthread_detach(philo[i]);
}