#include "philo_one.h"

void		pars_arg(t_struct *global, int argc, char **argv)
{
	int i;

	i = -1;
	global->philo_num = ft_atoi(argv[1]);
	while (++i < ft_atoi(argv[1]))
	{
		global->state[i].philo_score = i + 1;
		global->state[i].time_live = ft_atoi(argv[2]);
		global->state[i].time_eat = ft_atoi(argv[3]);
		global->state[i].time_sleep = ft_atoi(argv[4]);
		global->state[i].write = &global->write;
		global->state[i].time = &global->time;
		pthread_mutex_init(&global->state[i].left, NULL);
		// pthread_mutex_init(global->state[i].right, NULL);
		if (i == global->philo_num - 1)	
			global->state[i].right = &global->state[0].left;
		else
		
			global->state[i].right = &global->state[i + 1].left;
		if (argc == 6)
			global->state[i].times_to_eat = ft_atoi(argv[5]);
		else 
			global->state[i].times_to_eat = -1;
	}
}

void		declare_struct(t_struct	*global, char **argv, int argc)
{
	int i;

	i = -1;
	pthread_mutex_init(&global->write, NULL);
	// pthread_mutex_init(&global->state->left, NULL);
	// pthread_mutex_init(global->state->right, NULL);
	while (++i < ft_atoi(argv[1]))
	{
		global->state[i].philo_dead = 0;
		global->state[i].philo_score = 0;
		global->state[i].time_live = 0;
		global->state[i].time_eat = 0;
		global->state[i].philo_time = 0;
		global->state[i].time_sleep = 0;
		if (argc == 6)
			global->state[i].times_to_eat = 0;
		else 
			global->state[i].times_to_eat = -1;
	}
}