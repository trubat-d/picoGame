/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 06:00:47 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 12:51:46 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printfd.h"

void	flags_text_fd(int fd, const char *str, int *i)
{
	while (str[*i] && ft_strchr("+/-_*[O0", str[*i]))
	{
		if (str[*i] == '+')
			ft_putstr_fd(fd, "\033[1m");
		else if (str[*i] == '/')
			ft_putstr_fd(fd, "\033[3m");
		else if (str[*i] == '-')
			ft_putstr_fd(fd, "\033[9m");
		else if (str[*i] == '_')
			ft_putstr_fd(fd, "\033[4m");
		else if (str[*i] == '[')
			ft_putstr_fd(fd, "\033[51m");
		else if (str[*i] == 'O')
			ft_putstr_fd(fd, "\033[52m");
		else if (str[*i] == '0')
			ft_putstr_fd(fd, "\033[0m");
		else if (str[*i] == '*')
			bright_fd(fd, str, i);
		if (str[*i] && ft_strchr("+/-_*[O0", str[*i]))
			*i += 1;
	}
}
