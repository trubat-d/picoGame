/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 05:09:59 by hrolle            #+#    #+#             */
/*   Updated: 2022/11/20 14:59:23 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"

void	up_move(t_all *all)
{
	if (all->player.y && all->map[all->player.y - 1][all->player.x] == 'X')
		life(all);
	else if (all->player.y && all->map[all->player.y - 1][all->player.x] != '1')
	{
		if (all->map[all->player.y - 1][all->player.x] == 'E' && !all->exit)
		{
			put_img_str(all, PLAYER_UP,
				all->player.x * 64, all->player.y * 64);
			return ;
		}
		else if (all->map[all->player.y - 1][all->player.x] == 'E')
		{
			all->exit_code = 0;
			close_win(all);
		}
		put_img(all, '0', all->player.x, all->player.y);
		all->map[all->player.y][all->player.x] = '0';
		all->player.y--;
		if (all->map[all->player.y][all->player.x] == 'C')
			all->coin++;
		all->map[all->player.y][all->player.x] = 'P';
		if (all->coin == all->total_coin && !all->exit)
			exit_on(all);
		all->move++;
		print_move(all);
	}
	put_img_str(all, PLAYER_UP, all->player.x * 64, all->player.y * 64);
}

void	down_move(t_all *all)
{
	if (all->player.y < all->map_size.y
		&& all->map[all->player.y + 1][all->player.x] == 'X')
		life(all);
	else if (all->player.y < all->map_size.y
		&& all->map[all->player.y + 1][all->player.x] != '1')
	{
		if (all->map[all->player.y + 1][all->player.x] == 'E' && !all->exit)
		{
			put_img_str(all, PLAYER, all->player.x * 64, all->player.y * 64);
			return ;
		}
		else if (all->map[all->player.y + 1][all->player.x] == 'E')
		{
			all->exit_code = 0;
			close_win(all);
		}
		put_img(all, '0', all->player.x, all->player.y);
		all->map[all->player.y][all->player.x] = '0';
		all->player.y++;
		if (all->map[all->player.y][all->player.x] == 'C')
			all->coin++;
		all->map[all->player.y][all->player.x] = 'P';
		if (all->coin == all->total_coin && !all->exit)
			exit_on(all);
		all->move++;
		print_move(all);
	}
	put_img_str(all, PLAYER, all->player.x * 64, all->player.y * 64);
}

void	left_move(t_all *all)
{
	if (all->player.x < all->map_size.x
		&& all->map[all->player.y][all->player.x - 1] == 'X')
		life(all);
	else if (all->player.x < all->map_size.x
		&& all->map[all->player.y][all->player.x - 1] != '1')
	{
		if (all->map[all->player.y][all->player.x - 1] == 'E' && !all->exit)
		{
			put_img_str(all, PLAYER_L, all->player.x * 64, all->player.y * 64);
			return ;
		}
		else if (all->map[all->player.y][all->player.x - 1] == 'E')
		{
			all->exit_code = 0;
			close_win(all);
		}
		put_img(all, '0', all->player.x, all->player.y);
		all->map[all->player.y][all->player.x] = '0';
		all->player.x--;
		if (all->map[all->player.y][all->player.x] == 'C')
			all->coin++;
		all->map[all->player.y][all->player.x] = 'P';
		if (all->coin == all->total_coin && !all->exit)
			exit_on(all);
		all->move++;
		print_move(all);
	}
	put_img_str(all, PLAYER_L, all->player.x * 64, all->player.y * 64);
}

void	right_move(t_all *all)
{
	if (all->player.x && all->map[all->player.y][all->player.x + 1] == 'X')
		life(all);
	else if (all->player.x && all->map[all->player.y][all->player.x + 1] != '1')
	{
		if (all->map[all->player.y][all->player.x + 1] == 'E' && !all->exit)
		{
			put_img_str(all, PLAYER_R,
				all->player.x * 64, all->player.y * 64);
			return ;
		}
		else if (all->map[all->player.y][all->player.x + 1] == 'E')
		{
			all->exit_code = 0;
			close_win(all);
		}
		put_img(all, '0', all->player.x, all->player.y);
		all->map[all->player.y][all->player.x] = '0';
		all->player.x++;
		if (all->map[all->player.y][all->player.x] == 'C')
			all->coin++;
		all->map[all->player.y][all->player.x] = 'P';
		if (all->coin == all->total_coin && !all->exit)
			exit_on(all);
		all->move++;
		print_move(all);
	}
	put_img_str(all, PLAYER_R, all->player.x * 64, all->player.y * 64);
}

int	key_event(int keycode, t_all *all)
{
	(void)all;
	if (keycode == 126 || keycode == 13)
		up_move(all);
	if (keycode == 125 || keycode == 1)
		down_move(all);
	if (keycode == 123 || keycode == 0)
		left_move(all);
	if (keycode == 124 || keycode == 2)
		right_move(all);
	if (keycode == 53)
		close_win(all);
	return (0);
}
