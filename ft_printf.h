/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:06:28 by ssar              #+#    #+#             */
/*   Updated: 2022/10/04 12:07:45 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_flag
{
	int pad_zero;
	int to_left;
	int larg_min;
	int precision;
	int isprecision;
	int c_is_zero;
}				t_flag;
int				ft_is_in(char *base, char c);
int				ft_printf(const char *str, ...);
void			ft_put_percent(const char *str, size_t *i, size_t *l);
void			ft_def_conv(const char *str, size_t *i, va_list ap, size_t *l);
char			*ft_itoa_base(long long n, char *base_to, int excep);
void			ft_init_exception(int excep, char *tab, int *len);
int				ft_size_of_conv(long long n, char *base_to);
void			ft_fill_tab(long long n, char *base_to, char *tab, int len);
int				ft_show(char *str, t_flag *stock);
int				ft_len(char *str);
void			ft_char_to_str(unsigned char c, char **p, t_flag *stock);
void			ft_conv_nbr(va_list cpy, const char *str, char **p, int i);
t_flag			ft_init_flag(const char *str, va_list cpy, t_flag stock);
int				ft_next(const char *str);
char			*ft_treat_flag(char *p, t_flag flag, char c);
void			ft_treat_pad_zero(char **tab);
void			ft_treat_to_left(char **tab);
char			*ft_treat_larg_min(char *tab, int larg_min);
char			*ft_treat_prec_nb(char *tab, int precision);
char			*ft_treat_prec_s(char *tab, int precision);
int				ft_cmp(char *s1, char *s2);
t_flag			ft_default_flag(void);
char			*ft_free_tab(char *tab);
int				ft_len_nb(char *tab);
char			*ft_dup2(char *s);

#endif
