/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pad_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:52:37 by akotzky           #+#    #+#             */
/*   Updated: 2021/08/28 21:02:31 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_pad_space(int len, t_conv *cv)
{
	while (len-- > 0)
		if (write(1, " ", 1))
			cv->count++;
	return (len);
}
