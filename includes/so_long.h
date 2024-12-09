/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:54:31 by ihhadjal          #+#    #+#             */
/*   Updated: 2024/12/09 10:44:11 by ihhadjal         ###   ########.fr       */
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

typedef struct s_map
{
	char	**gnlmap;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		exits;
	int		players;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[5];
	t_map	*map;
}	t_data;

#endif