/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:55:05 by oumondad          #+#    #+#             */
/*   Updated: 2024/02/21 16:11:40 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_gps	ft_find_player(t_var data, char c)
{
	t_gps	pose;

	pose.y = 0;
	while (pose.y < data.x)
	{
		pose.x = 0;
		while (data.map[pose.y][pose.x])
		{
			if (data.map[pose.y][pose.x] == c)
				return (pose);
			pose.x++;
		}
		pose.y++;
	}
	return (pose);
}

char	**map_duplicate(t_var data)
{
	char	**copy;
	int		i;

	copy = malloc ((data.x + 1) * 8);
	if (!copy)
		ft_error("Error : Map duplicate faild\n");
	i = 0;
	while (i < data.x)
	{
		copy[i] = ft_strdup (data.map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

char	**flood_fill_player(int x, int y, char **map)
{
	if (map[y][x] == 'P' || map[y][x] == 'C' || map[y][x] == '0')
	{
		map[y][x] = 'X';
		flood_fill_player(x + 1, y, map);
		flood_fill_player(x - 1, y, map);
		flood_fill_player(x, y + 1, map);
		flood_fill_player(x, y - 1, map);
	}
	return (map);
}

char	**flood_fill_exit(int x, int y, char **map)
{
	if (map[y][x] == 'E' || map[y][x] == 'C'
		|| map[y][x] == '0' || map[y][x] == 'P')
	{
		map[y][x] = 'Z';
		flood_fill_exit(x + 1, y, map);
		flood_fill_exit(x - 1, y, map);
		flood_fill_exit(x, y + 1, map);
		flood_fill_exit(x, y - 1, map);
	}
	return (map);
}

void	map_valid(t_var data, char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.x)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				ft_error("the player can't win\n");
			j++;
		}
		i++;
	}
}
