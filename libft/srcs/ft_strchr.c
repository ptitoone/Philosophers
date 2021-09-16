/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:33:05 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:33:05 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	octet;

	octet = -1;
	while (s[++octet] || (char)c == '\0')
		if (s[octet] == (char)c)
			return ((char *)s + octet);
	return (0);
}
