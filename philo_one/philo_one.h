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

typedef		struct s_state
{
	int				philo_score;
	int				time_live;
	int				time_eat;
	int				time_sleep;
	int				times_to_eat;
	pthread_mutex_t	left;
	pthread_mutex_t	*right;
}					t_state;


typedef		struct s_struct
{
	int				philo_num;
	t_state			*state;
}					t_struct;


int		ft_atoi(const char *str);
int		ft_strlen(char *str);
int		ft_error(char *str);
int		ft_isnum(char c);
void	declare_state(t_struct *global, int argc);
void	declare_struct(t_struct *global, char **argv, int argc);
void	pars_arg(t_struct *global, int argc, char **argv);
int		check_errors(int argc, char **argv);
int		check_argv_excess(char **argv);

#endif
