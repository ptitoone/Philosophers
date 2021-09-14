/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:53:02 by akotzky           #+#    #+#             */
/*   Updated: 2021/08/28 21:02:31 by jpillet          ###   ########.fr       */
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
