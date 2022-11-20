/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 03:17:02 by hrolle            #+#    #+#             */
/*   Updated: 2022/11/20 09:05:12 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10
# include "PicoShell.h"

typedef struct S_rest
{
	char	*root;
	char	*seek;
}			t_rest;

int		ft_strlenl(char *s);
char	*ft_strdupjoin(char *s1, char *s2);
void	init_root(t_rest *line);
void	no_nl(t_rest *line, char **ret, char *nl);
char	*yes_nl(t_rest *line, char *ret, char *nl);
int		read_line(t_rest *line, int fd);
char	*get_next_line(int fd);
char	*ft_strchr_gnl(char *s, char c);

#endif