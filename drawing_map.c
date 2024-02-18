/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:53:35 by oumondad          #+#    #+#             */
/*   Updated: 2024/02/13 13:44:18 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_image(t_var *data)
{
	data -> wall = mlx_xpm_file_to_image(data->mlx,
			"./textures/wall.xpm", &data -> width, &data -> height);
	if (!data -> wall)
		ft_error("Error : wall faild");
	data -> bground = mlx_xpm_file_to_image(data->mlx,
			"./textures/bground.xpm", &data -> width, &data -> height);
	if (!data -> bground)
		ft_error("Error : bg faild");
	data -> salta3_birgar = mlx_xpm_file_to_image(data->mlx,
			"./textures/coin.xpm", &data -> width, &data -> height);
	if (!data->salta3_birgar)
		ft_error("Error : salta3 birgar filed");
	data -> door_c = mlx_xpm_file_to_image(data->mlx,
			"./textures/door_close.xpm", &data -> width, &data -> height);
	if (!data->door_c)
		ft_error("Error : door faild");
	initialize_image_2(data);
}

void	initialize_image_2(t_var *data)
{
	data -> sponge = mlx_xpm_file_to_image(data->mlx,
			"./textures/sponge.xpm", &data -> width, &data -> height);
	if (!data->sponge)
		ft_error("Error : sponge faild");
	data->back = mlx_xpm_file_to_image(data->mlx,
			"./textures/back.xpm", &data -> width, &data -> height);
	if (!data->back)
		ft_error("Error : sponge back faild");
	data->left = mlx_xpm_file_to_image(data->mlx,
			"./textures/left.xpm", &data -> width, &data -> height);
	if (!data->left)
		ft_error("Error : sponge left faild");
	data->right = mlx_xpm_file_to_image(data->mlx,
			"./textures/right.xpm", &data -> width, &data -> height);
	if (!data->right)
		ft_error("Error : sponge right faild");
	data->door_o = mlx_xpm_file_to_image(data->mlx,
			"./textures/door_o.xpm", &data -> width, &data -> height);
	if (!data->door_o)
		ft_error("Error : door faild");
}

void	put_image(t_var data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data.x)
	{
		x = 0;
		put_image_v2(data, x, y);
		y++;
	}
}

void	put_image_v2(t_var data, int x, int y)
{
	while (data.map[y][x])
	{
		if (data.map[y][x] == '1')
			mlx_put_image_to_window(data.mlx, data.mlx_window,
				data.wall, x * 50, y * 50);
		if (data.map[y][x] == '0' || data.map[y][x] == 'C'
			|| data.map[y][x] == 'P' || data.map[y][x] == 'E')
			mlx_put_image_to_window(data.mlx, data.mlx_window,
				data.bground, x * 50, y * 50);
		if (data.map[y][x] == 'C')
			mlx_put_image_to_window(data.mlx, data.mlx_window,
				data.salta3_birgar, x * 50, y * 50);
		if (data.map[y][x] == 'E')
			mlx_put_image_to_window(data.mlx, data.mlx_window,
				data.door_c, x * 50, y * 50);
		if (data.map[y][x] == 'P')
			mlx_put_image_to_window(data.mlx, data.mlx_window,
				data.sponge, x * 50, y * 50);
		x++;
	}
}

void	ft_check_open_door(t_var *data)
{
	t_gps	pose;

	pose = ft_find_player(*data, 'E');
	mlx_put_image_to_window(data->mlx, data->mlx_window,
		data->bground, (pose.x) * 50, (pose.y) * 50);
	mlx_put_image_to_window(data->mlx, data->mlx_window,
		data->door_o, (pose.x) * 50, (pose.y) * 50);
}
