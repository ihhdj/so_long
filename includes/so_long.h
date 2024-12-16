/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:54:31 by ihhadjal          #+#    #+#             */
/*   Updated: 2024/12/16 10:36:17 by ihhadjal         ###   ########.fr       */
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

typedef	struct s_data
{
	void	*mlx_ptr;
	void	*window;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

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
void	parsing(t_parse	*parse, t_data *data);
int		create_window(t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);
#endif