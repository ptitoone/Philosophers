/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:32:46 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:32:46 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	octet;

	octet = 0;
	if ((!dst && !src) && n)
		return (NULL);
	while (octet < n)
	{
		((unsigned char *)dst)[octet] = ((unsigned char *)src)[octet];
		octet++;
	}
	return (dst);
}
