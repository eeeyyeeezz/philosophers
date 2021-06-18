/*
;;;;;   PHILO_ONE_C 
;;;;;   gmorra's philosophers  
;;;;;   team created ??? 
;;;;;   team locked ???? 
*/

#include "philo_one.h"

void		philo_sleep(t_state *state)
{
	printf("\033[0;35m[%lu]\033[0m %d \033[0;33mis sleeping\033[0m\n", get_time(*state->time), state->philo_score);
	ft_usleep(state->time_sleep);
}

void		philo_think(t_state *state)
{
	printf("\033[0;35m[%lu]\033[0m %d \033[1;37mis thinking\033[0m\n", get_time(*state->time), state->philo_score);
}

void		*start_eat(void *tmp_state)
{
	t_state *state;
	state = (t_state *)tmp_state;
	int count;
	int dead;

	if (state->times_to_eat == -1)
		count = -1;
	else	
		count = state->times_to_eat;
	while (count--)
	{
		philo_eat(state);
		philo_sleep(state);
		philo_think(state);
	}
	if (state->done_eat != -1)
		state->done_eat = 1;
	printf("\033[0;35m[%lu]\033[0m %d \033[2;37mhas finished eating!\033[0m\n", get_time(*state->time), state->philo_score);
	return (NULL);
}

int			count_ate(t_struct *global)
{
	int i;
	int count;

	i = -1;
	count = 0;
	if (global->state[0].times_to_eat != -1)
	{
		while (global->state[++i].done_eat == 1)
			count++;
	}
	return (count);
}

void		*dead_thread(void *tmp_state)
{
	t_struct *global;
	int i;
	global = (t_struct *)tmp_state;

	if (global->state[i].philo_numbers == 1)
	{
		while (1)
		{
			if ((global->state[i].time_live - (get_time(*global->state[i].time) - global->state[i].philo_time)) <= 0)
			{
				printf("\033[0;35m[%zd]\033[0m %d \033[1;31mis dead\033[0m\n", get_time(*global->state[i].time), global->state[i].philo_score);
				return (NULL);
			}
		}
	}
	while (1)
	{
		i = -1;
		while (++i < global->philo_num)
		{
			if ((global->state[i].time_live - (get_time(*global->state[i].time) - global->state[i].philo_time)) < 0 
			&& global->state[i].philo_time != 0 && global->state[i].done_eat != 1)
			{
				printf("timelive [%d] time [%zd] philotime [%zd] philo [%d]\n", global->state[i].time_live, get_time(*global->state[i].time), global->state[i].philo_time, global->state[i].philo_score);
				global->philo_dead = 1;
				pthread_mutex_lock(global->state[i].write);	
				printf("\033[0;35m[%zd]\033[0m %d \033[1;31mis dead\033[0m\n", get_time(*global->state[i].time), global->state[i].philo_score);
				return (NULL);
			}
		}
		if (count_ate(global) == global->philo_num)
			return (NULL);		
	}
	return (NULL);
}

int			check_eat(t_struct *global)
{
	int i;

	if (global->state[0].times_to_eat != -1)
	{
		i = 0;
		while(global->state[i].done_eat == 1)
			i++;
		if (i == global->philo_num)
			return (1);
	}
	return (0);
}

void		free_all(t_struct *global)
{
	int i;

	i = -1;
	free(global->state);
	while (&global->state[++i])
		pthread_mutex_destroy(&global->state->left);
	pthread_mutex_destroy(&global->write);
}

void		pthreads_create(t_struct *global, pthread_t *philo, int argc)
{
	pthread_t	philo_dead;
	int			i;

	i = -1;
	pthread_create(&philo_dead, NULL, dead_thread, (void *)global);
	while (++i < global->philo_num && !global->philo_dead)
		pthread_create(&philo[i], NULL, start_eat, (void *)&global->state[i]);
	pthread_join(philo_dead, NULL);
	pthread_detach(*philo);
}

void		pthreads_dead(t_struct *global)
{
	pthread_t	philo_dead;

	pthread_create(&philo_dead, NULL, dead_thread, (void *)global);
	pthread_join(philo_dead, NULL);
}

int			main(int argc, char **argv)
{	
	t_struct		global;
	pthread_t		*philo;

	global.time = get_time(0);
	check_errors(argc, argv);
	global.state = malloc(sizeof(t_state) * (ft_atoi(argv[1]) + 1));
	if (!global.state)
		return (ft_error("Malloc Error!\n"));
	declare_struct(&global, argv, argc);
	pars_arg(&global, argc, argv);
	philo = malloc(sizeof(pthread_t) * (global.philo_num + 1));
	if (!philo)
		return (ft_error("Malloc Error!\n"));
	pthreads_create(&global, philo, argc);
	return (0);
}

// !) ft_error освобождение памяти добавить
// Когда все поели выйти из программ
// Защищать вывод мьютексом? 