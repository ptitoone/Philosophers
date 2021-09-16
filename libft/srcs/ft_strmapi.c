/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:33:12 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:33:12 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*str;
	const char	*slen;
	size_t		strind;

	if (!s || !f)
		return (0);
	slen = (const char *)s;
	strind = ft_strlen(slen);
	str = (char *)malloc((strind + 1) * sizeof(char));
	if (!str)
		return (0);
	strind = -1;
	while (s[++strind])
		str[strind] = f(strind, s[strind]);
	str[strind] = '\0';
	return (str);
}
