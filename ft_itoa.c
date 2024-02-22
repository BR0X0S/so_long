/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:01:04 by oumondad          #+#    #+#             */
/*   Updated: 2024/02/21 15:42:11 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	nb_len(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	char	*s_nb;
	int		len;

	len = nb_len(nb);
	s_nb = malloc (len + 1);
	if (!s_nb)
		ft_error("Error : itoa allocation faild");
	if (nb == 0)
		s_nb[0] = '0';
	if (nb < 0)
	{
		s_nb[0] = '-';
		nb *= -1;
	}
	s_nb[len] = '\0';
	while (len)
	{
		len--;
		s_nb[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (s_nb);
}
