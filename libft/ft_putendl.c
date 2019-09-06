/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putendl.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 12:03:31 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 12:04:42 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i = i + 1;
	write(1, s, i);
	write(1, "\n", 1);
}