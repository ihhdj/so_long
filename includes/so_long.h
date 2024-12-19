/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:54:31 by ihhadjal          #+#    #+#             */
/*   Updated: 2024/12/19 11:09:44 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/header/libft.h"
# include "../libft/header/get_next_line.h"
# include "../libft/header/ft_printf.h"
# include <mlx.h>

typedef	struct s_parse
{
	char	**map;
	char	**copy;
	int		line_map;
	int		colonne_map;
	char	*ligne_gnl;
	int		pos;
	int		item;
	int		eexit;
	size_t	long_line;
	int		count;
	int		cols;
	int		rows;
	int		start_x;
	int		start_y;
}	t_parse;

typedef	struct s_game
{
	void	*mlx;
	void	*window;
	int		height;
	int		width;
	char	**map;
}	t_game;

typedef	struct s_textures
{
	void	*background;
	void	*wall;
	void	*player;
	void	*collec;
	void	*exit;
}	t_textures;


int		check_map_form(t_parse *parse);
void	stock_map(char *filename, t_parse *parse);
int		check_file(char *map, t_parse *parse);
void	free_map(char **map);
int		check_walls(t_parse *parse);
int		check_items(t_parse *parse);
void	ft_error(char *str, t_parse *parse);
void	init_parse(t_parse *parse);
int		ft_count_lines(char	*filename, t_parse *parse);
void	flood_fill(char	**map, int x, int y, t_parse *parse);
int		find_pos(t_parse *parse);
char	**copy_map(t_parse *parse);
void	print_map(char **map);
void	check_flood(t_parse *parse);
void	parsing(t_parse	*parse, t_game *game, t_textures *text);
void	load_textures(t_game *game, t_textures *text);
void	init_game(t_game *game, char **map);
void	draw_map(t_game *game, t_textures *text, t_parse *parse);
#endif