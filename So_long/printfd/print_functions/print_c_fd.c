/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:17:11 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 12:22:23 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printfd.h"

int	print_c_fd(int fd, t_flags *flags, int c)
{
	flags->c = 1;
	if (!flags->min && flags->len > flags->c)
	{
		if (flags->zero)
			repeat_putchar_fd(fd, '0', flags->len - flags->c);
		else
			repeat_putchar_fd(fd, ' ', flags->len - flags->c);
	}
	ft_putchar_fd(fd, c);
	if (flags->min && flags->len > flags->c)
		repeat_putchar_fd(fd, ' ', flags->len - flags->c);
	if (flags->len <= flags->c)
		return (flags->c);
	return (flags->len);
}
