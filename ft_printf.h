/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:19:21 by apanikov          #+#    #+#             */
/*   Updated: 2023/02/22 18:20:04 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_digitint(int a);
int	ft_character(char a);
int	ft_string(char *s);
int	ft_lowhex(unsigned int n);
int	ft_uphex(unsigned int n);
int	ft_unsitoa(unsigned int n);
int	ft_pointer(unsigned long long n);
int	ft_printf(const char *format, ...);

#endif
