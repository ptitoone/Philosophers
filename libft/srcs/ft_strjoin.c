/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:33:10 by akotzky           #+#    #+#             */
/*   Updated: 2021/09/16 13:33:10 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	strlen;
	size_t	strlen2;

	if (!s1 || !s2)
		return (0);
	strlen = ft_strlen(s1);
	strlen2 = ft_strlen(s2);
	strlen += strlen2;
	str = (char *)malloc((strlen + 1) * sizeof(char));
	if (!str)
		return (0);
	str[strlen] = '\0';
	while (strlen2)
		str[--strlen] = ((char *)s2)[--strlen2];
	while (strlen--)
		str[strlen] = ((char *)s1)[strlen];
	return (str);
}

t_ribool	ft_strjoin_all_malloc(int ac, char **av, char c, char **str)
{
	int		nb_str;
	int		ind_av;
	int		index;

	nb_str = 1;
	if (c)
		nb_str = ac;
	ind_av = -1;
	while (++ind_av < ac)
	{
		if (av[ind_av])
		{
			index = -1;
			while (av[ind_av][++index])
				nb_str++;
		}
		else
			nb_str--;
	}
	if (!ft_malloc_char(nb_str, str))
		return (T_FALSE);
	return (T_TRUE);
}

void	ft_strjoin_all_copy(int ac, char **av, char c, char **str)
{
	int		nb_str;
	int		ind_av;
	int		index;

	nb_str = 0;
	ind_av = -1;
	while (++ind_av < ac)
	{
		if (av[ind_av])
		{
			index = 0;
			while (av[ind_av][index])
				(*str)[nb_str++] = av[ind_av][index++];
			if (c)
				(*str)[nb_str++] = c;
		}
	}
	(*str)[--nb_str] = '\0';
}

t_ribool	ft_strjoin_all(int ac, char **av, char c, char **str)
{
	if (!(ft_strjoin_all_malloc(ac, av, c, str)))
		return (T_FALSE);
	ft_strjoin_all_copy(ac, av, c, str);
	return (T_TRUE);
}
