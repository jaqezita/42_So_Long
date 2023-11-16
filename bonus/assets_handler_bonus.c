/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_handler_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:07:17 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/24 05:36:53 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_load_assets(t_game **game)
{
	(*game)->load->t_bolt = mlx_load_png("./assets/bolt/4.png");
	(*game)->load->bolt = mlx_texture_to_image((*game)->mlx, \
		(*game)->load->t_bolt);
	(*game)->load->t_percy = mlx_load_png("./assets/percy.png");
	(*game)->load->percy = mlx_texture_to_image((*game)->mlx, \
	(*game)->load->t_percy);
	(*game)->load->t_enemy = mlx_load_png("./assets/enemy.png");
	(*game)->load->enemy = mlx_texture_to_image((*game)->mlx, \
		(*game)->load->t_enemy);
	(*game)->load->t_tree = mlx_load_png("./assets/tree.png");
	(*game)->load->tree = mlx_texture_to_image((*game)->mlx, \
		(*game)->load->t_tree);
	(*game)->load->t_bg = mlx_load_png("./assets/bg.png");
	(*game)->load->bg = mlx_texture_to_image((*game)->mlx, \
		(*game)->load->t_bg);
	(*game)->load->t_portal = mlx_load_png("./assets/portal.png");
	(*game)->load->portal = mlx_texture_to_image((*game)->mlx, \
		(*game)->load->t_portal);
	(*game)->load->t_icon = mlx_load_png("./assets/icon.png");
}

void	ft_place_assets(t_game **game, int x, int y)
{
	mlx_image_to_window((*game)->mlx, (*game)->load->bg, y, x);
	ft_check_place(game, x, y);
	ft_check_place2(game, x, y);
	(*game)->load->portal->enabled = false;
	mlx_set_icon((*game)->mlx, (*game)->load->t_icon);
}

void	ft_check_place(t_game **game, int y, int x)
{
	(*game)->i = 0;
	x = 0;
	while ((*game)->i < (size_t)(*game)->len)
	{
		y = 0;
		(*game)->j = 0;
		while ((*game)->j <= ft_strlen((*game)->map[(*game)->i]))
		{
			if ((*game)->map[(*game)->i][(*game)->j] == '1')
				mlx_image_to_window((*game)->mlx, (*game)->load->tree, y, x);
			else if ((*game)->map[(*game)->i][(*game)->j] == 'P')
				mlx_image_to_window((*game)->mlx, \
				(*game)->load->percy, y + 10, x + 7);
			else if ((*game)->map[(*game)->i][(*game)->j] == 'E')
				mlx_image_to_window((*game)->mlx, \
				(*game)->load->portal, y + 5, x + 5);
			else if ((*game)->map[(*game)->i][(*game)->j] == 'C')
				mlx_image_to_window((*game)->mlx, \
				(*game)->load->bolt, y + 13, x + 15);
			(*game)->j++;
			y += 75;
		}
		(*game)->i++;
		x += 75;
	}
}

void	ft_check_place2(t_game **game, int y, int x)
{
	char	*steps;

	(*game)->i = 0;
	x = 0;
	while ((*game)->i < (size_t)(*game)->len)
	{
		y = 0;
		(*game)->j = 0;
		while ((*game)->j <= ft_strlen((*game)->map[(*game)->i]))
		{
			if ((*game)->map[(*game)->i][(*game)->j] == 'M')
				mlx_image_to_window((*game)->mlx, \
				(*game)->load->enemy, y + 5, x + 5);
			(*game)->j++;
			y += 75;
		}
		(*game)->i++;
		x += 75;
	}
	steps = ft_itoa((*game)->count->steps);
	(*game)->load->str = mlx_put_string((*game)->mlx, steps, 95, 10);
	(*game)->load->label = mlx_put_string((*game)->mlx, "Steps: ", 30, 10);
	free(steps);
}

void	exit_game(t_game **game)
{
	unsigned int	percy_x;
	unsigned int	percy_y;
	unsigned int	portal_x;
	unsigned int	portal_y;

	percy_x = (*game)->load->percy->instances->x;
	percy_y = (*game)->load->percy->instances->y;
	portal_y = (*game)->load->portal->instances->y;
	portal_x = (*game)->load->portal->instances->x;
	if ((size_t)(*game)->count->collected == (*game)->load->bolt->count)
		(*game)->load->portal->enabled = true;
	if ((*game)->load->portal->enabled == true \
		&& (percy_x > portal_x && percy_y > portal_y) \
		&& (percy_x < portal_x + (*game)->load->portal->width \
		&& percy_y < portal_y + (*game)->load->portal->height))
	{
		ft_printf("You won!\n");
		ft_free_load(game);
		mlx_terminate((*game)->mlx);
		ft_free_struct(game);
		exit(EXIT_SUCCESS);
	}
}
