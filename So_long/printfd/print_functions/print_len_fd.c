/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_len_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:47:58 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 10:55:34 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printfd.h"

int	print_len_fd(int fd, t_flags *flags, int c)
{
	if (!flags->len)
		return (write(fd, &c, 1));
	if (flags->min)
		ft_putchar_fd(fd, c);
	if (flags->zero && !flags->min)
		repeat_putchar_fd(fd, '0', flags->len - 1);
	else
		repeat_putchar_fd(fd, ' ', flags->len - 1);
	if (!flags->min)
		ft_putchar_fd(fd, c);
	return (flags->len);
}
