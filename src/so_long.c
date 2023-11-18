/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:22:30 by vbartos           #+#    #+#             */
/*   Updated: 2023/10/26 17:27:01 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// so_long
// - checks arguments if map is correctly provided;
// - parses the map;
// - checks if map is valid according to game rules;
// - initializes mlx and builds the map and assets;
// - listens to player input;
int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_print_error("Couldn't allocate memory for struct 'game'.", game);
	ft_init_struct(game);
	ft_arg_check(argc, argv[1], game);
	ft_map_parse(game, argv[1]);
	ft_map_check(game);
	ft_mlx_init(game);
	ft_free_struct(game);
	free(game);
	return (0);
}
