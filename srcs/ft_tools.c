/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:51:35 by akotzky           #+#    #+#             */
/*   Updated: 2021/10/26 17:40:07 by akotzky          ###   ########.fr       */
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

static void	ft_ltoa_init(long n, long *clclen, int *strlen, int *posinega)
{
	*clclen = n;
	*posinega = 1;
	*strlen = 2;
	if (n < 0)
		*posinega = -1;
	if (n < 0)
		*strlen = 3;
}

char	*ft_ltoa(long n)
{
	char	*nbrstr;
	long	clclen;
	int		strlen;
	int		posinega;

	ft_ltoa_init(n, &clclen, &strlen, &posinega);
	clclen /= 10;
	while (clclen)
	{
		clclen /= 10;
		strlen++;
	}
	nbrstr = (char *)malloc(strlen * sizeof(char));
	if (!nbrstr)
		return (0);
	nbrstr[--strlen] = '\0';
	while ((posinega < 0 && --strlen > 0) || (posinega > 0 && --strlen > -1))
	{
		nbrstr[strlen] = (((n % 10) * posinega) + '0');
		n /= 10;
	}
	nbrstr[0] = nbrstr[0];
	if (posinega < 0)
		nbrstr[0] = '-';
	return (nbrstr);
}

long int	ft_atol(const char *str)
{
	int			strind;
	int			posinega;
	long int	result;

	strind = 0;
	posinega = 1;
	while (str[strind] == ' ' || (str[strind] >= 9 && str[strind] <= 13))
		strind++;
	if (str[strind] == '-')
		posinega = -1;
	if (!(str[strind] == '-') && !(str[strind] == '+'))
		strind--;
	result = 0;
	while (str[++strind] >= '0' && str[strind] <= '9')
		result = (result * 10) + ((str[strind] - '0') * posinega);
	return (result);
}
