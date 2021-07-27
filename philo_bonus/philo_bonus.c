/*
;;;;;	PHILO_BONUS_C
;;;;;	gmorra's philosophers
;;;;;	team created 2021-06-18 14:52 MSK:+0300
;;;;;	team locked 2021-06-19 12:20 MSK:+0300
*/

#include "philo_bonus.h"

static	void	free_all(t_struct *global)
{
	int	i;

	i = -1;
	ft_free((void *)&global->state);
	ft_free((void *)&global->pids);
}

int	main(int argc, char **argv)
{	
	t_struct		global;
	pthread_t		*philo;

	global.time = get_time(0);
	check_errors(argc, argv);
	global.state = malloc(sizeof(t_state) * (ft_atoi(argv[1])));
	if (!global.state)
		return (ft_error("Malloc Error!\n"));
	declare_struct(&global, argv, argc);
	pars_arg(&global, argc, argv);
	philo = malloc(sizeof(pthread_t) * global.philo_num + 1);
	if (!philo)
		return (ft_error("Malloc Error!\n"));
	processes_create(&global, philo);
	free_all(&global);
	return (0);
}
