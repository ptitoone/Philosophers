/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:43:02 by jpillet           #+#    #+#             */
/*   Updated: 2021/08/25 22:45:48 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*sour;
	unsigned char	*dest;

	sour = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (dest > sour)
		while (len--)
			*(dest + len) = *(sour + len);
	else if (dest < sour)
		while (len--)
			*dest++ = *sour++;
	return (dst);
}
