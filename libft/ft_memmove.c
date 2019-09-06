/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:51:19 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 14:15:51 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*s1;
	char	*s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	if (s2 >= s1)
	{
		i = -1;
		while (++i < len)
			s1[i] = s2[i];
	}
	else
	{
		i = len;
		while (i > 0)
		{
			s1[i - 1] = s2[i - 1];
			i = i - 1;
		}
	}
	return (dst);
}
