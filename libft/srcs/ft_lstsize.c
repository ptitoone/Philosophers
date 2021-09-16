/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:32:39 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:32:39 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*lstcpy;
	int		lstsize;

	lstcpy = lst;
	lstsize = 0;
	while (lstcpy)
	{
		lstcpy = lstcpy->next;
		lstsize++;
	}
	return (lstsize);
}
