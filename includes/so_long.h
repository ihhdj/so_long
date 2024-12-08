/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:54:31 by ihhadjal          #+#    #+#             */
/*   Updated: 2024/12/08 13:16:43 by iheb             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define MAX_LIGNES 1000
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