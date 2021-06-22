/*
;;;;;	THREADS.C
;;;;;	gmorra's philosophers
;;;;;	team created 2021-06-18 14:52 MSK:+0300
;;;;;	team locked 2021-06-19 12:20 MSK:+0300
*/

#include "philo_one.h"

static int	check_one_philo(t_struct *global)
{
	if (global->state[0].philo_numbers == 1)
	{
		while (1)
		{
			if ((global->state[0].time_live - (get_time(*global->state[0].time)
						- global->state[0].philo_time)) <= 0)
			{
				printf("\033[0;35m[%zd]\033[0m %d \033[1;31mis dead\033[0m\n",
					get_time(*global->state[0].time),
					global->state[0].philo_score);
				return (1);
			}
		}
	}
	return (0);
}

void	*dead_thread(void *tmp_state)
{
	t_struct	*global;
	int			i;

	global = (t_struct *)tmp_state;
	if (check_one_philo(global) == 1)
		return (NULL);
	while (1)
	{
		i = -1;
		while (++i < global->philo_num)
		{
			if ((global->state[i].time_live - (get_time(*global->state[i].time)
						- global->state[i].philo_time)) < 0
				&& global->state[i].philo_time != 0
				&& global->state[i].done_eat != 1)
			{
				global->philo_dead = 1;
				pthread_mutex_lock(global->state[i].write);
				print_dead(global, i);
				return (NULL);
			}
		}
		if (count_ate(global) == global->philo_num)
			return (NULL);
	}
}

void	free_all(t_struct *global)
{
	int	i;

	i = -1;
	free(global->state);
	while (&global->state[++i])
		pthread_mutex_destroy(&global->state->left);
	pthread_mutex_destroy(&global->write);
}

void	pthreads_create(t_struct *global, pthread_t *philo)
{
	int			i;
	pthread_t	philo_dead;

	i = -1;
	pthread_create(&philo_dead, NULL, dead_thread, (void *)global);
	while (++i < global->philo_num && !global->philo_dead)
		pthread_create(&philo[i], NULL, start_eat, (void *)&global->state[i]);
	pthread_join(philo_dead, NULL);
	pthread_detach(*philo);
}

void	pthreads_dead(t_struct *global)
{
	pthread_t	philo_dead;

	pthread_create(&philo_dead, NULL, dead_thread, (void *)global);
	pthread_join(philo_dead, NULL);
}
