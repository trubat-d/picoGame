/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 12:59:33 by hrolle            #+#    #+#             */
/*   Updated: 2022/06/16 12:52:33 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFD_H
# define FT_PRINTFD_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct S_t_flags
{
	unsigned int	c;
	unsigned int	s;
	unsigned int	d;
	unsigned int	u;
	unsigned int	x;
	unsigned int	p;
	unsigned int	o;
	unsigned int	upx;
	unsigned int	pourcent;
	unsigned int	min;
	unsigned int	zero;
	unsigned int	plus;
	unsigned int	point;
	unsigned int	zpoint;
	unsigned int	sharp;
	unsigned int	sp;
	unsigned int	len;
}					t_flags;

void	flags_set(t_flags *flags);
void	value_check(const char *str, t_flags *flags, int *i);
int		flags_check_fd(int fd, const char *str, va_list args, int *i);
char	*ft_strchr(const char *s, int c);
void	ft_strcpy(char *dst, const char *src);

size_t	ft_strlen(const char *s);
int		nbrlen(long int nbr, unsigned int base, t_flags *flags);
int		cmpt_nbr_c(unsigned int nbr, unsigned int base, unsigned int i);
int		u_nbrlen_base(unsigned long nbr, unsigned long base, t_flags *flags);
int		flag_s_len(char *s, t_flags *flags);
int		len_atoi(const char *str, int *i);

void	ft_putstr_fd(int fd, char *s);
void	ft_putlstr_fd(int fd, char *s, int len);
void	rec_putnbr_fd(int fd, unsigned int n);
void	ft_putnbr_fd(int fd, int n);
void	ft_putnbrb_fd(int fd, unsigned long n, char *str, unsigned long base);
void	ft_putchar_fd(int fd, char c);
void	repeat_putchar_fd(int fd, char c, int len);
void	fd_repeat_putc_for_u(int fd, t_flags *flags, int c);
void	fd_repeat_putc_for_o(int fd, t_flags *flags, int c);
void	fd_repeat_putc_for_x(int fd, t_flags *flags, int c);
void	fd_repeat_putc_for_upx(int fd, t_flags *flags, int c);
void	fd_repeat_putc_for_d(int fd, t_flags *flags, int c);
void	put_sign_fd(int fd, t_flags *flags, int d);

int		print_c_fd(int fd, t_flags *flags, int c);
int		print_s_fd(int fd, t_flags *flags, char *s);
int		print_d_fd(int fd, t_flags *flags, int d);
int		print_u_fd(int fd, t_flags *flags, unsigned int u);
int		print_x_fd(int fd, t_flags *flags, unsigned long int x);
int		print_upx_fd(int fd, t_flags *flags, unsigned long int upx);
int		print_o_fd(int fd, t_flags *flags, unsigned int o);
int		print_len_fd(int fd, t_flags *flags, int c);

int		text_mod_fd(int fd, const char *str, int *i);
void	color_fd(int fd, const char *str, int *i);
void	backround_fd(int fd, const char *str, int *i);
void	flags_text_fd(int fd, const char *str, int *i);
void	bright_fd(int fd, const char *str, int *i);
void	bt_backround_fd(int fd, const char *str, int *i);

int		ft_printfd(int fd, const char *str, ...);

#endif
