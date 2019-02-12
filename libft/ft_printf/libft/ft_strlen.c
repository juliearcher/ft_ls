/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 15:15:54 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 12:58:14 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

size_t		ft_strlen(const char *s)
{
	int	index;

	index = 0;
	while (s[index] != 0)
		index = index + 1;
	return (index);
}
