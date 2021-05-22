#include "philo_one.h"

void		pars_arg(t_struct *global, int argc, char **argv)
{
	int i;

	i = -1;
	global->philo_num = ft_atoi(argv[1]);
	while (++i < ft_atoi(argv[1]))
	{
		global->state[i].philo_score = i;
		global->state[i].time_live = ft_atoi(argv[2]);
		global->state[i].time_eat = ft_atoi(argv[3]);
		global->state[i].time_sleep = ft_atoi(argv[4]);
		if (i == global->philo_num)	
			global->state[i].right = &global->state[0].left;
		else
			global->state[i].right = &global->state[i + 1].left;
		if (argc == 6)
			global->state[i].times_to_eat = (int)argv[5];
		else 
			global->state[i].times_to_eat = -1;
	}
}

void		declare_struct(t_struct	*global, char **argv, int argc)
{
	int i;

	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		global->state[i].philo_score = 0;
		global->state[i].time_live = 0;
		global->state[i].time_eat = 0;
		global->state[i].time_sleep = 0;
		if (argc == 6)
			global->state[i].times_to_eat = 0;
		else 
			global->state[i].times_to_eat = -1;
	}
}