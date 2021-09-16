/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freellers_types.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:32:26 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:32:26 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_ribool	ft_free_char(char **ptr)
{
	if (!(*ptr))
		return (T_FALSE);
	free(*ptr);
	*ptr = 0;
	return (T_FALSE);
}

t_ribool	ft_free_int(int **ptr)
{
	if (!(*ptr))
		return (T_FALSE);
	free(*ptr);
	*ptr = 0;
	return (T_FALSE);
}

t_ribool	ft_free_float(float **ptr)
{
	if (!(*ptr))
		return (T_FALSE);
	free(*ptr);
	*ptr = 0;
	return (T_FALSE);
}

t_ribool	ft_free_double(double **ptr)
{
	if (!(*ptr))
		return (T_FALSE);
	free(*ptr);
	*ptr = 0;
	return (T_FALSE);
}

t_ribool	ft_free_t_ribool(t_ribool **ptr)
{
	if (!(*ptr))
		return (T_FALSE);
	free(*ptr);
	*ptr = 0;
	return (T_FALSE);
}
