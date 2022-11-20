/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bright.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 06:00:34 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 12:50:16 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printfd.h"

void	bt_backround_fd(int fd, const char *str, int *i)
{
	if (str[*i] == 'K')
		ft_putstr_fd(fd, "\033[100m");
	else if (str[*i] == 'R')
		ft_putstr_fd(fd, "\033[101m");
	else if (str[*i] == 'G')
		ft_putstr_fd(fd, "\033[102m");
	else if (str[*i] == 'Y')
		ft_putstr_fd(fd, "\033[103m");
	else if (str[*i] == 'B')
		ft_putstr_fd(fd, "\033[104m");
	else if (str[*i] == 'P')
		ft_putstr_fd(fd, "\033[105m");
	else if (str[*i] == 'C')
		ft_putstr_fd(fd, "\033[106m");
	else if (str[*i] == 'W')
		ft_putstr_fd(fd, "\033[107m");
}

void	bright_fd(int fd, const char *str, int *i)
{
	*i += 1;
	if (str[*i] == 'k')
		ft_putstr_fd(fd, "\033[90m");
	else if (str[*i] == 'r')
		ft_putstr_fd(fd, "\033[91m");
	else if (str[*i] == 'g')
		ft_putstr_fd(fd, "\033[92m");
	else if (str[*i] == 'y')
		ft_putstr_fd(fd, "\033[93m");
	else if (str[*i] == 'b')
		ft_putstr_fd(fd, "\033[94m");
	else if (str[*i] == 'p')
		ft_putstr_fd(fd, "\033[95m");
	else if (str[*i] == 'c')
		ft_putstr_fd(fd, "\033[96m");
	else if (str[*i] == 'w')
		ft_putstr_fd(fd, "\033[97m");
	if (str[*i] && ft_strchr("krgybpcw", str[*i]))
		*i += 1;
	else if (str[*i] && ft_strchr("KRGYBPCW", str[*i]))
	{
		bt_backround_fd(fd, str, i);
		*i += 1;
	}
}
