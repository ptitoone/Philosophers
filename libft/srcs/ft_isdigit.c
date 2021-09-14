/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:40:48 by jpillet           #+#    #+#             */
/*   Updated: 2021/08/25 22:45:48 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

t_ribool	ft_strisdigit(char *str)
{
	int	index;

	index = -1;
	while (str[++index])
		if (!ft_isdigit(str[index]))
			return (T_FALSE);
	return (T_TRUE);
}

t_ribool	ft_strisnumber(char *str)
{
	if (str[0] == '-' || str[0] == '+')
		return (ft_strisdigit(str + 1));
	else
		return (ft_strisdigit(str));
}
