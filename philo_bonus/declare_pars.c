/*
;;;;;	DECLARE_PARS.C
;;;;;	gmorra's philosophers
;;;;;	team created 2021-06-18 14:52 MSK:+0300
;;;;;	team locked 2021-06-19 12:20 MSK:+0300
*/

#include "philo_bonus.h"

static	void	set_semaphores(t_struct *global, char **argv, int argc)
{
	int	i;

	i = -1;
	global->forks = sem_open("forks", O_CREAT, 0777, ft_atoi(argv[1]));
	sem_unlink("forks");
	global->waiter = sem_open("waiter", O_CREAT, 0777, 1);
	sem_unlink("waiter");
	global->write = sem_open("write", O_CREAT, 0777, 1);
	sem_unlink("write");
	if (global->state->times_to_eat != -1)
	{
		global->eat = sem_open("eat", O_CREAT, 0777, 0);
		sem_unlink("eat");
	}
}

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
		global->state[i].pids = &global->pids[i];
		global->state[i].time_sleep = ft_atoi(argv[4]);
		global->state[i].eat = global->eat;
		global->state[i].waiter = global->waiter;
		global->state[i].forks = global->forks;
		global->state[i].write = global->write;
		global->state[i].time = &global->time;
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
			global->state[i].times_to_eat = 0;
		else
			global->state[i].times_to_eat = -1;
	}
	set_semaphores(global, argv, argc);
	global->pids = malloc(sizeof(pid_t) * ft_atoi(argv[1]));
	if (!global->pids)
		ft_error("Malloc Error!\n");
}
