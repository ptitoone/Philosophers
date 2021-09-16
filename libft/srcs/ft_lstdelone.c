/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:32:36 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:32:36 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*noddel;

	if (lst && del)
	{
		noddel = lst;
		lst = lst->next;
		del(noddel->content);
		free(noddel);
	}
}
