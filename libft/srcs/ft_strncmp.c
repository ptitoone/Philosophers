/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:33:13 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:33:13 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			chrind;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	chrind = 0;
	while (chrind < n && (str1[chrind] || str2[chrind]))
	{
		if (str1[chrind] != str2[chrind])
			return (str1[chrind] - str2[chrind]);
		chrind++;
	}
	return (0);
}
