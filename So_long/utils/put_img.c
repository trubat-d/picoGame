/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 03:10:42 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/23 23:12:17 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"

int	put_img(t_all *all, char c, int x, int y)
{
	if (c == '1' && (y == 0 && (unsigned)x == all->map_size.x - 1))
		return (put_img_str(all, "./assets/wall_moves.xpm", x * 64, y * 64));
	else if (c == '1' && (y == 0 && x >= 0 && x <= 2))
		return (put_img_str(all, "./assets/wall_life.xpm", x * 64, y * 64));
	else if (c == '1' && ((unsigned)x == 0 || (unsigned)x == all->map_size.x - 1
			|| (unsigned)y == 0 || (unsigned)y == all->map_size.y - 1))
		return (put_img_str(all, "./assets/wall.xpm", x * 64, y * 64));
	else if (c == '1')
		return (put_img_str(all, "./assets/tree.xpm", x * 64, y * 64));
	else if (c == '0')
		return (put_img_str(all, "./assets/floor.xpm", x * 64, y * 64));
	else if (c == 'C')
		return (put_img_str(all, "./assets/coin.xpm", x * 64, y * 64));
	else if (c == 'P')
		return (put_img_str(all, "./assets/player.xpm", x * 64, y * 64));
	else if (c == 'E')
		return (put_img_str(all, "./assets/exit.xpm", x * 64, y * 64));
	else if (c == 'X')
		return (put_img_str(all, "./assets/enemy.xpm", x * 64, y * 64));
	else
		return (1);
}
