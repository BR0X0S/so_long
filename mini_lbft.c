/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lbft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:33:42 by oumondad          #+#    #+#             */
/*   Updated: 2024/02/12 12:55:43 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*place;
	size_t	i;

	if (count && (SIZE_MAX) / count < size)
		return (NULL);
	place = malloc (count * size);
	if (place == 0)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		place[i] = '\0';
		i++;
	}
	return (place);
}

int	ft_strcmp(char *substr, char *ber)
{
	int	i;

	i = 0;
	while (substr[i] == ber[i] && ber[i])
	{
		if (substr[i] != ber[i])
			return (1);
		i++;
	}
	if (substr[i] == '\0' && ber[i] == '\0')
		return (0);
	return (1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*place;
	size_t	i;

	place = malloc (len + 1);
	if (!place)
		ft_error ("Error : substr allocation faild");
	i = 0;
	while (i < len && s[start])
	{
		place[i] = s[start];
		i++;
		start++;
	}
	place[i] = '\0';
	return (place);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*copy;

	i = 0;
	copy = malloc(ft_strlen(s1) + 1);
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
