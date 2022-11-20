/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_nbrlen_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:19:58 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 11:16:25 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printfd.h"

int	u_nbrlen_base(unsigned long nbr, unsigned long base, t_flags *flags)
{
	unsigned int	i;

	i = 0;
	if (flags->zpoint && !nbr)
		return (0);
	if ((flags->sharp && nbr > 0 && base > 10) || flags->p)
	{
		if (flags->point)
			flags->point += 2;
		i += 2;
	}
	else if (flags->sharp && nbr > 0 && base < 10)
		i++;
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i + 1);
}
