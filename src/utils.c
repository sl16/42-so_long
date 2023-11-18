/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:35:34 by vbartos           #+#    #+#             */
/*   Updated: 2023/10/26 17:46:57 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// ft_init_struct
// - initializes variables in struct for clean handling;
int	ft_init_struct(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->fd = 0;
	game->empty_line = 0;
	game->map = NULL;
	game->map_copy = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->map_starts = 0;
	game->map_exits = 0;
	game->map_collectibles = 0;
	game->player_posx = 0;
	game->player_posy = 0;
	game->player_moves = 0;
	game->player_win = 0;
	game->texture_player = NULL;
	game->texture_exit = NULL;
	game->texture_collectible = NULL;
	game->texture_ground = NULL;
	game->texture_wall = NULL;
	game->texture_width = 0;
	game->texture_height = 0;
	return (0);
}

// ft_check_chars2
// - second part of ft_check_chars because norminette is annoying;
int	ft_check_chars2(t_game *game, int row, int i)
{
	if (game->map[row][i] != '0' && game->map[row][i] != '1'
		&& game->map[row][i] != 'C' && game->map[row][i] != 'E'
		&& game->map[row][i] != 'P')
		ft_print_error("Non-permitted characters detected.", game);
	if (game->map[row][i] == 'C')
		game->map_collectibles++;
	else if (game->map[row][i] == 'P')
	{
		game->map_starts++;
		game->player_posx = i;
		game->player_posy = row;
	}
	else if (game->map[row][i] == 'E')
		game->map_exits++;
	return (0);
}

// ft_map_parse2
// - second part of ft_map_parse because norminette is annoying;
int	ft_map_parse2(t_game *game, char *line, char **temp)
{
	char	*concat;

	if (line[0] == '\n')
		game->empty_line = 1;
	concat = ft_strjoin(*temp, line);
	free(*temp);
	*temp = concat;
	free(line);
	game->map_height++;
	return (0);
}
