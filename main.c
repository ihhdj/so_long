/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:16:32 by ihhadjal          #+#    #+#             */
/*   Updated: 2024/12/07 15:20:10 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	check_form(char *filename)
{
	int		fd;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	
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
		check_form(argv[1]);
	}
	return (0);
}
