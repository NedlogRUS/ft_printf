#include "ft_printf.h"

static unsigned int	ft_size(unsigned int n)
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

int	ft_unsitoa(unsigned int n)
{
	unsigned int		i;
	int	j;
	char	*out;

	i = ft_size(n);
	out = (char *)malloc(sizeof(char) * (i + 1));
	if (!out)
		return (0);
	if (n == 0)
	{
		return (ft_string("0"));
	}
	out[i] = '\0';
	while (n != 0)
	{
		out[--i] = (char)((n % 10) + '0');
		n = n / 10;
	}
	j = ft_string(out);
	return (j);
}

static unsigned int	ft_sizehex(unsigned int n)
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

int	ft_uphex(unsigned int n)
{
	unsigned int    i;
	int	j;
	char            *out;

	i = ft_sizehex(n);
	out = (char *)malloc(sizeof(char) * (i + 1));
	if (!out)
		return (0);
	if (n == 0)
	{
		return (ft_string("0"));
	}
	out[i] = '\0';
	while (n != 0)
	{
		out[--i] = (char)((n % 16) + '0');
        if(out[i] >= ':' && out[i] <= '?')
        out[i] += 7;
        n = n / 16;
	}
	j = ft_string(out);
	return (j);
}

int	ft_lowhex(unsigned int n)
{
	unsigned int    i;
	int	j;
	char            *out;

	i = ft_sizehex(n);
	out = (char *)malloc(sizeof(char) * (i + 1));
	if (!out)
		return (0);
	if (n == 0)
	{
		return (ft_string("0"));
	}
	out[i] = '\0';
	while (n != 0)
	{
		out[--i] = (char)((n % 16) + '0');
        if(out[i] >= ':' && out[i] <= '?')
        out[i] += 39;
        n = n / 16;
	}
	j = ft_string(out);
	return (j);
}