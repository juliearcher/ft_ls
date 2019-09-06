/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 15:09:46 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 14:04:44 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	while (i < n && (unsigned char)str1[i] == (unsigned char)str2[i])
		i = i + 1;
	if (n == 0 || i == n)
		return (0);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
