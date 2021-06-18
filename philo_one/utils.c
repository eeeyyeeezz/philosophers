#include "philo_one.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, &*s++, 1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	minus;

	i = 0;
	res = 0;
	minus = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			minus *= -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (minus * res);
}

void	ft_putnbr(int nb)
{
	if (nb < 0 && nb != -2147483648)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb == -2147483648)
		ft_putstr("-2147483648");
	else if (nb / 10 > 0)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	else
		ft_putchar(nb + 48);
}
