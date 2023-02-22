/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:51:18 by apanikov          #+#    #+#             */
/*   Updated: 2023/02/22 19:25:23 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_zerodigint(char *out)
{
	free (out);
	return (ft_string("0"));
}

int	ft_character(char a)
{
	write(1, &a, 1);
	return (1);
}

int	ft_string(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
			i++;
	}
	return (i);
}

static int	ft_size(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_digitint(int n)
{
	int		i;
	int		sign;
	char	*out;

	i = ft_size(n);
	sign = 1;
	if (n < 0)
		sign = -1;
	i = i + (n <= 0);
	out = (char *)malloc(sizeof(char) * (i + 1));
	if (!out)
		return (0);
	if (n == 0)
		return (ft_zerodigint(out));
	out[i] = '\0';
	while (n != 0)
	{
		out[--i] = (char)((n % 10) * sign + '0');
		n = n / 10;
	}
	if (sign < 0)
		out[--i] = '-';
	i = ft_string(out);
	free (out);
	return (i);
}
/*
int	ft_digitint(int a)
{
	unsigned int	i;
	static int	j;
	char			c;

    j = 0;
	if (a < 0)
	{
		write(1, "-", 1);
		i = -a;
	}
	else
		i = a;
	if (i > 9)
	{
		ft_digitint(i / 10);
		i %= 10;
	}
	c = i + '0';
	write(1, &c, 1);
    j++;
	return (j);
}
*/
