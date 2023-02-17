#include "libft.h"
#include "libftprintf.h"

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

char	*ft_zero(char *out)
{
	out[0] = '0';
	out[1] = '\0';
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