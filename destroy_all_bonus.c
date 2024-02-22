/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:06:59 by oumondad          #+#    #+#             */
/*   Updated: 2024/02/20 18:45:29 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_errors(t_var *data)
{
	mlx_destroy_image(data->mlx, data->enemy);
	mlx_destroy_image(data->mlx, data->enemy2);
	mlx_destroy_image(data->mlx, data->enemy3);
	mlx_destroy_image(data->mlx, data->enemy4);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->bground);
	mlx_destroy_image(data->mlx, data->salta3_birgar);
	mlx_destroy_image(data->mlx, data->door_c);
	mlx_destroy_image(data->mlx, data->sponge);
	mlx_destroy_image(data->mlx, data->back);
	mlx_destroy_image(data->mlx, data->left);
	mlx_destroy_image(data->mlx, data->right);
	mlx_destroy_image(data->mlx, data->door_o);
	mlx_destroy_window(data->mlx, data->mlx_window);
	write (2, "EXIT !", 7);
	exit (0);
	return (0);
}

void	ft_error(char *str)
{
	write (2, str, ft_strlen(str));
	exit (1);
}

void	ft_win(char *str, t_var *data)
{
	mlx_destroy_image(data->mlx, data->enemy);
	mlx_destroy_image(data->mlx, data->enemy2);
	mlx_destroy_image(data->mlx, data->enemy3);
	mlx_destroy_image(data->mlx, data->enemy4);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->bground);
	mlx_destroy_image(data->mlx, data->salta3_birgar);
	mlx_destroy_image(data->mlx, data->door_c);
	mlx_destroy_image(data->mlx, data->sponge);
	mlx_destroy_image(data->mlx, data->back);
	mlx_destroy_image(data->mlx, data->left);
	mlx_destroy_image(data->mlx, data->right);
	mlx_destroy_image(data->mlx, data->door_o);
	mlx_destroy_window(data->mlx, data->mlx_window);
	write (1, str, ft_strlen(str));
	exit(0);
}
