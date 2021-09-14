/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr_len.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:53:14 by akotzky           #+#    #+#             */
/*   Updated: 2021/08/28 21:02:31 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putstr_len(const char *s, size_t len, t_conv *cv)
{
	unsigned long	i;

	i = 0;
	if (s)
		while (i < len)
			if (write(1, &s[i++], 1))
				cv->count++;
}
