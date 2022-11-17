/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:31:59 by kdhrif            #+#    #+#             */
/*   Updated: 2022/10/30 16:39:24 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define UINT_MAX 4294967295
# define UINT_MIN 0
# define LONG_MAX 9223372036854775807
# define LONG_MIN -9223372036854775808
# define ULONG_MAX 18446744073709551615
# define ULONG_MIN 0
# define LLONG_MAX 9223372036854775807
# define LLONG_MIN -9223372036854775808
# define ULLONG_MAX 18446744073709551615
# define ULLONG_MIN 0
# define CHAR_MAX 255
# define CHAR_MIN 0
# define UCHAR_MAX 255
# define UCHAR_MIN 0
# define SHORT_MAX 32767
# define SHORT_MIN -32768
# define USHORT_MAX 65535
# define USHORT_MIN 0

typedef struct s_struct
{
	va_list	args;
	int		maxwidth;
	int		minwidth;
	int		precision;
	int		zero;
	int		pnt;
	int		dash;
	int		tl;
	int		sign;
	int		is_neg;
	int		is_ptr;
	int		already_neg;
	int		is_zero;
	int		upper;
	int		space_flag;
	int		hash;

}			t_print;

void		ft_print_char(t_print *tab);
void		ft_printint_checker(t_print *tab, int *nb, int *len);
void		choose_conversion(t_print *tab, const char *format, int i);
void		ft_bzero(char *s, size_t n);
void		*ft_memset(char *s, int c, size_t n);
void		ft_strwidth(t_print *tab, int max);
void		ft_printstr(t_print *tab);
void		ft_print_integer(t_print *tab);
void		ft_print_int_right(t_print *tab, int nb, int len);
void		ft_print_int_left(t_print *tab, int nb, int len);
void		ft_putnbr(int nb, t_print *tab);
void		ft_print_ptr(t_print *tab);
void		ft_putnbr_hex(unsigned long long n, t_print *tab);
void		ft_print_hex_left(t_print *tab, int len, unsigned long long nb);
void		ft_print_hex_right(t_print *tab, int len, unsigned long long nb);
void		ft_print_uint(t_print *tab);
void		ft_print_uint_right(t_print *tab, unsigned int nb, int len);
void		ft_print_uint_left(t_print *tab, unsigned int nb, int len);
void		ft_putunbr(unsigned int nb, t_print *tab);
void		ft_print_hex(t_print *tab);
void		ft_print_percent(t_print *tab);
void		ft_strcpy(char *dst, const char *src, int n);
void		ft_reset_str(t_print *tab);
void		ft_printstr_right(t_print *tab, char *str, int len);
void		ft_printstr_left(t_print *tab, char *str, int len);
void		ft_printint_zero(t_print *tab, int nb, int len);
void		ft_print_ptr_right(t_print *tab, int len, unsigned long long ptr);
void		ft_print_ptr_left(t_print *tab, int len, unsigned long long ptr);
void		ft_printhex_zero(t_print *tab);
void		ft_printint_norm(t_print *tab);
void		ft_printflags(t_print *tab, int nb);
void		ft_print_maxwidth(t_print *tab, int len, char opt);
void		ft_print_minwidth(t_print *tab, int len);
void		ft_print_maxwidthmin(t_print *tab);
void		ft_printhex_flags(t_print *tab, int nb);
void		ft_printhex_hash(t_print *tab);
void		ft_printhex_checker(t_print *tab, int nb);
void		ft_printhex_flagsplusminwidth(t_print *tab, int nb, int len);
void		ft_printint_flagsplusminwidth(t_print *tab, int nb, int len);
void		ft_printptr_nil(t_print *tab);
void		ft_printstr_putstrwidth(t_print *tab, char *str, int len);

int			ft_print_nullstr(t_print *tab);
int			ft_uintlen(unsigned int nb);
int			ft_hexlen(unsigned long long n);
int			ft_printf(const char *format, ...);
int			ft_eval_format(t_print *tab, const char *format, int i);
int			check_flags(char c);
int			ft_putstr(char *s);
int			ft_putchar(char c);
int			ft_isnum(char c);
int			ft_atoi(const char *nptr);
int			ft_strlen(char *s);
int			ft_intlen(int nb);
int			ft_print_spaces(t_print *tab);
int			ft_print_zero(t_print *tab);
int			ft_print_minus(t_print *tab);
int			ft_print_plus(t_print *tab);
int			ft_print_spaceflag(t_print *tab);
int			ft_printf_checkflags(t_print *tab, int i, const char *format);
int			ft_printf_checkflagint(t_print *tab, int i, char *nb,
				const char *format);
int			ft_printf_checkflagint2(t_print *tab, int i, char *nb,
				const char *format);
int			ft_checkflags_zero(const char *format, int i);

char		*ft_strnew(size_t size);

#endif
