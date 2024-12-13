/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:31:37 by ihhadjal          #+#    #+#             */
/*   Updated: 2024/12/13 17:34:42 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	parsing(t_parse	*parse)
{
	check_map_form(parse);
	check_walls(parse);
	check_items(parse);
	find_pos(parse);
	parse->copy = copy_map(parse);
	flood_fill(parse->copy, parse->start_x, parse->start_y, parse);
	print_map(parse->copy);
	check_flood(parse);
	free_map(parse->copy);
	free_map(parse->map);
}

int	create_window(t_data *data)
{
	data->window = mlx_new_window(data->mlx_ptr, 600, 400, "so_long");
	if (!data->window)
		return (free(data->mlx_ptr), 1);
	mlx_destroy_window(data->mlx_ptr, data->window);
	mlx_destroy_display(data->mlx_ptr);
	free (data->mlx_ptr);
	return (0);
}