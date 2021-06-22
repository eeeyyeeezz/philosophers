/*
;;;;;	MUTEX.C
;;;;;	gmorra's philosophers
;;;;;	team created 2021-06-18 14:52 MSK:+0300
;;;;;	team locked 2021-06-19 12:20 MSK:+0300
*/

#include "philo_one.h"

void	double_lock_mutex(t_state *state)
{
	if (state->philo_score % 2 == 0)
	{
		pthread_mutex_lock(&state->left);
		pthread_mutex_lock(state->right);
	}
	else
	{
		pthread_mutex_lock(state->right);
		pthread_mutex_lock(&state->left);
	}
}

void	unlock_mutex(t_state *state)
{
	if (state->philo_score % 2 == 0)
	{
		pthread_mutex_unlock(&state->left);
		pthread_mutex_unlock(state->right);
	}
	else
	{
		pthread_mutex_unlock(state->right);
		pthread_mutex_unlock(&state->left);
	}
}

void	lock_even_mutex(t_state *state)
{
	if (state->philo_score % 2 == 0)
		pthread_mutex_lock(&state->left);
	else
		pthread_mutex_lock(state->right);
}

void	lock_odd_mutex(t_state *state)
{
	if (state->philo_score % 2 == 0)
		pthread_mutex_lock(state->right);
	else
		pthread_mutex_lock(&state->left);
}
