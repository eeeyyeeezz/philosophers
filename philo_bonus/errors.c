/*
;;;;;	ERRORS.C
;;;;;	gmorra's philosophers
;;;;;	team created 2021-06-18 14:52 MSK:+0300
;;;;;	team locked 2021-06-19 12:20 MSK:+0300
*/

#include "philo_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

int	ft_isnum(char c)	
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	check_argv_excess(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isnum(argv[i][j]))
				return (ft_error("Extra characters in arguments\n"));
			j++;
		}
	}
	return (0);
}		

int	check_errors(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (ft_error("Error! Arguments\n"));
	check_argv_excess(argv);
	return (1);
}
