/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:58:50 by hrolle            #+#    #+#             */
/*   Updated: 2022/11/20 15:01:17 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"
#include "../printfd/HEADER/ft_printfd.h"

void	print_tabs(char **strs)
{
	while (*strs)
		ft_printfd(1, "%s", *(strs++));
}

int	animation(t_all *all)
{
	unsigned int		i;
	unsigned long int	modulo;

	i = 0;
	if (all->aleatory++ == 4294967295)
		all->aleatory = 0;
	if (all->frame++ < 3800)
		return (0);
	while (all->enemy[i].x || all->enemy[i].y)
	{
		modulo = (all->enemy[i].x
				+ all->enemy[i].y + all->aleatory + all->move) % 4;
		if (modulo == 0)
			right_enemy(all, i);
		else if (modulo == 1)
			down_enemy(all, i);
		else if (modulo == 2)
			up_enemy(all, i);
		else if (modulo == 3)
			left_enemy(all, i);
		i++;
	}
	all->frame = 0;
	return (0);
}

int	check_map_ext(char *map, char *ext)
{
	unsigned int	i;

	while (*map)
	{
		while (*map && *map != '.')
			map++;
		i = 0;
		while (*map && ext[i] && *map == ext[i])
		{
			map++;
			i++;
		}
		if (*map)
			i = 0;
		while (*map && *map != '.')
			map++;
		if (*map != '.')
			break ;
	}
	if (ext[i])
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_all	all;

	if (ac < 2)
		return (1);
	if (check_map_ext(av[1], ".ber"))
	{
		ft_printfd(2, "Error\nExtension invalide\n");
		return (1);
	}
	all.fd = open(av[1], O_RDONLY);
	if (all.fd == -1)
	{
		ft_printfd(2, "Error\nLe fichier ne s'est pas ouvert\n");
		return (1);
	}
	if (set_all(&all))
		return (1);
	mlx_key_hook(all.window, &key_event, &all);
	mlx_hook(all.window, 17, 0, &close_win, &all);
	mlx_loop_hook(all.mlx, &animation, &all);
	mlx_loop(all.mlx);
	return (1);
}
