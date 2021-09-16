/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_conv.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:32:56 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:32:56 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_parse_conv(const char *fmt, t_conv *c)
{
	c->j++;
	while (fmt[c->i + c->j])
	{
		if (ft_is_spec(fmt[c->i + c->j]))
			break ;
		else if (fmt[c->i + c->j] == '%' || !ft_check(fmt[c->i + 1]))
		{
			ft_putstr_len(&fmt[c->i], c->j, c);
			c->i += c->j;
			c->j = 0;
			return (0);
		}
		c->j++;
	}
	c->conv = ft_substr(fmt, c->i, c->j + 1);
	c->i += c->j;
	c->j = 0;
	return (1);
}
