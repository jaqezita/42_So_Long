/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:29:40 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/24 17:46:21 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_window(t_game **game)
{
	int32_t	x;
	int32_t	y;

	x = ft_strlen((*game)->map[0]) * WALL_SIZE;
	y = (*game)->len * WALL_SIZE;
	(*game)->mlx = mlx_init(x, y, "The Lightning Thief", 0);
}
