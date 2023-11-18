/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:40:28 by vbartos           #+#    #+#             */
/*   Updated: 2023/10/26 17:47:31 by vbartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TEXTURE_RES 64

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include "../minilibx_linux/mlx.h"

# include <stdio.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_game {
	void	*mlx_ptr;
	void	*win_ptr;

	int		fd;
	int		empty_line;
	char	**map;
	char	**map_copy;
	int		map_width;
	int		map_height;
	int		map_starts;
	int		map_exits;
	int		map_collectibles;

	int		player_posx;
	int		player_posy;
	int		player_moves;
	int		player_win;

	void	*texture_player;
	void	*texture_exit;
	void	*texture_collectible;
	void	*texture_ground;
	void	*texture_wall;
	int		texture_width;
	int		texture_height;
}				t_game;

int	ft_init_struct(t_game *game);
int	ft_arg_check(int argc, char *argv, t_game *game);
int	ft_map_parse(t_game *game, char *argv);
int	ft_map_parse2(t_game *game, char *line, char **temp);

int	ft_map_check(t_game *game);
int	ft_check_chars(t_game *game);
int	ft_check_chars2(t_game *game, int row, int i);
int	ft_check_rectangular(t_game *game);
int	ft_check_enclosed(t_game *game);
int	ft_check_path(int x, int y, t_game *game);

int	ft_mlx_init(t_game *game);
int	ft_mlx_keypress(int key, t_game *game);
int	ft_mlx_render(t_game *game, int x, int y);
int	ft_mlx_refresh(t_game *game);
int	ft_xpm_convert(t_game *game);

int	ft_gameplay(t_game *game, int move_to_x, int move_to_y);
int	ft_move_player(t_game *game, int x, int y);
int	ft_move_counter(t_game *game);

int	ft_print_error(char	*error, t_game *game);
int	ft_free_struct(t_game *game);
int	ft_free_map(t_game *game);
int	ft_free_window(t_game *game);

#endif