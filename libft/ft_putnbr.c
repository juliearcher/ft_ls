/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 12:05:25 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 14:46:14 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	print_nbr(unsigned int nb)
{
	if (nb >= 10)
		print_nbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void		ft_putnbr(int n)
{
	unsigned int	nb;

	if (n < 0)
		write(1, "-", 1);
	nb = n >= 0 ? n : -n;
	print_nbr(nb);
}
