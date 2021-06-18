#include "philo_one.h"

void		take_even_forks(t_state *state)
{
	if (state->philo_score % 2 == 0)
		printf("\033[0;35m[%lu]\033[0m %d \033[0;32mhas taken a L fork\033[0m\n", get_time(*state->time), state->philo_score);
	else
		printf("\033[0;35m[%lu]\033[0m %d \033[0;32mhas taken a R fork\033[0m\n", get_time(*state->time), state->philo_score);
}

void		take_odd_forks(t_state *state)
{
	if (state->philo_score % 2 == 0)
		printf("\033[0;35m[%lu]\033[0m %d \033[0;32mhas taken a R fork\033[0m\n", get_time(*state->time), state->philo_score);
	else
		printf("\033[0;35m[%lu]\033[0m %d \033[0;32mhas taken a L fork\033[0m\n", get_time(*state->time), state->philo_score);
}

void		philo_eat(t_state *state)
{
	if (state->philo_numbers % 2 != 0 && (state->philo_score % 2 != 0 || state->philo_score == state->philo_numbers) && state->philo_numbers != 1)
		ft_usleep(state->time_eat);
	lock_even_mutex(state);
	take_even_forks(state);
	lock_odd_mutex(state);
	take_odd_forks(state);
	state->philo_time = get_time(*state->time);
	printf("\033[0;35m[%lu]\033[0m %d \033[0;34mis eating\033[0m\n", get_time(*state->time), state->philo_score);
	ft_usleep(state->time_eat);
	unlock_mutex(state);
}