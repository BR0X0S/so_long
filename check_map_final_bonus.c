/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_final_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:26:02 by oumondad          #+#    #+#             */
/*   Updated: 2024/02/19 19:05:06 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_var	get_map(int fd)
{
	t_var	data;

	data.i = 0;
	data.x = 0;
	data.strr = NULL;
	while (1)
	{
		data.line = get_next_line(fd);
		if (!data.line)
			break ;
		data.strr = ft_strjoin(data.strr, data.line);
		if (!data.strr)
			ft_error("Error : strjoin faild\n");
		data.x++;
	}
	check_alphabet(data.strr);
	check_new_line(data.strr);
	data.map = ft_split (data.strr, '\n');
	if (!data.map)
		ft_error("Error : split allocation Error\n");
	check_elements(data);
	close (fd);
	return (data);
}

int	ft_check_if_ber(char **av)
{
	int		i;
	char	*str;

	if (av[1][5] == '.' && (ft_strlen(av[1]) - 9) == 0)
		ft_error("Error : hidden file .ber\n");
	i = ft_strlen(av[1]) - 4;
	str = ft_substr(av[1], i, 5);
	if (!str)
		ft_error("Error : substr in .ber check faild\n");
	if (i == 0)
		return (free(str), 1);
	if (ft_strcmp(str, ".ber") != 0)
		return (free(str), 1);
	return (free(str), 0);
}

int	check_first_last(t_var data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data.map[0][i] == '1')
		i++;
	if (data.map[0][i] != '\0')
		return (1);
	while (data.map[data.x - 1][j] == '1')
		j++;
	if (data.map[data.x - 1][j] != '\0')
		return (1);
	if (j == i && (data.x > 1))
		return (0);
	return (1);
}

int	check_walls(t_var data)
{
	int		j;
	size_t	len;

	j = 0;
	len = ft_strlen(data.map[j]);
	if (check_first_last(data) != 0)
		return (1);
	while (j < data.x)
	{
		if (len != ft_strlen(data.map[j]))
			ft_error("Error : lenght of lines not correct\n");
		if (data.map[j][0] != '1'
			|| data.map[j][ft_strlen(data.map[j]) - 1] != '1')
			return (1);
		j++;
	}
	return (0);
}

t_var	ft_check_map(char **av)
{
	t_var	data;
	t_gps	pose;

	data.fd = open(av[1], O_RDONLY);
	if (ft_check_if_ber(av) != 0)
		ft_error("Error : Error on ext .ber\n");
	data = get_map(data.fd);
	data.len_x = ft_strlen(data.map[data.x - 1]);
	data.len_y = data.x;
	if (data.len_x > 64 || data.len_y > 35)
		ft_error("Error : map resolution error !\n");
	if (check_walls(data) != 0)
		ft_error("Error : Error on cader of the map\n");
	pose = ft_find_player(data, 'P');
	data.gps_x = pose.x;
	data.gps_y = pose.y;
	data.map_check_c = map_duplicate(data);
	data.map_check_c = flood_fill_player(pose.x, pose.y, data.map_check_c);
	map_valid (data, data.map_check_c, 'C');
	data.map_check_all = map_duplicate(data);
	data.map_check_all = flood_fill_exit(pose.x, pose.y, data.map_check_all);
	map_valid (data, data.map_check_all, 'E');
	data.salta3_count = count_coin(&data);
	return (data);
}
