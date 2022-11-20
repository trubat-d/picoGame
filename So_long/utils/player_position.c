/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 04:46:28 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/23 23:11:05 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"

int	player_position(t_all *all)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == 'P')
			{
				all->player.x = x;
				all->player.y = y;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
