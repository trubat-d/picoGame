/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:22:06 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/23 23:10:16 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"

void	life(t_all *all)
{
	all->life--;
	if (!all->life)
		close_win(all);
	put_img_str(all, "./assets/wall.xpm", all->life * 64, 0);
}
