/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:06:18 by jpillet           #+#    #+#             */
/*   Updated: 2021/08/25 22:45:48 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const void	*p1;
	const void	*p2;
	size_t		oct;

	p1 = s1;
	p2 = s2;
	oct = 0;
	while (oct < n)
	{
		if ((((unsigned char *)p1)[oct] - ((unsigned char *)p2)[oct]) != 0)
			return ((((unsigned char *)p1)[oct] - ((unsigned char *)p2)[oct]));
		oct++;
	}
	return (0);
}
