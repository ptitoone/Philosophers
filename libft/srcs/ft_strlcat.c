/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:33:10 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:33:10 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	catinc;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= dstsize)
		return (srclen + dstsize);
	catinc = 0;
	while ((dstlen + catinc) < dstsize - 1 && src[catinc] != '\0')
	{
		dst[dstlen + catinc] = src[catinc];
		catinc++;
	}
	dst[dstlen + catinc] = '\0';
	return (dstlen + srclen);
}
