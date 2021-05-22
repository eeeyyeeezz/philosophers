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

void		*start_eat(void *tmp_state)
{
	t_state *state;
	state = (t_state *)tmp_state;

	lock_mutex(state);


	unlock_mutex(state);
	return (NULL);
}

void		pthreads_create(t_struct *global, pthread_t *philo, int argc)
{
	int i;

	i = -1;
	while (++i < global->philo_num)
		pthread_create(&philo[i], NULL, start_eat, (void *)&global->state[i]);
}

int			main(int argc, char **argv)
{	
	t_struct		global;
	pthread_t		*philo;

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
}

// !) ft_error освобождение памяти добавить