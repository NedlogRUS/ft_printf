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
	unsigned long long    i;
	int	j;
	char            *out;

	i = ft_sizepointer(n) + 2;
	out = (char *)malloc(sizeof(char) * (i + 3));
	if (!out)
		return (0);
	if (n == 0)
	{
		return (ft_string("0x0"));
	}
	out[i] = '\0';
	while (n != 0)
	{
		out[--i] = (char)((n % 16) + '0');
        if(out[i] >= ':' && out[i] <= '?')
        out[i] += 39;
        n = n / 16;
	}
    out[--i] = 'x';
    out[--i] = '0';
	j = ft_string(out);
	return (j);
}