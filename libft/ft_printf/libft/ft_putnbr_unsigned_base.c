/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_unsigned_base.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 11:53:36 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 11:58:18 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_printf.h"

void	ft_putnbr_unsigned_base(uintmax_t nb, char *base,
			unsigned int size, t_printf *str)
{
	if (nb >= size)
		ft_putnbr_unsigned_base(nb / size, base, size, str);
	ft_putchar_printf(base[nb % size], str);
}
