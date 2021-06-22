/*
;;;;;	PHILO_ONE.C
;;;;;	gmorra's philosophers
;;;;;	team created 2021-06-18 14:52 MSK:+0300
;;;;;	team locked 2021-06-19 12:20 MSK:+0300
*/

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include	<sys/time.h>
# include	<pthread.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>

typedef struct s_state
{
	ssize_t			*time;
	int				philo_numbers;
	int				philo_score;
	int				time_live;
	int				time_eat;
	ssize_t			philo_time;
	int				time_sleep;
	int				done_eat;
	int				times_to_eat;
	pthread_mutex_t	left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*write;
}					t_state;

typedef struct s_struct
{
	ssize_t			time;
	int				philo_num;
	int				philo_dead;
	pthread_mutex_t	write;
	t_state			*state;
}					t_struct;

int				count_ate(t_struct *global);
void			*start_eat(void *tmp_state);
void			philo_eat(t_state *state);
void			ft_usleep(ssize_t time);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putstr(char *s);
int				ft_atoi(const char *str);
int				ft_strlen(char *str);
int				ft_error(char *str);
int				ft_isnum(char c);
ssize_t			get_time(ssize_t time);
void			unlock_mutex(t_state *state);
void			lock_even_mutex(t_state *state);
void			lock_odd_mutex(t_state *state);
void			double_lock_mutex(t_state *state);
void			print_dead(t_struct *global, int i);
void			declare_state(t_struct *global, int argc);
void			pthreads_create(t_struct *global, pthread_t *philo);
void			declare_struct(t_struct *global, char **argv, int argc);
void			pars_arg(t_struct *global, int argc, char **argv);
int				check_errors(int argc, char **argv);
int				check_argv_excess(char **argv);

#endif
