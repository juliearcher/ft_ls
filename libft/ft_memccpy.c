/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:42:00 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 15:00:21 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	unsigned char	stop;
	char			*s1;
	char			*s2;
	size_t			i;

	s1 = (char *)dst;
	s2 = (char *)src;
	stop = (unsigned char)c;
	i = -1;
	while (++i < n && (unsigned char)s2[i] != stop)
		s1[i] = s2[i];
	if (i >= n)
		return (NULL);
	s1[i] = s2[i];
	return (&s1[i + 1]);
}
