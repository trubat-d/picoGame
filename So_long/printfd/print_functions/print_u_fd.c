/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:18:44 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 11:01:07 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printfd.h"

void	fd_repeat_putc_for_u(int fd, t_flags *flags, int c)
{
	if (flags->len > flags->u
		|| (flags->point > flags->u && flags->len > flags->point))
	{
		if (flags->point > flags->u)
			repeat_putchar_fd(fd, c, flags->len - flags->point);
		else
			repeat_putchar_fd(fd, c, flags->len - flags->u);
	}
}

int	print_u_fd(int fd, t_flags *flags, unsigned int u)
{
	int	c;

	flags->u = u_nbrlen_base(u, 10, flags);
	if (!flags->zero || flags->point || !flags->u)
		c = ' ';
	else
		c = '0';
	if (!flags->min)
		fd_repeat_putc_for_u(fd, flags, c);
	if (flags->point > flags->u)
		repeat_putchar_fd(fd, '0', flags->point - flags->u);
	if (flags->u)
		ft_putnbrb_fd(fd, u, "0123456789", 10);
	if (flags->min)
		fd_repeat_putc_for_u(fd, flags, ' ');
	if (flags->len > flags->u && flags->len > flags->point)
		return (flags->len);
	else if (flags->point > flags->u)
		return (flags->point);
	return (flags->u);
}
