/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:20:26 by apanikov          #+#    #+#             */
/*   Updated: 2023/02/22 18:27:54 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printarg(va_list print, int out, char a)
{
	int	i;

	i = 0;
	if (a == 'd' || a == 'i')
		i = ft_digitint(va_arg(print, int));
	else if (a == 'c')
		i = ft_character(va_arg(print, int));
	else if (a == 's')
		i = ft_string(va_arg(print, char *));
	else if (a == 'x')
		i = ft_lowhex(va_arg(print, unsigned int));
	else if (a == 'X')
		i = ft_uphex(va_arg(print, unsigned int));
	else if (a == 'u')
		i = ft_unsitoa(va_arg(print, unsigned int));
	else if (a == 'p')
		i = ft_pointer(va_arg(print, unsigned long long));
	else if (a == '%')
		i = ft_character('%');
	i += out;
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		out;
	va_list	print;

	i = 0;
	out = 0;
	va_start(print, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			i++;
			out++;
		}
		else if (format[i] == '%' && format[i + 1])
		{
			out = ft_printarg(print, out, format[i + 1]);
			i += 2;
		}
	}
	va_end(print);
	return (out);
}
