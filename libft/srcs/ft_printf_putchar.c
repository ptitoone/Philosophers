/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:32:57 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:32:57 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putchar_pf(char c, int fd, t_conv *cv)
{
	char	ch;

	ch = c;
	if (write(fd, &ch, 1))
		cv->count++;
}
