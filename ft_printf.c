#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

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

unsigned int	ft_size(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_zero(char *out)
{
	out[0] = '0';
	out[1] = '\0';
	return (out);
} 

char	*ft_unsitoa(unsigned int n)
{
	unsigned int		i;
	char	*out;

	i = ft_size(n);
	out = (char *)malloc(sizeof(char) * (i + 1));
	if (!out)
		return (out);
	if (n == 0)
		return (out = ft_zero(out));
	out[i] = '\0';
	while (n != 0)
	{
		out[--i] = (char)((n % 10) + '0');
		n = n / 10;
	}
	return (out);
}

unsigned int	ft_sizehex(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_lowhex(unsigned int n)
{
	unsigned int    i;
	char            *out;

	i = ft_sizehex(n);
	out = (char *)malloc(sizeof(char) * (i + 1));
	if (!out)
		return (out);
	if (n == 0)
		return (out = ft_zero(out));
	out[i] = '\0';
	while (n != 0)
	{
		out[--i] = (char)((n % 16) + '0');
        if(out[i] >= ':' && out[i] <= '?')
        out[i] += 39;
        n = n / 16;
	}
	return (out);
}

char	*ft_uphex(unsigned int n)
{
	unsigned int    i;
	char            *out;

	i = ft_sizehex(n);
	out = (char *)malloc(sizeof(char) * (i + 1));
	if (!out)
		return (out);
	if (n == 0)
		return (out = ft_zero(out));
	out[i] = '\0';
	while (n != 0)
	{
		out[--i] = (char)((n % 16) + '0');
        if(out[i] >= ':' && out[i] <= '?')
        out[i] += 7;
        n = n / 16;
	}
	return (out);
}

char	*ft_pointer(unsigned long long n)
{
	unsigned long long    i;
	char            *out;

	i = ft_sizepointer(n);
	out = (char *)malloc(sizeof(char) * (i + 1));
	if (!out)
		return (out);
	if (n == 0)
		return (out = ft_zero(out));
	out[i] = '\0';
	while (n != 0)
	{
		out[--i] = (char)((n % 16) + '0');
        if(out[i] >= ':' && out[i] <= '?')
        out[i] += 39;
        n = n / 16;
	}
	return (out);
}

char	*ft_strcharjoin(char const *s1, char s2)
{
	char	*res;
	int		a;

	a = 0;
	if (!s1 || !s2)
		return ((char *)malloc(sizeof(char)));
	res = (char *)malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!res)
		return ((void *)0);
	while (s1[a])
	{
		res[a] = s1[a];
		a++;
	}
	res[a] = s2;
	a++;
	res[a] = '\0';
	return (res);
}

int ft_printf(const char *format, ...)
{
	char *out = "";
	unsigned int	j;
	unsigned long long p;
	int				i;
	char			*a;
	int				b;
	char			c;

	i = 0;
	va_list print;
	va_start(print, format);
	while (format[i])
	{
		if(format[i] != '%')
		{
			out = ft_strcharjoin(out, format[i]);
			//write(1, &format[i], 1);
			i++;
		}
		else if (format[i] == '%')
		{
			i++;
			if(format[i] == 'c')
			{
				c = va_arg(print, int);
				ft_putchar_fd(c, 1);
				i++;
			}
			if(format[i] == 's')
			{
				a = va_arg(print, char *);
				ft_putstr_fd(a, 1);
				i++;
			}
			if(format[i] == 'd')
			{
				b = va_arg(print, int);
				ft_putnbr_fd(b, 1);
				i++;
			}
			if(format[i] == 'i')
			{
				b = va_arg(print, int);
				ft_putnbr_fd(b, 1);
				i++;
			}
			if(format[i] == 'x')
			{
				j = va_arg(print, unsigned int);
				a = ft_lowhex(j);
				fprintf(stdout, "%s", a);
				i++;
			}
			if(format[i] == 'X')
			{
				j = va_arg(print, unsigned int);
				a = ft_uphex(j);
				fprintf(stdout, "%s", a);
				i++;
			}
			if(format[i] == '%')
			{
				c = '%';
				write(1, &c, 1);
				i++;
			}
			if(format[i] == 'u')
			{
				j = va_arg(print, unsigned int);
				a = ft_unsitoa(j);
				fprintf(stdout, "%s", a);
				i++;
			}
			if(format[i] == 'p')
			{
				p = va_arg(print, unsigned long long);
				a = "0x";
				out = ft_strjoin(out, a);
				a = ft_pointer(p);
				out = ft_strjoin(out, a);
				//fprintf(stdout, "0x%s", a);
				i++;
			}
		}
	}
	va_end(print);
	ft_putstr_fd(out, 1);
	return (ft_strlen(out));
}

int main(void)
{
	setvbuf(stdout, 0, _IONBF, 0);
	char	*a = "StrInG";
	int		b = -42;
	char	c = 'C';
	int		d = 42; 
	int		e = 0xabcdef42;
	unsigned int u = 4294967295;
	char	*p = "42";
	printf("\n%i\n", ft_printf("Hello%p", p));
	printf("\n%i\n", printf("Hello%p", p));
	//ft_printf("s:%s d:%d c:%c i:%i x:%x X:%X %%:%% u:%u p:%p\n", a, b, c, d, e, e, u, p);
	//printf("s:%s d:%d c:%c i:%i x:%x X:%X %%:%% u:%u p:%p\n", a, b, c, d, e, e, u, p);
	//printf("%x\n", d);
	return (0);
}