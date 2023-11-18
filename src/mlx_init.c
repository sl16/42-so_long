/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:10:23 by vbartos           #+#    #+#             */
/*   Updated: 2023/10/26 17:26:50 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// ft_mlx_init
// - establishes connection with the X server via mlx_ptr;
// - creates a window based on the provided dimensions;
int	ft_mlx_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		ft_print_error("Couldn't establish connection with the X serv.", game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map_width * TEXTURE_RES,
			game->map_height * TEXTURE_RES, "so_long");
	if (!game->win_ptr)
		ft_print_error("Couldn't create window.", game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask,
		ft_free_struct, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask,
		ft_mlx_keypress, game);
	ft_xpm_convert(game);
	ft_mlx_refresh(game);
	mlx_loop_hook(game->mlx_ptr, ft_mlx_refresh, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}

// ft_keypress
// - listens for keypresses;
int	ft_mlx_keypress(int key, t_game *game)
{
	int	move_to_x;
	int	move_to_y;

	move_to_x = game->player_posx;
	move_to_y = game->player_posy;
	if (key == XK_Escape)
		ft_free_struct(game);
	else if (key == 'w' || key == XK_Up)
		move_to_y--;
	else if (key == 's' || key == XK_Down)
		move_to_y++;
	else if (key == 'a' || key == XK_Left)
		move_to_x--;
	else if (key == 'd' || key == XK_Right)
		move_to_x++;
	if (key == 'w' || key == XK_Up || key == 's' || key == XK_Down
		|| key == 'a' || key == XK_Left || key == 'd' || key == XK_Right)
		ft_gameplay(game, move_to_x, move_to_y);
	return (0);
}

// ft_mlx_render
// - renders the appropriate texture in window according to x and y;
int	ft_mlx_render(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->texture_player, x * TEXTURE_RES, y * TEXTURE_RES);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->texture_exit, x * TEXTURE_RES, y * TEXTURE_RES);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->texture_collectible, x * TEXTURE_RES, y * TEXTURE_RES);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->texture_ground, x * TEXTURE_RES, y * TEXTURE_RES);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->texture_wall, x * TEXTURE_RES, y * TEXTURE_RES);
	return (0);
}

// ft_mlx_refresh
// - refreshes the window and paints new textures according to changes;
int	ft_mlx_refresh(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			ft_mlx_render(game, x, y);
			x++;
		}
		y++;
	}
	ft_move_counter(game);
	return (0);
}

// ft_xpm_convert
// - loads all image assets into pointers;
int	ft_xpm_convert(t_game *game)
{
	game->texture_player = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/player.xpm", &game->texture_width, &game->texture_height);
	game->texture_exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/exit.xpm", &game->texture_width, &game->texture_height);
	game->texture_collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/collectible.xpm", &game->texture_width,
			&game->texture_height);
	game->texture_ground = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/ground.xpm", &game->texture_width, &game->texture_height);
	game->texture_wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"./assets/wall.xpm", &game->texture_width, &game->texture_height);
	if (!game->texture_player)
		ft_print_error("Player XPM image couldn't be converted.", game);
	if (!game->texture_exit)
		ft_print_error("Exit XPM image couldn't be converted.", game);
	if (!game->texture_collectible)
		ft_print_error("Collectible XPM image couldn't be converted.", game);
	if (!game->texture_ground)
		ft_print_error("Ground XPM image couldn't be converted.", game);
	if (!game->texture_wall)
		ft_print_error("Wall XPM image couldn't be converted.", game);
	return (0);
}
