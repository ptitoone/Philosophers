/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_conv_type.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:49:15 by akotzky           #+#    #+#             */
/*   Updated: 2021/08/28 21:02:51 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_get_conv_type(const char *conv)
{
	while (*conv)
		conv++;
	if (*(conv - 1) == 'c')
		return (0);
	if (*(conv - 1) == 's')
		return (1);
	if (*(conv - 1) == 'p')
		return (2);
	if (*(conv - 1) == 'd')
		return (3);
	if (*(conv - 1) == 'i')
		return (4);
	if (*(conv - 1) == 'u')
		return (5);
	if (*(conv - 1) == 'c')
		return (6);
	if (*(conv - 1) == 'x')
		return (8);
	if (*(conv - 1) == 'X')
		return (9);
	return (-1);
}
