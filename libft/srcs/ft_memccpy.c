/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:32:43 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:32:43 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*sour;
	unsigned char	*dest;

	i = -1;
	sour = (unsigned char *)src;
	dest = (unsigned char *)dst;
	while (++i < n)
	{
		dest[i] = sour[i];
		if (sour[i] == (unsigned char)c)
			return (dest + i + 1);
	}
	return (0);
}
