/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:14:45 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 10:44:45 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printfd.h"

void	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

void	repeat_putchar_fd(int fd, char c, int len)
{
	while (len > 0)
	{
		ft_putchar_fd(fd, c);
		len--;
	}
}
