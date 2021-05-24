/*
;;;;;   PHILO_ONE_C 
;;;;;   gmorra's philosophers  
;;;;;   team created ??? 
;;;;;   team locked ???? 
*/

#include "philo_one.h"

void		lock_mutex(t_state *state)
{
	if (state->philo_score % 2 == 0)
	{
		pthread_mutex_lock(&state->left);	
		pthread_mutex_lock(state->right);	
	}
	else
	{
		pthread_mutex_lock(state->right);
		pthread_mutex_lock(&state->left);	
	}
}

void		unlock_mutex(t_state *state)
{
	if (state->philo_score % 2 == 0)
	{
		pthread_mutex_unlock(&state->left);	
		pthread_mutex_unlock(state->right);	
	}
	else
	{
		pthread_mutex_unlock(state->right);
		pthread_mutex_unlock(&state->left);	
	}
}

	// putnbr_str(state->philo_score, " Has taken a fork\n");
	// putnbr_str(state->philo_score, " Has taken a fork\n");
	// putnbr_str(state->philo_score, " Is eating\n");

void		philo_eat(t_state *state)
{
	lock_mutex(state);
	pthread_mutex_lock(state->write);
	printf("\033[0;35m[%lu]\033[0m %d \033[0;32mhas taken a fork\033[0m\n", get_time(*state->time), state->philo_score);
	printf("\033[0;35m[%lu]\033[0m %d \033[0;32mhas taken a fork\033[0m\n", get_time(*state->time), state->philo_score);
	printf("\033[0;35m[%lu]\033[0m %d \033[0;34mis eating\033[0m\n", get_time(*state->time), state->philo_score);
	pthread_mutex_unlock(state->write);
	ft_usleep(state->time_eat);
	unlock_mutex(state);
}

void		philo_sleep(t_state *state)
{
	printf("\033[0;35m[%lu]\033[0m %d \033[0;31mis sleping\033[0m\n", get_time(*state->time), state->philo_score);
	ft_usleep(state->time_sleep);
}

void		*start_eat(void *tmp_state)
{
	t_state *state;
	state = (t_state *)tmp_state;

	if (!state->philo_dead)
	{
		philo_eat(state);
		philo_sleep(state);
	}
	return (NULL);
}

void		pthreads_create(t_struct *global, pthread_t *philo, int argc)
{
	int i;

	i = -1;
	while (++i < global->philo_num)
	{
		// write(1, "kavo\n", 5);
		pthread_create(&philo[i], NULL, start_eat, (void *)&global->state[i]);
		// pthread_join(philo[i], (void *)&global->state[i]);
	}
}

int			main(int argc, char **argv)
{	
	t_struct		global;
	pthread_t		*philo;

	global.time = get_time(0);
	check_errors(argc, argv);
	global.state = malloc(sizeof(t_state) * ft_atoi(argv[1]));
	if (!global.state)
		return (ft_error("Malloc Error!\n"));
	declare_struct(&global, argv, argc);
	pars_arg(&global, argc, argv);
	// printf("CHECK [%d]\n", global.state[3].time_eat);
	philo = malloc(sizeof(pthread_t) * (global.philo_num + 1));
	if (!philo)
		return (ft_error("Malloc Error!\n"));
	pthreads_create(&global, philo, argc);
	while (1){}
}

// !) ft_error освобождение памяти добавить