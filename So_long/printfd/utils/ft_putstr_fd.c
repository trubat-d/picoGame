/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:15:52 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 12:21:54 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printfd.h"

void	ft_putstr_fd(int fd, char *s)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

void	ft_putlstr_fd(int fd, char *s, int len)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (i < len)
		write(fd, s + i++, 1);
}
