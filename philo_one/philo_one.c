/*
;;;;;   PHILO_ONE_C 
;;;;;   gmorra's philosophers  
;;;;;   team created ??? 
;;;;;   team locked ???? 
*/

#include "philo_one.h"

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

int			ft_isnum(char c)	
{
	if (c >= 48 && c <= 57)
		return (1);
	else 
		return (0);
}

int			check_argv_excess(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			// printf("lol [%c]\n", argv[i][j]);
			if (!ft_isnum(argv[i][j]))
				return (ft_error("Extra characters in arguments\n"));
			j++;
		}
	}
	return (0);
}		

int		check_errors(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (ft_error("Error! Arguments\n"));		
	check_argv_excess(argv);
	return (1);
}



int			main(int argc, char **argv)
{	
	pthread_t	*philo;

	check_errors(argc, argv);
	pars_arg(argc, argv);
}

// !) ft_error освобождение памяти добавить