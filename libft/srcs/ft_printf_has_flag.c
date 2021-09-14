/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_has_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:51:01 by akotzky           #+#    #+#             */
/*   Updated: 2021/08/28 21:02:31 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_has_flag(const char *conv)
{
	while (*conv)
	{
		if (*conv == '-' && *(conv - 1) != '.')
			return ('-');
		if (*conv == '0' && *(conv + 1) != '-' && *(conv - 1) != '.'
			&& !((*(conv - 1) >= '1' && *(conv - 1) <= '9')))
			return ('0');
		conv++;
	}
	return (0);
}