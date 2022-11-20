/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 04:58:53 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 12:54:07 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printfd.h"

void	backround_fd(int fd, const char *str, int *i)
{
	if (str[*i] == 'K')
		ft_putstr_fd(fd, "\033[40m");
	else if (str[*i] == 'R')
		ft_putstr_fd(fd, "\033[41m");
	else if (str[*i] == 'G')
		ft_putstr_fd(fd, "\033[42m");
	else if (str[*i] == 'Y')
		ft_putstr_fd(fd, "\033[43m");
	else if (str[*i] == 'B')
		ft_putstr_fd(fd, "\033[44m");
	else if (str[*i] == 'P')
		ft_putstr_fd(fd, "\033[45m");
	else if (str[*i] == 'C')
		ft_putstr_fd(fd, "\033[46m");
	else if (str[*i] == 'W')
		ft_putstr_fd(fd, "\033[47m");
}

void	color_fd(int fd, const char *str, int *i)
{
	if (str[*i] == 'k')
		ft_putstr_fd(fd, "\033[30m");
	else if (str[*i] == 'r')
		ft_putstr_fd(fd, "\033[31m");
	else if (str[*i] == 'g')
		ft_putstr_fd(fd, "\033[32m");
	else if (str[*i] == 'y')
		ft_putstr_fd(fd, "\033[33m");
	else if (str[*i] == 'b')
		ft_putstr_fd(fd, "\033[34m");
	else if (str[*i] == 'p')
		ft_putstr_fd(fd, "\033[35m");
	else if (str[*i] == 'c')
		ft_putstr_fd(fd, "\033[36m");
	else if (str[*i] == 'w')
		ft_putstr_fd(fd, "\033[37m");
}

int	text_mod_fd(int fd, const char *str, int *i)
{
	*i += 1;
	if (str[*i] == '#')
	{
		ft_putchar_fd(fd, '#');
		*i += 1;
		return (1);
	}
	if (str[*i] && ft_strchr("+/-_*[O0", str[*i]))
		flags_text_fd(fd, str, i);
	if (str[*i] && ft_strchr("krgybpcw", str[*i]))
	{
		color_fd(fd, str, i);
		*i += 1;
	}
	else if (str[*i] && ft_strchr("KRGYBPCW", str[*i]))
	{
		backround_fd(fd, str, i);
		*i += 1;
	}
	return (0);
}
