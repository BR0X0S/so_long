/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:32:58 by oumondad          #+#    #+#             */
/*   Updated: 2024/02/21 16:45:38 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_alphabet(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || str[i] == '\0')
		ft_error("Error : map does not exist");
	while (str[i])
	{
		if (!(str[i] == '1' || str[i] == '0' || str[i] == 'P' || str[i] == 'M'
				|| str[i] == 'E' || str[i] == 'C' || str[i] == '\n'))
			ft_error("Error : new element add");
		i++;
	}
}

void	check_new_line(char *strr)
{
	int	i;

	i = 0;
	while (strr[i])
	{
		if ((strr[i] == '\n' && strr[i + 1] == '\n')
			|| strr[i] == ' ' || strr[i] == '\t' || strr[0] == '\n')
			ft_error("Error :something wrong with the architecture of the map");
		i++;
	}
	if (strr[i - 1] == '\n')
		ft_error("Error : something wrong with the architecture of the map");
}

void	check_elements(t_var data)
{
	static int	c = 0;
	static int	e = 0;
	static int	p = 0;
	static int	m = 0;

	while (data.i < data.x)
	{
		data.j = 0;
		while (data.map[data.i][data.j])
		{
			if (data.map[data.i][data.j] == 'C')
				c++;
			else if (data.map[data.i][data.j] == 'E')
				e++;
			else if (data.map[data.i][data.j] == 'P')
				p++;
			else if (data.map[data.i][data.j] == 'M')
				m++;
			data.j++;
		}
		data.i++;
	}
	if (e != 1 || p != 1 || c < 1 || m < 1)
		ft_error("Error : in the element of the map");
}

int	count_coin(t_var *data)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (data->strr[i])
	{
		if (data->strr[i] == 'C')
			c++;
		i++;
	}
	return (c);
}
