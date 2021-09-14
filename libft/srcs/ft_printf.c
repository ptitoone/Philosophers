/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:23:33 by akotzky           #+#    #+#             */
/*   Updated: 2021/08/28 21:02:31 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	alist;
	t_conv	c;

	c.i = 0;
	c.j = 0;
	c.count = 0;
	va_start(alist, fmt);
	while (fmt[c.i] != 0)
	{
		if (fmt[c.i] == '%' && ft_check(fmt[c.i + 1]))
		{
			if (!ft_parse_conv(fmt, &c))
				continue ;
			ft_handle_conv(&c, &alist);
		}
		else if (fmt[c.i] == '%' && fmt[c.i + 1] == '%')
			ft_putchar_pf(fmt[c.i++], 1, &c);
		else
			ft_putchar_pf(fmt[c.i], 1, &c);
		c.i++;
	}
	va_end(alist);
	return (c.count);
}
