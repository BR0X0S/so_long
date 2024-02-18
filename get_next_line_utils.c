/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:40:01 by oumondad          #+#    #+#             */
/*   Updated: 2024/01/28 14:43:07 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strchr(char *str, char c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *stack, char *buffer)
{
	char	*str;
	size_t	j;
	size_t	i;
	size_t	stack_len;
	size_t	buffer_len;

	stack_len = ft_strlen(stack);
	buffer_len = ft_strlen(buffer);
	i = -1;
	str = malloc(stack_len + buffer_len + 1);
	if (!str)
		return (free(stack), free(buffer), NULL);
	while (++i < stack_len && stack)
		str[i] = stack[i];
	str[i] = '\0';
	j = -1;
	while (++j < buffer_len)
		str[i + j] = buffer[j];
	str[i + j] = '\0';
	return (free(stack), free(buffer), str);
}

void	ft_help(char *stack, char *tmp, int i)
{
	size_t	j;

	j = -1;
	while (stack[i + (++j)])
		tmp[j] = stack[i + j];
	tmp[j] = '\0';
}

char	*ft_check(int i, char *buffer, char *stack)
{
	if (i == 0)
		return (free (buffer), stack);
	return (free (buffer), free (stack), NULL);
}
