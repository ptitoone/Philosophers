/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:33:14 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:33:14 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long int	octet;

	octet = ft_strlen(s);
	while (s[octet] != (char)c && octet > -1)
		octet--;
	if (s[octet] == (char)c && octet > -1)
		return ((char *)s + octet);
	return (0);
}
