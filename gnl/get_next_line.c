/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 03:16:52 by hrolle            #+#    #+#             */
/*   Updated: 2022/11/20 08:59:35 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

void	init_root(t_rest *line)
{
	line->root = malloc((BUFFER_SIZE + 1) * sizeof(char));
	line->root[0] = 0;
	line->seek = line->root;
}

void	no_nl(t_rest *line, char **ret, char *nl)
{
	char	*tmp;

	tmp = *ret;
	*ret = ft_strdupjoin(tmp, line->seek);
	if (tmp)
		free(tmp);
	line->seek = nl;
}

char	*yes_nl(t_rest *line, char *ret, char *nl)
{
	char	*tmp;

	tmp = ret;
	ret = ft_strdupjoin(tmp, line->seek);
	if (tmp)
		free(tmp);
	line->seek = nl + 1;
	return (ret);
}

int	read_line(t_rest *line, int fd)
{
	int	rd;

	line->seek = line->root;
	rd = read(fd, line->root, BUFFER_SIZE);
	if (rd < 1)
	{
		free(line->root);
		line->root = NULL;
		line->seek = NULL;
		return (0);
	}
	line->root[rd] = 0;
	return (1);
}

char	*get_next_line(int fd)
{
	static t_rest	line;
	char			*ret;
	char			*nl;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!line.root)
		init_root(&line);
	if (!line.root)
		return (NULL);
	ret = NULL;
	while (1)
	{
		if (!line.seek[0])
			if (!read_line(&line, fd))
				return (ret);
		nl = ft_strchr_gnl(line.seek, '\n');
		if (*nl != '\n')
			no_nl(&line, &ret, nl);
		else
			return (yes_nl(&line, ret, nl));
		if (!ret)
			return (NULL);
	}
	return (ret);
}

// int	main(int ac, char **av)
// {
// 	int		fd;
// 	int		r;
// 	char	*line;

// 	if (ac != 3)
// 		return (1);
// 	fd = open(av[1], O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("file not found\n");
// 		return (1);
// 	}
// 	r = atoi(av[2]);
// 	for (int i = 0; i < r; i++)
// 	{
// 		line = gnl(fd);
// 		printf("%s", line);
// 		if (line)
// 			free(line);
// 	}
// 	return (0);
// }
