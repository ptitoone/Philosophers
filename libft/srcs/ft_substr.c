/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:33:15 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:33:15 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	strlen;

	if (!s)
		return (0);
	strlen = ft_strlen(s);
	if (start >= strlen)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	else
	{
		if (len < (strlen - start))
			strlen = (len + start);
		str = (char *)malloc(((strlen - start) + 1) * sizeof(char));
		if (!str)
			return (0);
		ft_strlcpy(str, (s + start), ((strlen - start) + 1));
	}
	return (str);
}
