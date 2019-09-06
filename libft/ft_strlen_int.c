/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen_int.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 11:53:36 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 11:58:18 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_strlen_int(int nb, int base)
{
	unsigned	nbr;
	int			length;

	length = 1;
	if (nb < 0)
		++length;
	nbr = nb < 0 ? -nb : nb;
	while ((nbr = nbr / base) != 0)
		++length;
	return (length);
}
