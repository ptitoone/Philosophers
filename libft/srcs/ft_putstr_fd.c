/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:28:52 by jpillet           #+#    #+#             */
/*   Updated: 2021/08/25 22:45:48 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned long int	strind;

	strind = 0;
	while (s && s[strind])
		ft_putchar_fd(s[strind++], fd);
}
