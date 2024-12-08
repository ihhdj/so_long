/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:16:32 by ihhadjal          #+#    #+#             */
/*   Updated: 2024/12/08 13:47:34 by iheb             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

char	**stock_map(char *filename)
{
	char	**map;
	char	*ligne;
	int		fd;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	map = malloc(sizeof(char *) * (MAX_LIGNES + 1);
	if (!map)
		return (NULL);
	if (fd < 0)
		return (NULL);
	while ((ligne = get_next_line(fd)))
	{
		if (i >= MAX_LIGNES)
		{
			free (ligne);
			break;
		}
		map[i++] = ligne;
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
		ft_printf("Error, cannot open this file\n");
		return (0);
	}
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	int		len_argv;
	char	*ext;

	if (argc != 2)
		ft_printf("Arguments error\n");
	else
	{
		ext = ".ber";
		len_argv = ft_strlen(argv[1]);
		if(ft_strncmp(argv[1] + len_argv - 4, ext, 20) != 0)
			ft_printf("choose a .ber file\n");
		check_file(argv[1]);
		printf("%s", (char *)stock_map(argv[1]));
	}
	return (0);
}
