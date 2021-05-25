/*
;;;;;   PHILO_ONE_C 
;;;;;   gmorra's philosophers  
;;;;;   team created ??? 
;;;;;   team locked ???? 
*/

#include "philo_one.h"

void		philo_eat(t_state *state)
{
	lock_left_mutex(state);
	printf("\033[0;35m[%lu]\033[0m %d \033[0;32mhas taken a fork\033[0m\n", get_time(*state->time), state->philo_score);
	lock_right_mutex(state);
	printf("\033[0;35m[%lu]\033[0m %d \033[0;32mhas taken a fork\033[0m\n", get_time(*state->time), state->philo_score);
	printf("\033[0;35m[%lu]\033[0m %d \033[0;34mis eating\033[0m\n", get_time(*state->time), state->philo_score);
	state->philo_time = get_time(*state->time);
	ft_usleep(state->time_eat);
	unlock_mutex(state);
}

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
	return (NULL);
}

void		*dead_thread(void *tmp_state)
{
	t_struct *global;
	int i;
	global = (t_struct *)tmp_state;

	while (1)
	{
		usleep(global->state[0].time_live / 4);
		i = -1;
		// printf("INFO %d\n", state->philo_score);
		while (++i < global->philo_num)
		{
			if ((global->state[i].time_live - (get_time(*global->state[i].time) - global->state[i].philo_time)) <= 0 && global->state[i].philo_time != 0)
			{
				pthread_mutex_lock(global->state[i].write);	
				printf("\033[0;35m[%zd]\033[0m %d \033[1;31mis dead\033[0m\n", get_time(*global->state[i].time), global->state[i].philo_score);
				return (NULL);
			}
		}
		
	}
	return (NULL);
}

void		pthreads_create(t_struct *global, pthread_t *philo, int argc)
{
	int			i;
	pthread_t	philo_dead;

	i = -1;
	pthread_create(&philo_dead, NULL, dead_thread, (void *)global);
	while (++i < global->philo_num)
		pthread_create(&philo[i], NULL, start_eat, (void *)&global->state[i]);
	pthread_join(*philo, NULL);
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
	// while (1)
	// {
	// 	// check_dead(global.state);
	// 	// if (global.state->philo_dead)
	// 		// exit(1);
	// }
}

// !) ft_error освобождение памяти добавить
// Защищать вывод мьютексом? 
// Когда все поели выйти из программы