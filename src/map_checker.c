/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:03:19 by vbartos           #+#    #+#             */
/*   Updated: 2023/10/26 18:10:44 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// ft_map_check
// - checks if map only contains permitted characters
//	in the correct amount (0, 1, C, E, P);
// - checks if map is rectangular;
// - checks if map is enclosed by walls;
// - checks if there is a valid path with flood fill;
int	ft_map_check(t_game *game)
{
	ft_check_chars(game);
	ft_check_rectangular(game);
	ft_check_enclosed(game);
	if (ft_check_path(game->player_posx, game->player_posy, game) == 1)
		ft_print_error("No viable path detected in map.", game);
	return (0);
}

int	ft_check_chars(t_game *game)
{
	int	row;
	int	i;

	row = 0;
	i = 0;
	while (row < game->map_height)
	{
		while (game->map[row][i] != '\0')
		{
			ft_check_chars2(game, row, i);
			i++;
		}
		i = 0;
		row++;
	}
	if (game->map_collectibles < 1 || game->map_starts != 1
		|| game->map_exits != 1)
		ft_print_error("Incorrect amount of permitted characters.", game);
	return (0);
}

int	ft_check_rectangular(t_game *game)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(game->map[i]);
	while (i < (game->map_height - 1))
	{
		if (len != ft_strlen(game->map[i + 1]))
			ft_print_error("Provided map is not rectangular.", game);
		else
		{
			i++;
			len = ft_strlen(game->map[i]);
		}
	}
	return (0);
}

int	ft_check_enclosed(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1')
			ft_print_error("Provided map is not enclosed in walls.", game);
		i++;
	}
	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
			ft_print_error("Provided map is not enclosed in walls.", game);
		i++;
	}
	return (0);
}

int	ft_check_path(int x, int y, t_game *game)
{
	static int	found_collectibles;
	static int	found_exit;

	if (found_collectibles == game->map_collectibles
		&& found_exit == game->map_exits)
		return (0);
	if (game->map_copy[y][x] == '1')
		return (1);
	if (game->map_copy[y][x] == 'C')
		found_collectibles++;
	else if (game->map_copy[y][x] == 'E')
		found_exit++;
	game->map_copy[y][x] = '1';
	if (ft_check_path(x + 1, y, game) == 0)
		return (0);
	if (ft_check_path(x - 1, y, game) == 0)
		return (0);
	if (ft_check_path(x, y + 1, game) == 0)
		return (0);
	if (ft_check_path(x, y - 1, game) == 0)
		return (0);
	return (1);
}
