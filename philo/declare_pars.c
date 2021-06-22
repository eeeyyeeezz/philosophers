/*
;;;;;	DECLARE_PARS.C
;;;;;	gmorra's philosophers
;;;;;	team created 2021-06-18 14:52 MSK:+0300
;;;;;	team locked 2021-06-19 12:20 MSK:+0300
*/

#include "philo_one.h"

void	pars_arg(t_struct *global, int argc, char **argv)
{
	int	i;

	i = -1;
	global->philo_num = ft_atoi(argv[1]);
	while (++i < ft_atoi(argv[1]))
	{
		global->state[i].philo_score = i + 1;
		global->state[i].philo_numbers = ft_atoi(argv[1]);
		global->state[i].time_live = ft_atoi(argv[2]);
		global->state[i].time_eat = ft_atoi(argv[3]);
		global->state[i].time_sleep = ft_atoi(argv[4]);
		global->state[i].write = &global->write;
		global->state[i].time = &global->time;
		pthread_mutex_init(&global->state[i].left, NULL);
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

void	declare_struct(t_struct	*global, char **argv, int argc)
{
	int	i;

	i = -1;
	pthread_mutex_init(&global->write, NULL);
	global->philo_dead = 0;
	while (++i < ft_atoi(argv[1]))
	{
		global->state[i].philo_numbers = 0;
		global->state[i].philo_score = 0;
		global->state[i].time_live = 0;
		global->state[i].time_eat = 0;
		global->state[i].philo_time = 0;
		global->state[i].time_sleep = 0;
		if (argc == 6)
		{
			global->state[i].done_eat = 0;
			global->state[i].times_to_eat = 0;
		}
		else
		{
			global->state[i].done_eat = -1;
			global->state[i].times_to_eat = -1;
		}
	}
}
