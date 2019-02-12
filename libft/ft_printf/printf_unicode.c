/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_unicode.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 11:52:36 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 11:53:30 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_string_unicode(t_printf *str)
{
	wchar_t	*s;
	int		length;
	int		temp;

	if ((s = va_arg(str->ap, wchar_t *)) == 0)
	{
		ft_putstr("(null)", str);
		return (0);
	}
	length = ft_strlen_unicode(s, str->precision);
	if (!str->flags_tab[MINUS])
		print_width(str, length);
	temp = 0;
	while (s[temp] && str->precision != 0)
	{
		ft_putchar_unicode(s[temp], str);
		++temp;
	}
	if (str->flags_tab[MINUS])
		print_width(str, length);
	return (0);
}

int		printf_char_unicode(t_printf *str)
{
	wchar_t		c;
	int			length;

	c = va_arg(str->ap, wint_t);
	length = 4;
	if (c <= 0xFFFF)
		--length;
	if (c <= 0x7FF)
		--length;
	if (c <= 0x7F)
		--length;
	if (!str->flags_tab[MINUS])
		print_width(str, length);
	str->precision = 4;
	ft_putchar_unicode(c, str);
	if (str->flags_tab[MINUS])
		print_width(str, length);
	return (0);
}
