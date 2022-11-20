/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:58:44 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/30 17:46:41 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"
#include "../HEADER/get_next_line.h"
#include "../printfd/HEADER/ft_printfd.h"

char	**ft_strsjoin(char **strs, char *line)
{
	char			**ret;
	unsigned int	i;

	i = 0;
	while (strs[i])
		i++;
	ret = malloc((i + 2) * sizeof(char *));
	if (!ret)
		return (NULL);
	i = -1;
	while (strs[++i])
		ret[i] = strs[i];
	ret[i] = line;
	ret[i + 1] = NULL;
	return (ret);
}

int	read_map(t_all *all)
{
	char	*line;
	char	**tmp;

	all->map = malloc(2 * sizeof(char *));
	if (!all->map)
		return (1);
	all->map[0] = get_next_line(all->fd);
	if (!all->map[0])
	{
		ft_printfd(2, "Error\nMap vide\n");
		return (1);
	}
	all->map[1] = NULL;
	while (1)
	{
		line = get_next_line(all->fd);
		if (!line)
			break ;
		tmp = all->map;
		all->map = ft_strsjoin(tmp, line);
		free(tmp);
		if (!all->map)
			return (1);
	}
	return (0);
}
