/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:05:43 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/24 05:34:04 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "MLX42.h"
# include "libft.h"

# define WALL_SIZE 75

typedef struct s_assets
{
	mlx_texture_t	*t_bolt;
	mlx_image_t		*bolt;
	mlx_texture_t	*t_percy;
	mlx_image_t		*percy;
	mlx_texture_t	*t_portal;
	mlx_image_t		*portal;
	mlx_texture_t	*t_tree;
	mlx_image_t		*tree;
	mlx_texture_t	*t_enemy;
	mlx_image_t		*enemy;	
	mlx_texture_t	*t_bg;
	mlx_image_t		*bg;
	mlx_texture_t	*t_icon;
	mlx_image_t		*str;
	mlx_image_t		*label;
}					t_assets;

typedef struct s_count
{
	int	player;
	int	exit;
	int	coin;
	int	collected;
	int	steps;
}		t_count;

typedef struct s_game
{
	char		**map;
	char		**map_copy;
	mlx_t		*mlx;
	t_assets	*load;
	t_count		*count;
	int			len;
	size_t		x;
	size_t		y;
	int			screen_numbers;
	int			pos_x1;
	int			pos_y1;
	size_t		i;
	size_t		j;
}				t_game;

void	ft_create_matrix(char *path, t_game **game);
void	ft_read_map(t_game **game);
void	ft_load_assets(t_game **game);
void	ft_place_assets(t_game **game, int x, int y);
void	ft_free_load(t_game **game);
void	ft_free_struct(t_game **game);
int		validate_map(t_game **game, int x, int y);
int		validate_square_map(t_game **game);
int		ft_validate_characteres(t_game **game, int x, int y);
void	count_characters(t_game **game, int x, int y);
void	ft_move(mlx_key_data_t keydata, t_game **game);
void	ft_walk(t_game **game);
int		ft_validate_walk(t_game **game);
int		validate_horizontal(t_game **game, int offset);
int		validate_vertical(t_game **game, int offset);
void	check_bolts(t_game **game);
void	exit_game(t_game **game);
void	ft_flood_fill(t_game **game, int x, int y);
void	map_ok(t_game **game);
void	ft_up(t_game **game);
void	ft_down(t_game **game);
void	ft_left(t_game **game);
void	ft_right(t_game **game);
void	ft_check_place(t_game **game, int y, int x);
void	ft_check_place2(t_game **game, int y, int x);
void	ft_flood_fill(t_game **game, int x, int y);
void	ft_conditions(t_game **game, int x, int y);
void	collision(t_game **game);
void	ft_invalid_type(char *path, t_game **game);
void	ft_message(t_game **game);
void	ft_window(t_game **game);

#endif
