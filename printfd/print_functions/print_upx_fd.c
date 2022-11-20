/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_upx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:19:08 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 11:02:32 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printfd.h"

void	fd_repeat_putc_for_upx(int fd, t_flags *flags, int c)
{
	if (flags->len > flags->upx
		|| (flags->point > flags->upx && flags->len > flags->point))
	{
		if (flags->point > flags->upx)
			repeat_putchar_fd(fd, c, flags->len - flags->point);
		else
			repeat_putchar_fd(fd, c, flags->len - flags->upx);
	}
}

int	print_upx_fd(int fd, t_flags *flags, unsigned long int upx)
{
	int	c;

	flags->upx = u_nbrlen_base(upx, 16, flags);
	if (!flags->zero || flags->point || !flags->upx)
		c = ' ';
	else
		c = '0';
	if (!flags->min && (!flags->zero || flags->point))
		fd_repeat_putc_for_upx(fd, flags, c);
	if (upx > 0 && flags->sharp)
		ft_putstr_fd(fd, "0X");
	if (!flags->min && flags->zero && !flags->point)
		fd_repeat_putc_for_upx(fd, flags, c);
	if (flags->point > flags->upx)
		repeat_putchar_fd(fd, '0', flags->point - flags->upx);
	if (flags->upx)
		ft_putnbrb_fd(fd, upx, "0123456789ABCDEF", 16);
	if (flags->min)
		fd_repeat_putc_for_upx(fd, flags, ' ');
	if (flags->len > flags->upx && flags->len > flags->point)
		return (flags->len);
	else if (flags->point > flags->upx)
		return (flags->point);
	return (flags->upx);
}
