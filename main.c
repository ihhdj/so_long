/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:16:32 by ihhadjal          #+#    #+#             */
/*   Updated: 2024/12/09 15:11:56 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	check_map_form(char **map)
{
	size_t	taille;
	int		i;

	taille = ft_strlen(map[0]);
	i = 1;
	if (!map || !map[0])
	{
		ft_printf("Error\n%s", "map does not exist");
		exit(EXIT_FAILURE);
	}
	while (map[i])
	{
		if (ft_strlen(map[i]) != taille)
		{
			ft_printf("Error\n%s", "invalid map");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (1);
}

char	**stock_map(char *filename)
{
	char	**map;
	char	*ligne;
	int		fd;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);	
	map = malloc(sizeof(char *) * (MAX_LIGNES + 1));
	if (!map)
		exit(EXIT_FAILURE);
	ligne = get_next_line(fd);
	while (ligne)
	{
		if (ligne[ft_strlen(ligne) - 1] == '\n')
			ligne[ft_strlen(ligne) - 1] = '\0';
		map[i++] = ligne;
		ligne = get_next_line(fd);
	}
	map[i] = NULL;
	close (fd);
	return (map);
}

int	check_file(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n%s", "cannot open this file");
		exit(EXIT_FAILURE);
	}
	close (fd);
	return (1);
}
void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
	{
		ft_printf("Error\n%s", "argument error");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 20) != 0)
	{	
		ft_printf ("Error\n%s", "choose a .ber file");
		exit(EXIT_FAILURE);;
	}
	check_file(argv[1]);
	map = stock_map(argv[1]);
	check_map_form(map);
	free_map(map);
	return (0);
}
