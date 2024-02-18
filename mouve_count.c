/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:25:50 by oumondad          #+#    #+#             */
/*   Updated: 2024/02/06 17:51:35 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write (1, "-", 1);
		nb *= 1;
		ft_putnbr(nb);
	}
	else if (nb >= 0 && nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_player_mv(void)
{
	static int	i = 1;

	write(1, "player moves = ", 16);
	ft_putnbr(i);
	write(1, "\n", 1);
	i++;
}
