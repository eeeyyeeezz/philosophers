/*
;;;;;	GETTIME.C
;;;;;	gmorra's philosophers
;;;;;	team created 2021-06-18 14:52 MSK:+0300
;;;;;	team locked 2021-06-19 12:20 MSK:+0300
*/

#include "philo_bonus.h"

void	ft_usleep(ssize_t time)
{
	struct timeval	t1;
	ssize_t			strace;

	gettimeofday(&t1, NULL);
	strace = t1.tv_sec * 1000 + t1.tv_usec / 1000;
	while (time > (t1.tv_sec * 1000 + t1.tv_usec / 1000) - strace)
	{
		gettimeofday(&t1, NULL);
		usleep(100);
	}
}

void	print_dead(t_struct *global, int i)
{
	printf("\033[0;35m[%zd]\033[0m %d \033[1;31mis dead\033[0m\n",
		get_time(*global->state[i].time),
		global->state[i].philo_score);
}

ssize_t	get_time(ssize_t time)
{
	struct timeval	t1;

	gettimeofday(&t1, NULL);
	return ((t1.tv_sec * 1000 + t1.tv_usec / 1000) - time);
}
