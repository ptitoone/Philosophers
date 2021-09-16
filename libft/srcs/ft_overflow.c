/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overflow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:31:38 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 22:20:37 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

t_ribool	ft_int_overflow(const char *src)
{
	int		num;
	char	*itoa;
	int		ret_val;

	num = ft_atoi(src);
	itoa = ft_itoa(num);
	ret_val = ft_strcmp(src, itoa);
	free(itoa);
	if (!ret_val)
		return (T_FALSE);
	return (T_TRUE);
}
