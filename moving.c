/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:30:12 by oumondad          #+#    #+#             */
/*   Updated: 2024/02/18 19:10:23 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_moving(int keycode, t_var *data)
{
	if (keycode == LEFT_KEY || keycode == A_KEY)
		left_move(data);
	else if (keycode == RIGHT_KEY || keycode == D_KEY)
		right_move(data);
	else if (keycode == UP_KEY || keycode == W_KEY)
		up_move(data);
	else if (keycode == DOWN_KEY || keycode == S_KEY)
		down_move(data);
	else if (keycode == 53)
		ft_win("Exit !\n", data);
	if (data->salta3_count == 0)
		ft_check_open_door(data);
	return (0);
}

void	left_move(t_var *data)
{
	if ((data->map[data->gps_y][data->gps_x - 1] != '1'
		&& data->map[data->gps_y][data->gps_x - 1] != 'E')
		|| (data->map[data->gps_y][data->gps_x - 1] != '1'
		&& data->salta3_count == 0))
	{
		ft_player_mv();
		if (data->map[data->gps_y][data->gps_x - 1] == 'E')
			ft_win("\nYou Win\n", data);
		mlx_put_image_to_window(data->mlx, data->mlx_window,
			data->bground, data->gps_x * 50, data->gps_y * 50);
		mlx_put_image_to_window(data->mlx, data->mlx_window,
			data->left, (data->gps_x - 1) * 50, data->gps_y * 50);
		data->gps_x--;
		if (data->map[data->gps_y][data->gps_x] == 'C')
		{
			data->map[data->gps_y][data->gps_x] = '0';
			data->salta3_count--;
		}
	}
	return ;
}

void	right_move(t_var *data)
{
	if ((data->map[data->gps_y][data->gps_x + 1] != '1'
		&& data->map[data->gps_y][data->gps_x + 1] != 'E')
			|| (data->map[data->gps_y][data->gps_x + 1] != '1'
				&& data->salta3_count == 0))
	{
		ft_player_mv();
		if (data->map[data->gps_y][data->gps_x + 1] == 'E')
			ft_win("\nYou Win\n", data);
		mlx_put_image_to_window(data->mlx, data->mlx_window,
			data->bground, data->gps_x * 50, data->gps_y * 50);
		mlx_put_image_to_window(data->mlx, data->mlx_window,
			data->right, (data->gps_x + 1) * 50, data->gps_y * 50);
		if (data->map[data->gps_y][data->gps_x + 1] == 'C')
		{
			data->map[data->gps_y][data->gps_x + 1] = '0';
			data->salta3_count--;
		}
		data->gps_x++;
	}
	return ;
}

void	up_move(t_var *data)
{
	if ((data->map[data->gps_y - 1][data->gps_x] != '1'
		&& data->map[data->gps_y - 1][data->gps_x] != 'E')
			|| (data->map[data->gps_y - 1][data->gps_x] != '1'
				&& data->salta3_count == 0))
	{
		ft_player_mv();
		mlx_put_image_to_window(data->mlx, data->mlx_window,
			data->bground, data->gps_x * 50, data->gps_y * 50);
		mlx_put_image_to_window(data->mlx, data->mlx_window,
			data->back, data->gps_x * 50, (data->gps_y - 1) * 50);
		if (data->map[data->gps_y - 1][data->gps_x] == 'E')
			ft_win("\nYou Win\n", data);
		data->gps_y--;
		if (data->map[data->gps_y][data->gps_x] == 'C')
		{
			data->map[data->gps_y][data->gps_x] = '0';
			data->salta3_count--;
		}
	}
	return ;
}

void	down_move(t_var *data)
{
	if ((data->map[data->gps_y + 1][data->gps_x] != '1'
		&& data->map[data->gps_y + 1][data->gps_x] != 'E')
			|| (data->map[data->gps_y + 1][data->gps_x] != '1'
				&& data->salta3_count == 0))
	{
		ft_player_mv();
		mlx_put_image_to_window(data->mlx, data->mlx_window,
			data->bground, data->gps_x * 50, data->gps_y * 50);
		mlx_put_image_to_window(data->mlx, data->mlx_window,
			data->sponge, data->gps_x * 50, (data->gps_y + 1) * 50);
		if (data->map[data->gps_y + 1][data->gps_x] == 'E')
			ft_win("\nYou Win\n", data);
		if (data->map[data->gps_y + 1][data->gps_x] == 'C')
		{
			data->map[data->gps_y + 1][data->gps_x] = '0';
			data->salta3_count--;
		}
		data->gps_y++;
	}
	return ;
}
