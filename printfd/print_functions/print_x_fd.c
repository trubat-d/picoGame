/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:19:29 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 11:04:34 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printfd.h"

void	fd_repeat_putc_for_x(int fd, t_flags *flags, int c)
{
	if (flags->len > flags->x
		|| (flags->point > flags->x && flags->len > flags->point))
	{
		if (flags->point > flags->x)
			repeat_putchar_fd(fd, c, flags->len - flags->point);
		else
			repeat_putchar_fd(fd, c, flags->len - flags->x);
	}
}

int	print_x_fd(int fd, t_flags *flags, unsigned long int x)
{
	int	c;

	flags->x = u_nbrlen_base(x, 16, flags);
	if (!flags->zero || flags->point || !flags->x)
		c = ' ';
	else
		c = '0';
	if (!flags->min && (!flags->zero || flags->point))
		fd_repeat_putc_for_x(fd, flags, c);
	if ((x > 0 && flags->sharp) || flags->p)
		ft_putstr_fd(fd, "0x");
	if (!flags->min && flags->zero && !flags->point)
		fd_repeat_putc_for_x(fd, flags, c);
	if (flags->point > flags->x)
		repeat_putchar_fd(fd, '0', flags->point - flags->x);
	if (flags->x)
		ft_putnbrb_fd(fd, x, "0123456789abcdef", 16);
	if (flags->min)
		fd_repeat_putc_for_x(fd, flags, ' ');
	if (flags->len > flags->x && flags->len > flags->point)
		return (flags->len);
	else if (flags->point > flags->x)
		return (flags->point);
	return (flags->x);
}
