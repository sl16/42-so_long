/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:20:27 by vbartos           #+#    #+#             */
/*   Updated: 2023/10/27 10:59:50 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_gameplay(t_game *game, int move_to_x, int move_to_y)
{
	ft_move_player(game, move_to_x, move_to_y);
	if (game->player_win == 1)
	{
		ft_free_struct(game);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

// ft_move_player
// - checks if provided move is valid;
// - if yes, sets current position's sprite to ground
//	and moves player to desired position;
// - sets player_win to 1 if win conditions are met;
int	ft_move_player(t_game *game, int move_to_x, int move_to_y)
{
	if (game->map[move_to_y][move_to_x] == '1')
		return (1);
	if (game->map[move_to_y][move_to_x] == 'C')
		game->map_collectibles--;
	if (game->map[move_to_y][move_to_x] == 'E' && game->map_collectibles == 0)
		game->player_win = 1;
	if (game->map[move_to_y][move_to_x] != 'E')
		game->map[move_to_y][move_to_x] = 'P';
	if (game->map[game->player_posy][game->player_posx] != 'E')
		game->map[game->player_posy][game->player_posx] = '0';
	game->player_posx = move_to_x;
	game->player_posy = move_to_y;
	game->player_moves++;
	ft_printf("Moves: %d\n", game->player_moves);
	return (0);
}

// ft_move_counter
// - shows the number of moves taken in game window
int	ft_move_counter(t_game *game)
{
	char	*moves;
	char	*str;

	moves = ft_itoa(game->player_moves);
	str = ft_strjoin("# of moves: ", moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 20, 20, 0xFFFFFF,
		"sprites by anokolisa.itch.io");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 20, 40, 0xFFFFFF, str);
	free(moves);
	free(str);
	return (0);
}
