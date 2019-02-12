/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_nb.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 11:53:36 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 11:58:18 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printf_int_flags(t_printf *str, intmax_t nb, int mod, int length)
{
	if (str->flags_tab[ZERO])
	{
		if (nb < 0)
			ft_putchar('-', str);
		else if (str->flags_tab[SPACE] || str->flags_tab[PLUS])
			ft_putchar(str->flags_tab[PLUS] ? '+' : ' ', str);
	}
	if (!str->flags_tab[MINUS])
		print_width(str, mod +
			(length > str->precision ? length : str->precision));
	if (!str->flags_tab[ZERO])
	{
		if (nb < 0)
			ft_putchar('-', str);
		else if (str->flags_tab[SPACE] || str->flags_tab[PLUS])
			ft_putchar(str->flags_tab[PLUS] ? '+' : ' ', str);
	}
}

int			printf_int(t_printf *str)
{
	intmax_t	nb;
	int			length;
	int			mod;

	if (str->precision > -1)
		str->flags_tab[ZERO] = 0;
	nb = get_number(str);
	length = ft_strlen_unsigned(nb < 0 ? -nb : nb, 10);
	mod = (nb < 0 || str->flags_tab[SPACE] || str->flags_tab[PLUS]);
	printf_int_flags(str, nb, mod, length);
	print_precision(str, length);
	if (str->precision != 0 || nb != 0)
		ft_putnbr_unsigned_base(nb < 0 ? -nb :
								nb, "0123456789", 10, str);
	else if (str->min_width != -1)
		ft_putchar(' ', str);
	if (str->flags_tab[MINUS])
		print_width(str, mod +
			(length > str->precision ? length : str->precision));
	return (0);
}

int			printf_long_int(t_printf *str)
{
	str->type = LONG;
	return (printf_int(str));
}

int			printf_unsigned(t_printf *str)
{
	uintmax_t			nb;
	int					length;

	nb = get_number_unsigned(str);
	if (str->flags_tab[MINUS] || str->precision != -1)
		str->flags_tab[ZERO] = 0;
	length = ft_strlen_unsigned(nb, 10);
	if (!str->flags_tab[MINUS])
		print_width(str, (length > str->precision ?
							length : str->precision));
	print_precision(str, length);
	if (nb != 0 || str->precision != 0)
		ft_putnbr_unsigned_base(nb, "0123456789", 10, str);
	if (str->flags_tab[MINUS])
		print_width(str, (length > str->precision ?
							length : str->precision));
	return (0);
}

int			printf_long_unsigned(t_printf *str)
{
	str->type = LONG;
	return (printf_unsigned(str));
}