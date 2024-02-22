/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oumondad <oumondad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:40:12 by oumondad          #+#    #+#             */
/*   Updated: 2024/02/21 16:48:24 by oumondad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*DEFINE KEY MOVEMENT*/

# define UP_KEY 126
# define W_KEY 13
# define DOWN_KEY 125
# define S_KEY 1
# define LEFT_KEY 123
# define A_KEY 0
# define RIGHT_KEY 124
# define D_KEY 2

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

/*GET PLAYER POSE STRUCT*/

typedef struct s_gps
{
	int	x;
	int	y;
}	t_gps;

/*GET MAP STRUCT*/

typedef struct s_var
{
	char	*strr;
	char	*line;
	char	**map;
	char	**map_check_c;
	char	**map_check_all;
	int		gps_x;
	int		gps_y;
	int		fd;
	int		x;
	int		len_x;
	int		len_y;
	void	*mlx;
	void	*wall;
	void	*bground;
	void	*salta3_birgar;
	void	*sponge;
	void	*back;
	void	*left;
	void	*right;
	void	*door_o;
	void	*door_c;
	void	*mlx_window;
	int		width;
	int		height;
	int		salta3_count;
}	t_var;

/*GET NEXT LINE FUNCTIONS*/

char	*get_next_line(int fd);
size_t	ft_strlen(char const *str);
size_t	ft_strchr(char *str, char c);
void	ft_help(char *stack, char *tmp, int i);
char	*ft_strjoin(char *stack, char *buffer);
char	*ft_check(int i, char *buffer, char *stack);

/*CHECK MAP FUNCTIONS*/

t_var	get_map(int fd);
void	ft_error(char *str);
int		count_coin(t_var *data);
int		check_walls(t_var data);
t_var	ft_check_map(char **av);
void	check_alphabet(char *str);
int		ft_check_if_ber(char **av);
void	check_elements(t_var data);
void	check_new_line(char *strr);
int		check_first_last(t_var data);
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *substr, char *ber);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*FLOOD FILL FUNCTIONS*/

char	*ft_strdup(char *s1);
char	**map_duplicate(t_var data);
t_gps	ft_find_player(t_var data, char c);
void	map_valid(t_var data, char **map, char c);
char	**flood_fill_exit(int x, int y, char **map);
char	**flood_fill_player(int x, int y, char **map);

/*DRAWING MAP FUCTIONS*/

void	put_image(t_var data);
void	initialize_image(t_var *data);
void	initialize_image_2(t_var *data);
void	ft_check_open_door(t_var *data);
void	put_image_v2(t_var data, int x, int y);

/*MOVING COUNT FUNCTIONS*/

void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_player_mv(void);

/*MOVING FUNCTIONS*/

void	up_move(t_var *data);
void	down_move(t_var *data);
void	left_move(t_var *data);
void	right_move(t_var *data);
int		ft_moving(int keycode, t_var *data);

/*DESTROY FUNCTIONS*/

int		ft_errors(t_var *data);
void	ft_win(char *str, t_var *data);

/*********************/

#endif