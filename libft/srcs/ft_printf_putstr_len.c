/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr_len.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:32:58 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:32:58 by akotzky          ###   ########.fr       */
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
