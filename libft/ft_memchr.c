/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:57:47 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 14:01:50 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	stop;
	char			*str;
	size_t			i;

	str = (char *)s;
	stop = (unsigned char)c;
	i = 0;
	while (i < n && (unsigned char)str[i] != stop)
		i = i + 1;
	return (i < n && (unsigned char)str[i] == stop ? &str[i] : NULL);
}
