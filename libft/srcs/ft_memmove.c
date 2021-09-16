/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:32:46 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:32:46 by akotzky          ###   ########.fr       */
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
