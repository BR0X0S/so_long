/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_count_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:25:50 by oumondad          #+#    #+#             */
/*   Updated: 2024/02/20 16:50:08 by oumondad         ###   ########.fr       */
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

void	init_img_bonus(t_var *data)
{
	data->enemy = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy.xpm", &data->width, &data->height);
	if (!data->enemy)
		ft_error("Error : enemy faild");
	data->enemy2 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy2.xpm", &data->width, &data->height);
	if (!data->enemy2)
		ft_error("Error : enemy2 faild");
	data->enemy3 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy3.xpm", &data->width, &data->height);
	if (!data->enemy3)
		ft_error("Error : enemy3 faild");
	data->enemy4 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy4.xpm", &data->width, &data->height);
	if (!data->enemy4)
		ft_error("Error : enemy4 faild");
}

int	animation(t_var *data)
{
	static int	i;
	int			x;
	int			y;

	y = 0;
	i++;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'M')
				frames(data, x, y, i);
			x++;
		}
		y++;
	}
	if (i > 6500)
		i = 0;
	return (0);
}

void	frames(t_var *data, int x, int y, int i)
{
	if (i == 1500)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_window,
			data->bground, x * 50, y * 50);
		mlx_put_image_to_window(data->mlx, data->mlx_window,
			data->enemy2, x * 50, y * 50);
	}
	if (i == 3000)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_window,
			data->bground, x * 50, y * 50);
		mlx_put_image_to_window(data->mlx, data->mlx_window,
			data->enemy3, x * 50, y * 50);
	}
	frames2(data, x, y, i);
}

void	frames2(t_var *data, int x, int y, int i)
{
	if (i == 4500)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_window,
			data->bground, x * 50, y * 50);
		mlx_put_image_to_window(data->mlx, data->mlx_window,
			data->enemy4, x * 50, y * 50);
	}
	if (i == 6000)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_window,
			data->bground, x * 50, y * 50);
		mlx_put_image_to_window(data->mlx, data->mlx_window,
			data->enemy, x * 50, y * 50);
	}
}
