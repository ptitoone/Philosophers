/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:33:11 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:33:11 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_strlen(const char *s)
{
	int		len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

int	ft_strlen_2(const char **s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
