/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen_unsigned.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 11:53:36 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 11:58:18 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdint.h>
#include "libft_printf.h"

int		*ft_strlen_float_unsigned(long double nb, int *tab, int max)
{
	long	entier;
	int		length;

	entier = (long)nb;
	length = ft_strlen_unsigned(entier, 10);
	tab[0] = length;
	length = 0;
	nb -= entier;
	while (nb - (long)nb > 0.0000001 && max)
	{
		nb = nb * 10;
		++length;
		--max;
	}
	tab[1] = length;
	return (tab);
}
