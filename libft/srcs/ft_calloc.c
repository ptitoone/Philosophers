/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:32:24 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:32:24 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_ribool	ft_calloc(size_t count, size_t size, void *ptr)
{
	void	*newcal;

	newcal = malloc(count * size);
	if (!(newcal))
		return (T_FALSE);
	ft_bzero(ptr, size);
	return (T_TRUE);
}
