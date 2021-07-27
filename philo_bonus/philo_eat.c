/*
;;;;;	PHILO_EAT.C
;;;;;	gmorra's philosophers
;;;;;	team created 2021-06-18 14:52 MSK:+0300
;;;;;	team locked 2021-06-19 12:20 MSK:+0300
*/

#include "philo_bonus.h"

static	void	take_fork(t_state *state)
{
	sem_wait(state->waiter);
	sem_wait(state->forks);
	sem_wait(state->write);
	printf("\033[0;35m[%lu]\033[0m %d \033[0;32mhas taken a fork\033[0m\n",
		get_time(*state->time), state->philo_score);
	sem_post(state->write);
	sem_wait(state->forks);
	sem_wait(state->write);
	printf("\033[0;35m[%lu]\033[0m %d \033[0;32mhas taken a fork\033[0m\n",
		get_time(*state->time), state->philo_score);
	sem_post(state->write);
	sem_post(state->waiter);
}

static	void	put_forks(t_state *state)
{
	sem_post(state->forks);
	sem_post(state->forks);
}

void	philo_eat(t_state *state)
{
	take_fork(state);
	state->philo_time = get_time(*state->time);
	sem_wait(state->write);
	printf("\033[0;35m[%lu]\033[0m %d \033[0;34mis eating\033[0m\n",
		get_time(*state->time), state->philo_score);
	sem_post(state->write);
	ft_usleep(state->time_eat);
	put_forks(state);
}

void	philo_sleep(t_state *state)
{
	sem_wait(state->write);
	printf("\033[0;35m[%lu]\033[0m %d \033[0;33mis sleeping\033[0m\n",
		get_time(*state->time), state->philo_score);
	sem_post(state->write);
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
		sem_wait(state->write);
		printf("\033[0;35m[%lu]\033[0m %d \033[1;37mis thinking\033[0m\n",
			get_time(*state->time), state->philo_score);
		sem_post(state->write);
	}
	state->done_eat = 1;
	sem_post(state->eat);
	printf("\033[0;35m[%lu]\033[0m %d \033[2;37mhas finished eating!\033[0m\n",
		get_time(*state->time), state->philo_score);
	return (NULL);
}
