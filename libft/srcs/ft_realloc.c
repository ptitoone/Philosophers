/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@42nice.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:32:04 by akotzky           #+#    #+#             */
/*   Updated: 2021/08/31 16:06:20 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*dst;

	dst = NULL;
	if (size > 0 && ptr)
	{
		dst = malloc(size);
		if (!dst)
			return (dst);
		ft_memcpy(dst, ptr, size);
		if (ptr)
			free(ptr);
	}
	return (dst);
}
