/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:18:28 by jpillet           #+#    #+#             */
/*   Updated: 2021/09/06 15:05:35 by jpillet          ###   ########.fr       */
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
