/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:51:35 by akotzky           #+#    #+#             */
/*   Updated: 2021/11/01 17:36:44 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strcmp(char const *s1, char const *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

t_ribool	ft_long_overflow(const char *src)
{
	long	num;
	char	*ltoa;
	int		ret_val;

	num = ft_atol(src);
	ltoa = ft_ltoa(num);
	ret_val = ft_strcmp(src, ltoa);
	free(ltoa);
	if (!ret_val)
		return (T_FALSE);
	return (T_TRUE);
}

static void	ft_ltoa_init(long n, long *clclen, int *len, int *polarity)
{
	*clclen = n;
	*polarity = 1;
	*len = 2;
	if (n < 0)
		*polarity = -1;
	if (n < 0)
		*len = 3;
}

char	*ft_ltoa(long n)
{
	char	*str;
	long	clclen;
	int		len;
	int		polarity;

	ft_ltoa_init(n, &clclen, &len, &polarity);
	clclen /= 10;
	while (clclen)
	{
		clclen /= 10;
		len++;
	}
	str = (char *)malloc(len * sizeof(char));
	if (!str)
		return (0);
	str[--len] = '\0';
	while ((polarity < 0 && --len > 0) || (polarity > 0 && --len > -1))
	{
		str[len] = (((n % 10) * polarity) + '0');
		n /= 10;
	}
	str[0] = str[0];
	if (polarity < 0)
		str[0] = '-';
	return (str);
}

long int	ft_atol(const char *str)
{
	int			i;
	int			polarity;
	long int	ret_val;

	i = 0;
	polarity = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		polarity = -1;
	if (!(str[i] == '-') && !(str[i] == '+'))
		i--;
	ret_val = 0;
	while (str[++i] >= '0' && str[i] <= '9')
		ret_val = (ret_val * 10) + ((str[i] - '0') * polarity);
	return (ret_val);
}
