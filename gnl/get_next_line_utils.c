/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 03:18:30 by hrolle            #+#    #+#             */
/*   Updated: 2022/11/20 09:06:45 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

int	ft_strlenl(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	//if (s[i] == '\n')
	//	i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (s);
}

char	*ft_strdupjoin(char *s1, char *s2)
{
	char	*ret;
	char	*tmp;

	ret = malloc((ft_strlenl(s1) + ft_strlenl(s2) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	tmp = ret;
	if (s1)
		while (*s1)
			*(ret++) = *(s1++);
	if (s2)
	{
		while (*s2 && *s2 != '\n')
			*(ret++) = *(s2++);
		//if (*s2 == '\n')
		//	*(ret++) = *s2;
	}
	*ret = 0;
	return (tmp);
}
