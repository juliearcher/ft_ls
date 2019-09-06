/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 09:40:43 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 13:05:28 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*str;
	size_t	i;

	if (size <= 0 || (str = (char *)malloc(size)) == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		str[i] = 0;
	return (str);
}
