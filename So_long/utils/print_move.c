/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:08:20 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/23 23:11:23 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"

void	print_move(t_all *all)
{
	char	*str;

	put_img_str(all, "./assets/wall_moves.xpm", (all->map_size.x - 1) * 64, 0);
	str = itostr_base(all->move, "0123456789", 10);
	mlx_string_put(all->mlx, all->window,
		(all->map_size.x - 1) * 64 + 25, 36, 0xFFFFFF, str);
	free(str);
}
