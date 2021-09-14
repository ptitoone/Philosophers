/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:18:51 by jpillet           #+#    #+#             */
/*   Updated: 2021/09/02 18:11:12 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned long int	len;
	char				*strdup;

	len = ft_strlen(s1);
	if (!ft_malloc_char((len + 1), &strdup))
		return (0);
	strdup[len] = '\0';
	while (len--)
		(strdup[len] = s1[len]);
	return (strdup);
}
