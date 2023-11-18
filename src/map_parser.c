/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:23:10 by vbartos           #+#    #+#             */
/*   Updated: 2023/10/26 17:48:36 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// ft_arg_check
// - checks if provided number of args is two (path to map);
// - checks for the .ber format
int	ft_arg_check(int argc, char *argv, t_game *game)
{
	int	len;

	if (argc != 2)
		ft_print_error("Provide a path to your desired map (argc = 2).", game);
	len = ft_strlen(argv);
	if (!ft_strnstr(&argv[len - 4], ".ber", 4))
		ft_print_error("Provide a .ber file.", game);
	return (0);
}

// ft_map_parse
// - opens the file provided;
// - reads contents with get_next_line, stores in struct game;
// - closes the file provided;
// - stores the map width and height in struct game;
// - creates another copy of parsed map for path validation;
int	ft_map_parse(t_game *game, char *argv)
{
	char	*line;
	char	*temp;

	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
		ft_print_error("File cannot be opened.", game);
	line = get_next_line(game->fd);
	temp = ft_strdup("");
	while (line)
	{
		ft_map_parse2(game, line, &temp);
		line = get_next_line(game->fd);
	}
	close(game->fd);
	if (temp[ft_strlen(temp) - 1] == '\n')
		game->empty_line = 1;
	game->map = ft_split(temp, '\n');
	game->map_copy = ft_split(temp, '\n');
	game->map_width = ft_strlen(game->map[0]);
	free(temp);
	if (game->empty_line == 1)
		ft_print_error("Empty line detected in map.", game);
	return (0);
}
