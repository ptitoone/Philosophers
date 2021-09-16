/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_has_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:32:52 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:32:52 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_has_precision(const char *conv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = NULL;
	while (conv[i])
	{
		if (conv[i] == '.'
			&& ((conv[i + 1] >= '1' && conv[i + 1] <= '9')
				|| conv[i + 1] == '-'))
		{
			j++;
			i++;
			while (ft_isdigit(conv[i + j]))
				j++;
			tmp = ft_substr(conv, i, j);
			i = ft_atoi(tmp);
			free(tmp);
			return (i);
		}
		i++;
	}
	return (0);
}
