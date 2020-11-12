/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhames <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 21:17:48 by mokhames          #+#    #+#             */
/*   Updated: 2019/12/20 12:41:09 by mokhames         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <wchar.h>

typedef struct	s_struct
{
	int i;
	int len;
	int fd;
	int minus;
	int zero;
	int width;
	int precision_specified;
	int precision;
	int op;
	int	nash;
}				t_struct;
int				ft_putstr2(const char *s);
int				ft_printf(const char *format, ...);
void			ft_print_string(t_struct *f, va_list ap);
void			ft_print_decimal(t_struct *f, va_list ap);
int				ft_putstr3(const char *s, int a);
int				ft_num_of_digits(long value, int base);
int				ft_itoa_base(long value, int base);
int				ft_ultoa_base(char c, unsigned long long value, int base);
int				ft_ultoa_base2(char c, unsigned long long value, int base);
int				ft_uitoa_base(char c, unsigned int value, int base);
void			ft_edit_flags(const char *format, t_struct *f, va_list ap);
void			ft_check_format(const char *format, t_struct *f, va_list ap);
void			ft_padding_right_align(int nbrlen, int n, t_struct *f);
void			ft_padding_left_align(int nbrlen, t_struct *f);
void			ft_print_pointer(char c, t_struct *f, va_list ap);
void			ft_print_percent_sign(t_struct *f);
void			ft_print_char(t_struct *f, va_list ap);
void			ft_print_hex(char c, t_struct *f, va_list ap);
void			ft_print_unsigned_decimal(t_struct *f, va_list ap);
int				ft_hexa(unsigned int nb, int x, int base);

#endif
