/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:54:31 by ihhadjal          #+#    #+#             */
/*   Updated: 2024/12/10 19:23:51 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define MAX_LIGNES 10000
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/header/libft.h"
# include "../libft/header/get_next_line.h"
# include "../libft/header/ft_printf.h"
# include <mlx.h>

typedef struct s_parse
{
	char	**map;
	int		line_map;
	int		colonne_map;
	char	*ligne_gnl;
	int		pos;
	int		item;
	int		eexit;
	size_t	long_line;
}	t_parse;

int		check_map_form(t_parse *parse);
void	stock_map(char *filename,t_parse *parse);
int		check_file(char *map);
void	free_map(char **map);
int		main(int argc, char **argv);
int		check_walls(t_parse *parse);
int		check_items(t_parse *parse);

#endif