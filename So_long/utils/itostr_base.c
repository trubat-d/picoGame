/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itostr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:08:00 by hrolle            #+#    #+#             */
/*   Updated: 2022/08/23 23:05:35 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/so_long.h"

unsigned int	nbrlen_base(unsigned int n, unsigned int base)
{
	unsigned int	i;

	i = 1;
	while (n >= base)
	{
		n /= base;
		i++;
	}
	return (i);
}

void	putnbr_base_str(unsigned int n, char *str, unsigned int base, char *ret)
{
	if (n >= base)
		putnbr_base_str(n / base, str, base, ret - 1);
	*ret = str[n % base];
}

char	*itostr_base(unsigned int n, char *str, unsigned int base)
{
	unsigned int	len;
	char			*ret;

	len = nbrlen_base(n, base);
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[len] = 0;
	putnbr_base_str(n, str, base, ret + (len - 1));
	return (ret);
}
