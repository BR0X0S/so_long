/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:05:29 by oumondad          #+#    #+#             */
/*   Updated: 2024/02/15 16:39:16 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_var	*data;

	if (ac == 2)
	{
		data = malloc(sizeof(t_var));
		if (!data)
			ft_error("Error : struct faild");
		*data = ft_check_map(av);
		if (data->len_x > 51 || data->len_y > 28)
			ft_error("Error : map resolution error !\n");
		data -> mlx = mlx_init();
		initialize_image(data);
		data -> mlx_window = mlx_new_window(data->mlx,
				(data -> len_x * 50), (data -> len_y * 50), "Broxos");
		if (!data -> mlx_window)
			ft_error("Error : window faild");
		put_image(*data);
		mlx_hook(data->mlx_window, 2, 0, ft_moving, data);
		mlx_hook(data->mlx_window, 17, 0, ft_errors, data);
		mlx_loop(data->mlx);
	}
	if (ac >= 3)
		ft_error("Error : wa 3aye9ti");
	ft_error("Error : zid lmap");
}
