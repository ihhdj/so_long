/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:39:00 by ihhadjal          #+#    #+#             */
/*   Updated: 2024/12/12 20:20:42 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	flood_fill(char	**map, int x, int y, t_parse *parse)
{
	if (x < 0 || y < 0 || y >= parse->count|| x >= parse->colonne_map||
		map[y][x] == 'V' || map[y][x] == '1')
		return ;
	else
	{
		map[y][x] = 'V';
		flood_fill(map, x + 1, y, parse);
		flood_fill(map, x - 1, y, parse);
		flood_fill(map, x, y + 1, parse);
		flood_fill(map, x, y - 1, parse);
	}
}
int	find_pos(t_parse *parse)
{
	int	y;
	int	x;

	parse->start_x = -1;
	parse->start_y = -1;
	y = 0;
	while (y < parse->count)
	{
		x = 0;
		while(x < parse->colonne_map)
		{
			if (parse->map[y][x] == 'P')
			{
				parse->start_x = x;
				parse->start_y = y;
				break;
			}
			x++;
		}
		y++;
	}
	if (parse->start_x == -1 || parse->start_y == -1)
		ft_error("Error:\nno starting point found", parse);
	return (1);
}
char	**copy_map(t_parse *parse)
{
	char	**map_cpy;
	int		i;

	i = 0;
	map_cpy = malloc(sizeof(char *) * (parse->count + 1));
	while (i < parse->count)
	{
		map_cpy[i] = ft_strdup(parse->map[i]);
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}
void	print_map(char **map)
{
	int		i;
	
	i = 0;
	while (map[i])
	{
		ft_printf(map[i]);
		write(1, "\n", 2);
		i++;
	}
	write(1, "\n" ,2);
}
void	check_flood(t_parse *parse)
{
	int i;
	int	j;

	i = 0;
	while (parse->copy[i])
	{
		j = 0;
		while (parse->copy[i][j])
		{
			if (parse->copy[i][j] == 'E' || parse->copy[i][j] == 'C')
				ft_error("Error:\nplayer cannot reach everything", parse);
			j++;
		}
		i++;
	}
}