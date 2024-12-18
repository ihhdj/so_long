/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:31:37 by ihhadjal          #+#    #+#             */
/*   Updated: 2024/12/18 18:58:31 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	parsing(t_parse	*parse, t_game *game, t_textures *text)
{
	check_map_form(parse);
	check_walls(parse);
	check_items(parse);
	find_pos(parse);
	parse->copy = copy_map(parse);
	flood_fill(parse->copy, parse->start_x, parse->start_y, parse);
	// print_map(parse->copy);
	check_flood(parse);
	init_game(game, parse->map);
	load_textures(game, text);
	free_map(parse->copy);
	free_map(parse->map);
}


void	init_game(t_game *game, char **map)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit(EXIT_FAILURE);
	game->map = map;
	game->height = 0;
	while (map[game->height])
		game->height++;
	game->width = ft_strlen(map[0]);
	game->window = mlx_new_window(game->mlx, game->width * 64,
			game->height * 64, "So_long");
}

void	load_textures(t_game *game, t_textures *text)
{
	int	width;
	int	height;

	text->background = mlx_xpm_file_to_image(game->mlx, "xpm/grass.xpm", &width, &height);
	text->wall = mlx_xpm_file_to_image(game->mlx, "xpm/wall.xpm", &width, &height);
	text->player = mlx_xpm_file_to_image(game->mlx, "xpm/player.xpm", &width, &height);
	text->collec = mlx_xpm_file_to_image(game->mlx, "xpm/gold.xpm", &width, &height);
	text->exit = mlx_xpm_file_to_image(game->mlx, "xpm/exit.xpm", &width, &height);
	if (!text->background || !text->wall || !text->player || !text->collec || !text->exit)
	{
		ft_printf("Error:\nxpm file is not available");
		exit(EXIT_FAILURE);
	}
}

