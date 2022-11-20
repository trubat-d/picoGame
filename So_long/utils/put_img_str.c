/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 03:10:42 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/23 23:12:46 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"

int	put_img_str(t_all *all, char *str, int x, int y)
{
	void	*img;
	int		i[2];

	img = mlx_xpm_file_to_image(all->mlx, str, i, i + 1);
	if (!img)
		return (1);
	mlx_put_image_to_window(all->mlx, all->window, img, x, y);
	mlx_destroy_image(all->mlx, img);
	return (0);
}
