/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 03:23:14 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/23 23:10:43 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"

int	map_gen(t_all *all)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j] && all->map[i][j] != '\n')
		{
			if (put_img(all, all->map[i][j], j, i))
				return (1);
			j++;
		}
		i++;
	}
	str = itostr_base(all->move, "0123456789", 10);
	mlx_string_put(all->mlx, all->window,
		(all->map_size.x - 1) * 64 + 25, 36, 0xFFFFFF, str);
	free(str);
	return (0);
}
