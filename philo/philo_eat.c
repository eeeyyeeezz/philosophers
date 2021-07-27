/*
;;;;;	PHILO_EAT.C
;;;;;	gmorra's philosophers
;;;;;	team created 2021-06-18 14:52 MSK:+0300
;;;;;	team locked 2021-06-19 12:20 MSK:+0300
*/

#include "philo_one.h"

void	take_even_forks(t_state *state)
{
	if (state->philo_score % 2 == 0)
	{
		pthread_mutex_lock(state->write);
		printf("\033[0;35m[%lu]\033[0m %d \033[0;32mhas taken a L fork\033[0m\n",
			get_time(*state->time), state->philo_score);
		pthread_mutex_unlock(state->write);
	}
	else
	{
		pthread_mutex_lock(state->write);
		printf("\033[0;35m[%lu]\033[0m %d \033[0;32mhas taken a R fork\033[0m\n",
			get_time(*state->time), state->philo_score);
		pthread_mutex_unlock(state->write);
	}
}

void	take_odd_forks(t_state *state)
{
	if (state->philo_score % 2 == 0)
	{
		pthread_mutex_lock(state->write);
		printf("\033[0;35m[%lu]\033[0m %d \033[0;32mhas taken a R fork\033[0m\n",
			get_time(*state->time), state->philo_score);
		pthread_mutex_unlock(state->write);
	}
	else
	{
		pthread_mutex_lock(state->write);
		printf("\033[0;35m[%lu]\033[0m %d \033[0;32mhas taken a L fork\033[0m\n",
			get_time(*state->time), state->philo_score);
		pthread_mutex_unlock(state->write);
	}
}

void	philo_eat(t_state *state)
{
	lock_even_mutex(state);
	take_even_forks(state);
	lock_odd_mutex(state);
	take_odd_forks(state);
	state->philo_time = get_time(*state->time);
	pthread_mutex_lock(state->write);
	printf("\033[0;35m[%lu]\033[0m %d \033[0;34mis eating\033[0m\n",
		get_time(*state->time), state->philo_score);
	pthread_mutex_unlock(state->write);
	ft_usleep(state->time_eat);
	unlock_mutex(state);
}

void	philo_sleep(t_state *state)
{
	pthread_mutex_lock(state->write);
	printf("\033[0;35m[%lu]\033[0m %d \033[0;33mis sleeping\033[0m\n",
		get_time(*state->time), state->philo_score);
	pthread_mutex_unlock(state->write);
	ft_usleep(state->time_sleep);
}

void	*start_eat(void *tmp_state)
{
	int		count;
	t_state	*state;

	state = (t_state *)tmp_state;
	if (state->times_to_eat == -1)
		count = -1;
	else
		count = state->times_to_eat;
	while (count--)
	{
		philo_eat(state);
		philo_sleep(state);
		pthread_mutex_lock(state->write);
		printf("\033[0;35m[%lu]\033[0m %d \033[1;37mis thinking\033[0m\n",
			get_time(*state->time), state->philo_score);
		pthread_mutex_unlock(state->write);
	}
	if (state->done_eat != -1)
		state->done_eat = 1;
	pthread_mutex_lock(state->write);
	printf("\033[0;35m[%lu]\033[0m %d \033[2;37mhas finished eating!\033[0m\n",
		get_time(*state->time), state->philo_score);
	pthread_mutex_unlock(state->write);
	return (NULL);
}
