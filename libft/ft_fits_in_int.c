/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fits_in_int.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/07 10:09:02 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/07 10:09:04 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <limits.h>

int		ft_fits_in_int(const char *str)
{
	int					i;
	int					neg;
	unsigned int		val;

	i = 0;
	val = 0;
	neg = 1;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\v' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == ' ')
		i = i + 1;
	if (str[i] == '-' || str[i] == '+')
	{
		neg = str[i] == '-' ? -1 : 1;
		i = i + 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((val * 10 + str[i] - '0') >
			(neg == -1 ? (unsigned)(INT_MAX + 1) : (unsigned)INT_MAX))
			return (0);
		val = val * 10 + str[i] - '0';
		i = i + 1;
	}
	return (1);
}
