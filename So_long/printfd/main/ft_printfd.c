/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:10:08 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 12:54:46 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printfd.h"

int	ft_printfd(int fd, const char *str, ...)
{
	va_list	args;
	int		i;
	int		cmpt;

	if (!str || fd < 0)
		return (0);
	va_start(args, str);
	i = 0;
	cmpt = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			cmpt += flags_check_fd(fd, str, args, &i);
			if (str[i])
				i++;
		}
		else if (str[i] == '#')
			cmpt += text_mod_fd(fd, str, &i);
		else if (str[i])
			cmpt += write(fd, &str[i++], 1);
	}
	va_end(args);
	return (cmpt);
}
