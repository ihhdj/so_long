/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:42:19 by ihhadjal          #+#    #+#             */
/*   Updated: 2024/12/09 20:00:50 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	check_walls(char	**map)
{
	// int	lignes;
	// int	colonnes;
	int	i;

	//lignes = 0;
	i = 0;
	while (*map[i])
	{
		i++;
		if (*map[i] != '1')
		{
			ft_printf("Error\n%s", "map is not surrounded by walls");
			exit(EXIT_FAILURE);	
		}
	}
	return (1);
}