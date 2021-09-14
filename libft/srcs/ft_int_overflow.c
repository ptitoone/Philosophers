/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_overflow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:31:38 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/14 19:33:06 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ribool	ft_int_overflow(const char *src)
{
	long long	num;
	char 		*itoa;
	int			ret_val;

	num = ft_atol(src);
	itoa = ft_itoa(num);
	ret_val = ft_strcmp(src, itoa);
	free(itoa);
	if (!ret_val)
		return (T_FALSE);
	return (T_TRUE);
}
