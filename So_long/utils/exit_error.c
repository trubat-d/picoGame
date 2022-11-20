/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 06:37:32 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/23 23:05:16 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"
#include "../printfd/HEADER/ft_printfd.h"

void	exit_error(t_all *all, char *str, int errnum)
{
	int	i;

	i = 0;
	ft_printfd(2, str);
	if (all->enemy)
		free(all->enemy);
	while (all->map[i])
		free(all->map[i++]);
	free(all->map);
	exit(errnum);
}
