/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:58:46 by hrolle            #+#    #+#             */
/*   Updated: 2022/11/20 14:51:37 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"
#include "../HEADER/get_next_line.h"

unsigned int	ft_strslen(char **ss)
{
	unsigned int	i;

	i = 0;
	while (ss[i])
		i++;
	return (i);
}

void	set_enemy(t_all *all)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	k = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (all->map[i][j++] == 'X')
			{
				all->enemy[k].y = i;
				all->enemy[k].x = j - 1;
				k++;
			}
		}
		i++;
	}
	all->enemy[k].y = 0;
	all->enemy[k].x = 0;
}

void	enemy_check(t_all *all)
{
	unsigned int	enemy;
	unsigned int	i;
	unsigned int	j;

	enemy = 0;
	i = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
			if (all->map[i][j++] == 'X')
				enemy++;
		i++;
	}
	all->enemy = malloc((enemy + 1) * sizeof(t_coor *));
	if (!all->enemy)
		exit_error(all, "Malloc error\n", 1);
	set_enemy(all);
}

int	set_all(t_all *all)
{
	if (read_map(all))
		return (1);
	all->map_size.x = ft_strlen(all->map[0]) - 1;
	all->map_size.y = ft_strslen(all->map);
	all->enemy = NULL;
	all->total_coin = 0;
	check_map(all);
	enemy_check(all);
	all->coin = 0;
	all->life = 3;
	all->exit = 0;
	all->move = 0;
	all->frame = 0;
	all->exit_code = 1;
	if (player_position(all))
		return (1);
	all->mlx = mlx_init();
	if (!all->mlx)
		return (1);
	all->window = mlx_new_window(all->mlx,
			all->map_size.x * 64, all->map_size.y * 64, "so_long");
	if (!all->window)
		return (1);
	if (map_gen(all))
		return (1);
	return (0);
}
