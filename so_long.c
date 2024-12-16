/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:31:37 by ihhadjal          #+#    #+#             */
/*   Updated: 2024/12/16 11:16:17 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	parsing(t_parse	*parse, t_data *data)
{
	check_map_form(parse);
	check_walls(parse);
	check_items(parse);
	find_pos(parse);
	parse->copy = copy_map(parse);
	flood_fill(parse->copy, parse->start_x, parse->start_y, parse);
	// print_map(parse->copy);
	check_flood(parse);
	free_map(parse->copy);
	free_map(parse->map);
	create_window(data);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
int	create_window(t_data *data)
{
	data->window = mlx_new_window(data->mlx_ptr, 600, 400, "so_long");
	data->img = mlx_new_image(data->mlx_ptr, 600, 400);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_length, &data->endian);
	put_pixel(data, 125, 125, 0x00FF0000);
	mlx_put_image_to_window(data->mlx_ptr, data->window, data->img, 0, 0);
	mlx_loop(data->mlx_ptr);
	return (0);
}
