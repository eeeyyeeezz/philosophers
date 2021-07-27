/*
;;;;;	PHILO_BONUS.H
;;;;;	gmorra's philosophers
;;;;;	team created 2021-06-18 14:52 MSK:+0300
;;;;;	team locked 2021-06-19 12:20 MSK:+0300
*/

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include	<sys/time.h>
# include	<pthread.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<semaphore.h>
# include	<signal.h>

typedef struct s_state
{
	ssize_t			*time;
	pid_t			*pids;
	int				philo_numbers;
	int				philo_score;
	ssize_t			philo_time;
	int				time_live;
	int				time_eat;
	int				time_sleep;
	int				times_to_eat;
	int				done_eat;
	sem_t			*forks;
	sem_t			*waiter;
	sem_t			*write;
	sem_t			*eat;
}					t_state;

typedef struct s_struct
{
	ssize_t			time;
	int				philo_num;
	int				philo_dead;
	pid_t			*pids;
	sem_t			*eat;
	sem_t			*forks;
	sem_t			*waiter;
	sem_t			*write;
	t_state			*state;
}					t_struct;

ssize_t			get_time(ssize_t time);
void			ft_free(void **var);
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
void			unlock_mutex(t_state *state);
void			lock_even_mutex(t_state *state);
void			lock_odd_mutex(t_state *state);
void			double_lock_mutex(t_state *state);
void			print_dead(t_struct *global, int i);
void			declare_state(t_struct *global, int argc);
void			kill_all_processes(t_struct *global);
void			processes_create(t_struct *global, pthread_t *philo);
void			pars_arg(t_struct *global, int argc, char **argv);
void			declare_struct(t_struct *global, char **argv, int argc);
int				check_errors(int argc, char **argv);
int				check_argv_excess(char **argv);

#endif
