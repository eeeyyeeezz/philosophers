#include "philo_one.h"

void		pars_arg(t_info *info, int argc, char **argv)
{
	info->philo_num = ft_atoi(argv[1]);
	info->time_live = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->times_to_eat = (int)argv[5];
}

void		declare_struct(t_info *info, char **argv, int argc)
{
	info->philo_num = 0;
	info->time_live = 0;
	info->time_eat = 0;
	info->time_sleep = 0;
	if (argc == 6)
		info->times_to_eat = 0;
	else 
		info->times_to_eat = -1;
}