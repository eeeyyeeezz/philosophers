/*
;;;;;   PHILO_ONE_C 
;;;;;   gmorra's philosophers  
;;;;;   team created 2021-06-18 14:52 MSK:+0300
;;;;;   team locked ???? 
*/

#include "philo_one.h"


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