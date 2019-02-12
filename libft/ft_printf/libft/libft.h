/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 11:44:54 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 11:30:08 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include <wchar.h>
# include "../ft_printf.h"

typedef struct s_printf	t_printf;

int				ft_strlen_unsigned(uintmax_t nb, int base);
int				*ft_strlen_float_unsigned(long double nb, int *tab, int max);
void			ft_putnbr_unsigned_base(uintmax_t nb, char *base,
					unsigned int size, t_printf *str);
size_t			ft_strlen(const char *s);
size_t			ft_strlen_unicode(const wchar_t *str, int precision);
void			ft_putchar(char c, t_printf *str);
void			ft_putstr(char *str, t_printf *s);
void			ft_putchar_unicode(wchar_t c, t_printf *str);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strcpy(char *dest, const char *src);

#endif
