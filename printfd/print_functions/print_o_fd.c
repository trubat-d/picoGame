/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:18:11 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 10:58:11 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printfd.h"

void	fd_repeat_putc_for_o(int fd, t_flags *flags, int c)
{
	if (flags->len > flags->o
		|| (flags->point > flags->o && flags->len > flags->point))
	{
		if (flags->point > flags->o)
			repeat_putchar_fd(fd, c, flags->len - flags->point);
		else
			repeat_putchar_fd(fd, c, flags->len - flags->o);
	}
}

int	print_o_fd(int fd, t_flags *flags, unsigned int o)
{
	int	c;

	flags->o = u_nbrlen_base(o, 8, flags);
	if (!flags->zero || flags->point || !flags->o)
		c = ' ';
	else
		c = '0';
	if (!flags->min && (!flags->zero || flags->point))
		fd_repeat_putc_for_o(fd, flags, c);
	if (o > 0 && flags->sharp)
		ft_putchar_fd(fd, '0');
	if (!flags->min && flags->zero && !flags->point)
		fd_repeat_putc_for_o(fd, flags, c);
	if (flags->point > flags->o)
		repeat_putchar_fd(fd, '0', flags->point - flags->o);
	if (flags->o)
		ft_putnbrb_fd(fd, o, "01234567", 8);
	if (flags->min)
		fd_repeat_putc_for_o(fd, flags, ' ');
	if (flags->len > flags->o && flags->len > flags->point)
		return (flags->len);
	else if (flags->point > flags->o)
		return (flags->point);
	return (flags->o);
}
