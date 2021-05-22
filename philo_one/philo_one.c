/*
;;;;;   PHILO_ONE_C 
;;;;;   gmorra's philosophers  
;;;;;   team created ??? 
;;;;;   team locked ???? 
*/

#include "philo_one.h"

void		*print(void *buf)
{
	pthread_mutex_t		mutex;

	pthread_mutex_lock(&mutex);


	pthread_mutex_unlock(&mutex);
	return (NULL);
}

void		create_threads(pthread_t *philo, pthread_mutex_t *forks, t_info *info)
{
	int		i;

	i = -1;
	while (++i < info->philo_num)
		pthread_create(&philo[i], NULL, print, NULL);
}


int			main(int argc, char **argv)
{	
	pthread_t		*philo;
	pthread_mutex_t	*forks;
	t_info		info;

	check_errors(argc, argv);
	declare_struct(&info, argv, argc);
	pars_arg(&info, argc, argv);
	philo = malloc(sizeof(pthread_t) * (info.philo_num + 1));
	if (!philo)
		return (ft_error("Malloc Error!\n"));
	forks = malloc(sizeof(pthread_mutex_t) * info.philo_num);
	if (!forks)
		return (ft_error("Malloc Error!\n"));
	create_threads(philo, forks, &info);

	// printf(")) [%d] [%d] [%d] [%d]\n", info.philo_num, info.time_live, info.time_eat, info.time_sleep);
}

// !) ft_error освобождение памяти добавить