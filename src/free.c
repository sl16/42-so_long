/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:41:47 by vbartos           #+#    #+#             */
/*   Updated: 2023/10/26 17:25:34 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// ft_print_error
// - prints a custom error message;
// - frees the entires struct;
// - exits the program;

int	ft_print_error(char	*error, t_game *game)
{
	ft_printf("Error\n%s\n", error);
	ft_free_struct(game);
	return (0);
}

// ft_free_struct
// - frees all alloc'd variables (maps, textures, mlx window);
int	ft_free_struct(t_game *game)
{
	int	player_win;

	player_win = game->player_win;
	if (game->map)
		ft_free_map(game);
	if (game->texture_player)
		mlx_destroy_image(game->mlx_ptr, game->texture_player);
	if (game->texture_exit)
		mlx_destroy_image(game->mlx_ptr, game->texture_exit);
	if (game->texture_collectible)
		mlx_destroy_image(game->mlx_ptr, game->texture_collectible);
	if (game->texture_wall)
		mlx_destroy_image(game->mlx_ptr, game->texture_wall);
	if (game->texture_ground)
		mlx_destroy_image(game->mlx_ptr, game->texture_ground);
	if (game->win_ptr && game->mlx_ptr)
		ft_free_window(game);
	free(game);
	if (player_win == 1)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}

// ft_free_map
// - frees both map and map_copy arrays;
int	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		free(game->map_copy[i]);
		i++;
	}
	free(game->map);
	free(game->map_copy);
	return (0);
}

// ft_free_window
// - closes the window and connection to X server;
// - used with ESC key or mouseclick on X button;
int	ft_free_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	return (0);
}
