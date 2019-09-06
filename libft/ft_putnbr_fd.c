/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 12:13:56 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 14:49:04 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	print_nbr(unsigned int nb, int fd)
{
	if (nb >= 10)
		print_nbr(nb / 10, fd);
	ft_putchar_fd(nb % 10 + 48, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
		write(fd, "-", 1);
	nb = n >= 0 ? n : -n;
	print_nbr(nb, fd);
}
