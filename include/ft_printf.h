/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 01:45:52 by ddevico           #+#    #+#             */
/*   Updated: 2015/12/21 21:11:00 by ddevico          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include "libft.h"
# define NUM "0123456789"

typedef struct		s_flags
{
	int				minus;
	int				plus;
	int				plushere;
	int				space;
	int				zero;
	int				hashtag;
	int				nbhashtag;
	int				number;
	int				numbertwo;
	int				numberzero;
	int				nbarg;
	int				point;
	int				length;
	char			option;
	int				count;
	int				good;
}					t_flags;

int					ft_printf(char const *str, ...);

int					ft_printnbr(va_list ap, t_flags *flag);
int					ft_printlnbr(va_list ap, t_flags *flag);
int					ft_printchar(va_list ap, t_flags *flag);
int					ft_printstr(va_list ap, t_flags *flag);
int					ft_printwstr(va_list ap, t_flags *flag);
int					ft_printwchar(va_list ap, t_flags *flag);
int					ft_printunsigned(va_list ap, t_flags *flag);
int					ft_printlong(va_list ap, t_flags *flag);
int					ft_printhexa(va_list ap, int i, t_flags *flag);
int					ft_printvoid(va_list ap, t_flags *flag);
int					ft_printoct(va_list ap, t_flags *flag);
int					ft_printloct(va_list ap, t_flags *flag);
int					ft_printpourcent(char c, t_flags *flag);

int					ft_putzero(t_flags *flag, char *p, int nb);
int					ft_putminus(t_flags *flag, char *p, int nb, int ok);
int					ft_putplus(t_flags *flag, char *p);
int					ft_putspace(t_flags *flag, char *p);
int					ft_puthashtag(t_flags *flag, char *p, int nb, int i);

int					ft_putminus_special(t_flags *flag, int count, int ok,
										char *p);
int					ft_putplus_special(t_flags *flag, char *p);
int					ft_putzero_special(t_flags *flag, int count, int ok);
char				*ft_putpoint_special(t_flags *flag, char *p);
int					ft_putzero_special_str(t_flags *flag, char *p);

int					ft_put_special_space(t_flags *flag, char *p);
int					ft_put_special_space_wstr(t_flags *flag, int count);
int					ft_put_special_space_str(t_flags *flag, char *p);
int					ft_put_special_space_hashtag(t_flags *flag, char *p,
												int nb);
int					ft_put_special_flag_zero(t_flags *flag, int len, int ok,
											char *p);

int					ft_putchar_printf(char c);
int					ft_put_w(wint_t c, int ok, t_flags *flag);
int					ft_put_w_point(wint_t c, int ok, t_flags *flag);
char				*ft_itoa_printf(long int n);
char				*ft_itoalong(intmax_t n);
void				ft_putstr(char const *str);
size_t				ft_strlen(const char *str);
size_t				ft_wstrlen(wchar_t *str);
char				*ft_strdup(const char *s1);
char				*ft_utoa(unsigned int nb);
char				*ft_utoa_long(uintmax_t nb);
char				*ft_hexatoa(unsigned int n);
char				*ft_hexatoalong(uintmax_t n);
char				*ft_octtoa(uintmax_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_toupper_printf(char *str);

t_flags				*ft_new_flags(void);
const char			*ft_findflag(const char *str, t_flags *flag);
const char			*ft_checknumber(const char *str, t_flags *flag);
const char			*ft_checknumberzero(const char *str, t_flags *flag);
const char			*ft_checkspace(const char *str);
int					ft_countnumber(const char *str);

intmax_t			ft_printf_get_signed_from_length(va_list ap, t_flags *flag);
uintmax_t			ft_printf_get_unsigned_from_length(va_list ap, t_flags
														*flag);
int					ft_while_putzero(t_flags *flag, int len, int i, int plus);
void				ft_putwchar(void *mem, int size);

#endif
