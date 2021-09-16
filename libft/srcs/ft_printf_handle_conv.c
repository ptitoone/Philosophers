/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_conv.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:32:50 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:32:50 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_handle_conv(t_conv *c, va_list *alist)
{
	int		type;
	int		(*fnc[10])(t_conv *, va_list	*);

	fnc[0] = &ft_c;
	fnc[1] = &ft_s;
	fnc[2] = &ft_p;
	fnc[3] = &ft_i;
	fnc[4] = &ft_i;
	fnc[5] = &ft_u;
	fnc[8] = &ft_x;
	fnc[9] = &ft_ux;
	type = ft_get_conv_type(c->conv);
	if (ft_has_asterisk(c->conv))
		ft_replace_asterisk(&c->conv, alist);
	fnc[type](c, alist);
	free(c->conv);
	c->conv = NULL;
	return (0);
}
