/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:32:58 by oumondad          #+#    #+#             */
/*   Updated: 2024/02/13 13:11:32 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_alphabet(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || str[i] == '\0')
		ft_error("map does not exist");
	while (str[i])
	{
		if (!(str[i] == '1' || str[i] == '0' || str[i] == 'P' || str[i] == 'E'
				|| str[i] == 'C' || str[i] == '\n'))
			ft_error("Error new element add");
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
			ft_error("something wrong with the architecture of the map");
		i++;
	}
	if (strr[i - 1] == '\n')
		ft_error("something wrong with the architecture of the map");
}

void	check_elements(t_var data)
{
	int			i;
	int			j;
	static int	c = 0;
	static int	e = 0;
	static int	p = 0;

	i = 0;
	while (i < data.x)
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] == 'C')
				c++;
			else if (data.map[i][j] == 'E')
				e++;
			else if (data.map[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	if (e != 1 || p != 1 || c < 1)
		ft_error("Error in the element of the map");
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
