/*
;;;;;   PHILO_ONE_H 
;;;;;   gmorra's philosophers  
;;;;;   team created ??? 
;;;;;   team locked ???? 
*/

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
#include <sys/time.h>

typedef		struct s_state
{
	ssize_t			*time;
	int				philo_dead;
	int				philo_score;
	int				time_live;
	int				time_eat;
	ssize_t			philo_time;		// когда последнйи раз поел
	int				time_sleep;
	int				times_to_eat;	
	pthread_mutex_t	left;
	pthread_mutex_t	*right;
	pthread_mutex_t *write;
}					t_state;


typedef		struct s_struct
{
	ssize_t			time;
	int				philo_num;
	pthread_mutex_t	write;
	t_state			*state;
}					t_struct;


void			ft_usleep(ssize_t time);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putstr(char *s);
void			putnbr_str(int nb, char *str);
int				ft_atoi(const char *str);
int				ft_strlen(char *str);
int				ft_error(char *str);
int				ft_isnum(char c);
ssize_t			get_time(ssize_t time);
void			declare_state(t_struct *global, int argc);
void			declare_struct(t_struct *global, char **argv, int argc);
void			pars_arg(t_struct *global, int argc, char **argv);
int				check_errors(int argc, char **argv);
int				check_argv_excess(char **argv);

#endif
