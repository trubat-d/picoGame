/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:15:16 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 10:39:15 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printfd.h"

void	ft_putnbrb_fd(int fd, unsigned long n, char *str, unsigned long base)
{
	unsigned int	nb;

	nb = n;
	if (n >= base)
		ft_putnbrb_fd(fd, n / base, str, base);
	ft_putchar_fd(fd, str[nb % base]);
}
