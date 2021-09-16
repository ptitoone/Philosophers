/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:32:49 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:32:49 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static void	ft_has_tac(t_c_data *d, t_conv *c)
{
	ft_putchar_pf(d->nb, 1, c);
	if (d->width > 1)
		ft_pad_space(d->width - 1, c);
}

int	ft_c(t_conv *c, va_list *alist)
{
	t_c_data	d;

	d.nb = va_arg(*alist, int);
	d.width = ft_has_width(c->conv);
	if (ft_has_flag(c->conv) == '-')
		ft_has_tac(&d, c);
	else
	{
		if (d.width > 1)
			ft_pad_space(d.width - 1, c);
		ft_putchar_pf(d.nb, 1, c);
	}
	return (0);
}
