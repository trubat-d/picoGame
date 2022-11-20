/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:15:00 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 10:43:13 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printfd.h"

void	rec_putnbr_fd(int fd, unsigned int n)
{
	unsigned int	nb;

	nb = n;
	if (n > 9)
		rec_putnbr_fd(fd, n / 10);
	ft_putchar_fd(fd, nb % 10 + '0');
}

void	ft_putnbr_fd(int fd, int n)
{
	int	pn;

	pn = 1;
	if (n < 0)
		pn *= -1;
	rec_putnbr_fd(fd, n * pn);
}
