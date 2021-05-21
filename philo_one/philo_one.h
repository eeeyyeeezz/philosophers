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

typedef		struct	s_info
{
	int				philo_num;
	int				time_live;
	int				time_eat;
	int				time_sleep;
	int				times_to_eat;
}					t_info;

int		ft_atoi(const char *str);
int		ft_strlen(char *str);
int		ft_error(char *str);
int		ft_isnum(char c);
void	declare_struct(t_info *info, char **argv, int argc);
void	pars_arg(t_info *info, int argc, char **argv);
int		check_errors(int argc, char **argv);
int		check_argv_excess(char **argv);

#endif
