/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:17:32 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 11:05:09 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printfd.h"

void	fd_repeat_putc_for_d(int fd, t_flags *flags, int c)
{
	if (flags->len > flags->d
		|| (flags->point > flags->d && flags->len > flags->point))
	{
		if (flags->point > flags->d)
			repeat_putchar_fd(fd, c, flags->len - flags->point);
		else
			repeat_putchar_fd(fd, c, flags->len - flags->d);
	}
}

void	put_sign_fd(int fd, t_flags *flags, int d)
{
	if (d >= 0 && flags->plus)
		ft_putchar_fd(fd, '+');
	else if (d >= 0 && flags->sp)
		ft_putchar_fd(fd, ' ');
	else if (d < 0)
		ft_putchar_fd(fd, '-');
}

int	print_d_fd(int fd, t_flags *flags, int d)
{
	int	c;

	flags->d = nbrlen(d, 10, flags);
	if (!flags->zero || flags->point || !flags->d)
		c = ' ';
	else
		c = '0';
	if (!flags->min && (!flags->zero || flags->point))
		fd_repeat_putc_for_d(fd, flags, c);
	put_sign_fd(fd, flags, d);
	if (!flags->min && (flags->zero && !flags->point))
		fd_repeat_putc_for_d(fd, flags, c);
	if (flags->point > flags->d)
		repeat_putchar_fd(fd, '0', flags->point - flags->d);
	if (flags->d)
		ft_putnbr_fd(fd, d);
	if (flags->min)
		fd_repeat_putc_for_d(fd, flags, ' ');
	if (flags->len > flags->d && flags->len > flags->point)
		return (flags->len);
	else if (flags->point > flags->d)
		return (flags->point);
	return (flags->d);
}
