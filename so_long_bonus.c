/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:05:29 by oumondad          #+#    #+#             */
/*   Updated: 2024/02/20 16:50:23 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	open_window(t_var *data)
{
	data -> mlx_window = mlx_new_window(data->mlx,
			(data->len_x * 50), (data->len_y * 50), "Broxos");
	if (!data->mlx_window)
		ft_error("Error : window faild");
}

int	main(int ac, char **av)
{
	t_var	*data;

	if (ac == 2)
	{
		data = malloc(sizeof(t_var));
		if (!data)
			ft_error("Error : struct faild");
		*data = ft_check_map(av);
		data -> mlx = mlx_init();
		if (!data -> mlx)
			ft_error("Error : mlx faild");
		initialize_image(data);
		open_window(data);
		put_image(*data);
		mlx_string_put(data->mlx, data->mlx_window, 5, 15, 0xFFFFFF, "0");
		mlx_loop_hook(data->mlx, animation, data);
		mlx_hook(data->mlx_window, 2, 0, ft_moving, data);
		mlx_hook(data->mlx_window, 17, 0, ft_errors, data);
		mlx_loop(data->mlx);
	}
	if (ac >= 3)
		ft_error("Error : wa 3aye9ti");
	ft_error("Error : zid lmap");
}
