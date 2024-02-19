/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_count_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:25:50 by oumondad          #+#    #+#             */
/*   Updated: 2024/02/19 19:31:36 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_player_mv(t_var *data)
{
	static int	i = 1;

	data->str_mv = ft_itoa(i);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->wall, 0, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->wall, 50, 0);
	mlx_string_put(data->mlx, data->mlx_window, 1, 15, 0xFFFFFF, data->str_mv);
	free(data->str_mv);
	i++;
}
