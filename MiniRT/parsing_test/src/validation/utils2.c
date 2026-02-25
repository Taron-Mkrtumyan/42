#include "minirt.h"

int	is_ulong(char *str)
{
	unsigned long	res;
	unsigned long	limit;
	int				i;

	if (!str || !str[0])
		return (0);
	i = 0;
	res = 0;
	limit = ULONG_MAX / 10;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		if (res > limit || (res == limit && \
			(unsigned long)(str[i] - '0') > ULONG_MAX % 10))
			return (0);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (1);
}

float	str_to_float(char *str)
{
	float	sum;
	float	prec;
	float	div;
	float	sign;

	prec = 0.0;
	div = 1.0;
	sign = 1.0;
	if (str && str[0] == '-')
		sign *= -1.0;
	sum = (float)ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (*str++ == '.')
	{
		while (*str >= '0' && *str <= '9')
		{
			div *= 10.0;
			prec += (*str - '0') / div;
			str++;
		}
		sum += prec * sign;
	}
	return (sum);
}

int	check_float_digits(char *str, int i)
{
	int	dot;
	int	digit_before;
	int	digit_after;

	dot = 0;
	digit_before = 0;
	digit_after = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			if (!dot)
				digit_before++;
			else
				digit_after++;
		}
		else if (str[i] == '.' && !dot)
			dot = 1;
		else
			return (0);
		i++;
	}
	if (dot)
		return (digit_before > 0 && digit_after > 0);
	return (digit_before > 0);
}

int	is_float(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	return (check_float_digits(str, i));
}

int	array_length(char *arr[])
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}
