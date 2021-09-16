/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:33:04 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:33:04 by akotzky          ###   ########.fr       */
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
