/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanisms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:07:59 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/23 19:56:01 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_walk(t_game **game)
{
	mlx_key_hook((*game)->mlx, (void *)ft_move, (void *)game);
}

void	ft_move(mlx_key_data_t keydata, t_game **game)
{
	if (keydata.action == MLX_PRESS)
	{
		if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W) \
			&& validate_vertical(game, -75) == 0)
			ft_up(game);
		if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S) \
			&& validate_vertical(game, 75) == 0)
			ft_down(game);
		if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D) \
			&& validate_horizontal(game, 75) == 0)
			ft_right(game);
		if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A) \
			&& validate_horizontal(game, -75) == 0)
			ft_left(game);
		check_bolts(game);
	}
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window((*game)->mlx);
}

int	validate_horizontal(t_game **game, int offset)
{
	size_t			i;
	unsigned int	percy_x;
	unsigned int	percy_y;
	unsigned int	tree_x;
	unsigned int	tree_y;

	i = 0;
	percy_y = (*game)->load->percy->instances[0].y;
	percy_x = (*game)->load->percy->instances[0].x + offset;
	while (i < (*game)->load->tree->count)
	{
		tree_x = (*game)->load->tree->instances[i].x;
		tree_y = (*game)->load->tree->instances[i].y;
		if (percy_x > tree_x && percy_y > tree_y && percy_x < tree_x \
			+ (*game)->load->tree->width && percy_y < tree_y \
			+ (*game)->load->tree->height)
			return (1);
		i++;
	}
	return (0);
}

int	validate_vertical(t_game **game, int offset)
{
	size_t			i;
	unsigned int	percy_x;
	unsigned int	percy_y;
	unsigned int	tree_x;
	unsigned int	tree_y;

	i = 0;
	percy_y = (*game)->load->percy->instances[0].y + offset;
	percy_x = (*game)->load->percy->instances[0].x;
	while (i < (*game)->load->tree->count)
	{
		tree_x = (*game)->load->tree->instances[i].x;
		tree_y = (*game)->load->tree->instances[i].y;
		if (percy_x > tree_x && percy_y > tree_y && percy_x < tree_x \
			+ (*game)->load->tree->width && percy_y < tree_y \
			+ (*game)->load->tree->height)
			return (1);
		i++;
	}
	return (0);
}

void	check_bolts(t_game **game)
{
	size_t			i;
	unsigned int	bolt_x;
	unsigned int	bolt_y;
	unsigned int	percy_x;
	unsigned int	percy_y;

	i = 0;
	percy_x = (*game)->load->percy->instances[0].x;
	percy_y = (*game)->load->percy->instances[0].y;
	while (i < (*game)->load->bolt->count)
	{
		bolt_y = (*game)->load->bolt->instances[i].y;
		bolt_x = (*game)->load->bolt->instances[i].x;
		if (bolt_x > percy_x && bolt_y > percy_y && bolt_x < percy_x \
			+ (*game)->load->percy->width && bolt_y < percy_y \
			+ (*game)->load->percy->height
			&& (*game)->load->bolt->instances[i].enabled == true)
		{
			(*game)->load->bolt->instances[i].enabled = false;
			(*game)->count->collected++;
			break ;
		}
		i++;
	}
	exit_game(game);
}
