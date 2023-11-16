/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:29:40 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/24 05:45:24 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_invalid_type(char *path, t_game **game)
{
	if (!ft_strnstr(path, ".ber", ft_strlen(path)))
		ft_message(game);
}

void	ft_message(t_game **game)
{
	ft_free_struct(game);
	exit(ft_printf("Error\n%s\n", "INVALID MAP"));
}

void	collision(t_game **game)
{
	size_t			i;
	unsigned int	enemy_x;
	unsigned int	enemy_y;
	unsigned int	percy_x;
	unsigned int	percy_y;

	i = 0;
	percy_x = (*game)->load->percy->instances[0].x;
	percy_y = (*game)->load->percy->instances[0].y;
	while (i < (*game)->load->enemy->count)
	{
		enemy_x = (*game)->load->enemy->instances[i].x;
		enemy_y = (*game)->load->enemy->instances[i].y;
		if ((percy_x > enemy_x && percy_y > enemy_y) && (percy_y < enemy_y \
			+ (*game)->load->enemy->width && percy_x < enemy_x \
			+ (*game)->load->enemy->height))
		{
			ft_free_load(game);
			mlx_terminate((*game)->mlx);
			ft_free_struct(game);
			exit((ft_printf("%s\n", "GAME OVER")));
		}
		i++;
	}
}

void	ft_flood_fill(t_game **game, int x, int y)
{
	if ((*game)->map_copy[y][x] == 'C')
		(*game)->count->coin--;
	if ((*game)->map_copy[y][x] == 'E')
		(*game)->count->exit--;
	if ((*game)->map_copy[y][x] == '1' || (*game)->map_copy[y][x] == '#' \
	|| (*game)->map_copy[y][x] == 'M' )
		return ;
	(*game)->map_copy[y][x] = '#';
	ft_flood_fill(game, x + 1, y);
	ft_flood_fill(game, x - 1, y);
	ft_flood_fill(game, x, y + 1);
	ft_flood_fill(game, x, y - 1);
}

void	ft_window(t_game **game)
{
	int32_t	x;
	int32_t	y;

	x = ft_strlen((*game)->map[0]) * WALL_SIZE;
	y = (*game)->len * WALL_SIZE;
	(*game)->mlx = mlx_init(x, y, "The Lightning Thief", 0);
}
