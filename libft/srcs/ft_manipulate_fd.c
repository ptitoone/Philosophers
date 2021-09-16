/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manipulate_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:32:41 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 14:10:00 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_ribool	ft_close_fd(int *fd)
{
	if (*fd > 2)
		close(*fd);
	*fd = -2;
	return (T_FALSE);
}

t_ribool	ft_unlink_file(char *file)
{
	if (file && !(access(file, F_OK)))
		unlink(file);
	return (T_FALSE);
}
