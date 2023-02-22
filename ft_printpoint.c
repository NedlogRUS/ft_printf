/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:28:45 by apanikov          #+#    #+#             */
/*   Updated: 2023/02/22 18:47:48 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_sizepointer(unsigned long long n)
{
	unsigned long long	i;

	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_pointer(unsigned long long n)
{
	unsigned long long	i;
	int					j;
	char				*out;

	i = ft_sizepointer(n);
	out = (char *)malloc(sizeof(char) * (i + 1));
	if (!out)
		return (0);
	if (n == 0)
	{
		free (out);
		return (ft_string("0x0"));
	}
	out[i] = '\0';
	while (n != 0)
	{
		out[--i] = (char)((n % 16) + '0');
		if (out[i] >= ':' && out[i] <= '?')
			out[i] += 39;
		n = n / 16;
	}
	ft_string("0x");
	j = ft_string(out) + 2;
	free (out);
	return (j);
}
