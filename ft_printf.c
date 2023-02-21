#include "ft_printf.h"

int	ft_printarg(va_list print, int out, char a)
{
    int	i;

	i = 0;
    if(a == 'd' || a == 'i')
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

int ft_printf(const char *format, ...)
{
	int	i;
	int out;

	i = 0;
	out = 0;
	va_list print;
	va_start(print, format);
	while (format[i])
	{
		if(format[i] != '%')
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
/*
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
	//printf("\n%i\n", ft_printf("Hello%p", p));
	//printf("\n%i\n", printf("Hello%p", p));
	ft_printf("s:%s d:%d c:%c i:%i x:%x X:%X %%:%% u:%u p:%p\n", a, b, c, d, e, e, u, p);
	printf("s:%s d:%d c:%c i:%i x:%x X:%X %%:%% u:%u p:%p\n", a, b, c, d, e, e, u, p);
	//printf("%x\n", d);
	return (0);
}
*/