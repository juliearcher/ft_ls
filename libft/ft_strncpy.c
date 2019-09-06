/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 15:22:33 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 12:59:03 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] != 0 && len > 0)
	{
		dst[i] = src[i];
		i = i + 1;
		len = len - 1;
	}
	while (len > 0)
	{
		dst[i] = 0;
		i = i + 1;
		len = len - 1;
	}
	return (dst);
}
