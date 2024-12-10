/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:42:19 by ihhadjal          #+#    #+#             */
/*   Updated: 2024/12/10 20:37:00 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	check_walls(t_parse *parse)
{
	int	i;

	i = 0;
	parse->line_map = 0;
	while (parse->map[parse->line_map])
		parse->line_map++;
	parse->colonne_map = ft_strlen(parse->map[0]);
	while (i < parse->colonne_map) 
	{
		if (parse->map[0][i] != '1' ||
			parse->map[parse->line_map - 1][i] != '1')
			ft_printf("Error\n%s", "map is not surrounded by walls");
		i++;
	}
	i = 0;
	while (i < parse->line_map)
	{
		if (parse->map[i][0] != '1' ||
			parse->map[i][parse->colonne_map - 1] != '1')
			ft_printf("Error\n%s", "map is not surrounded by walls");
		i++;
	}
	return (1);
}
void	init_parse(t_parse *parse)
{
	parse->eexit = 0;
	parse->item = 0;
	parse->pos = 0;
}
int	check_items(t_parse *parse)
{
	int	i;
	int	j;

	init_parse(parse);
	i = 0;
	while(parse->map[i])
	{
		j = 0;
		while (parse->map[i][j])
		{
			if (parse->map[i][j] == 'C')
				parse->item += 1;
			else if (parse->map[i][j] == 'P')
				parse->pos += 1;
			else if (parse->map[i][j] == 'E')
				parse->eexit += 1;
			j++;
		}
		i++;
	}
	if (parse->eexit != 1 || parse->pos != 1 || parse->item <= 0)
	{
		printf("Error\n%s", "invalid map");
		exit(EXIT_FAILURE);
	}
	return (1);
}
