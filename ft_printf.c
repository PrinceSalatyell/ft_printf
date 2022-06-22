/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:47:07 by josanton          #+#    #+#             */
/*   Updated: 2022/04/06 17:28:30 by josanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr(char *str, char c, int n)
{
	int	x;

	x = 0;
	if (n)
	{
		write(1, &c, 1);
		return (1);
	}
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[x])
		x++;
	write(1, str, x);
	return (x);
}

static int	ft_putnbr_base(unsigned long long n, int b, char *base, int tof)
{
	int	res;

	res = 0;
	if (tof)
		res += ft_putstr("0x", 0, 0);
	if (n / b == 0)
		res += ft_putstr(NULL, base[n], 1);
	else
	{
		res += ft_putnbr_base(n / b, b, base, 0);
		res += ft_putnbr_base(n % b, b, base, 0);
	}
	return (res);
}

static void	check(char c, va_list args, int *x)
{
	int			d;
	long long	sig;

	if (c == 'c')
		*x += ft_putstr(NULL, va_arg(args, int), 1);
	else if (c == 's')
		*x += ft_putstr(va_arg(args, char *), 0, 0);
	else if (c == 'p')
		*x += ft_putnbr_base(va_arg(args, unsigned long int), 16, HEX_L, 1);
	else if (c == 'd' || c == 'i')
	{
		d = va_arg(args, int);
		*x += write(1, "-", (d < 0));
		sig = ((d >= 0) - (d < 0));
		*x += ft_putnbr_base((d * sig), 10, DEC, 0);
	}
	else if (c == 'u')
		*x += ft_putnbr_base(va_arg(args, unsigned int), 10, DEC, 0);
	else if (c == 'x')
		*x += ft_putnbr_base(va_arg(args, unsigned int), 16, HEX_L, 0);
	else if (c == 'X')
		*x += ft_putnbr_base(va_arg(args, unsigned int), 16, HEX_U, 0);
	else if (c == '%')
		*x += ft_putstr(NULL, '%', 1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		res;

	i = 0;
	res = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			check(str[++i], args, &res);
		else
		{
			ft_putstr(NULL, str[i], 1);
			res++;
		}
		i++;
	}
	va_end(args);
	return (res);
}
