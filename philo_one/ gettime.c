#include "philo_one.h"

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

ssize_t	get_time(ssize_t time)
{
	struct timeval	t1;

	gettimeofday(&t1, NULL);
	return ((t1.tv_sec * 1000 + t1.tv_usec / 1000) - time);
}
