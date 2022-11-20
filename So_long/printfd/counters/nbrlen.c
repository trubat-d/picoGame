/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:16:51 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 11:16:21 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ft_printfd.h"

int	cmpt_nbr_c(unsigned int nbr, unsigned int base, unsigned int i)
{
	while (nbr >= base)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

int	nbrlen(long int nbr, unsigned int base, t_flags *flags)
{
	unsigned int	i;
	unsigned int	nbrb;

	i = 0;
	if (flags->zpoint && !nbr)
		return (0);
	if (nbr < 0)
	{
		nbrb = nbr * -1;
		i++;
		if (flags->point)
			flags->point += 1;
	}
	else
	{
		nbrb = (unsigned long )nbr;
		if (flags->sp || flags->plus)
		{
			i++;
			if (flags->point)
				flags->point += 1;
		}
	}
	return (cmpt_nbr_c(nbrb, base, i) + 1);
}
