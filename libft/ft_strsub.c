/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 11:22:40 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 15:07:30 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (s == 0 || (result = (char *)malloc(len + 1)) == 0)
		return (0);
	i = -1;
	while (++i < len)
		result[i] = s[start + i];
	result[i] = 0;
	return (result);
}
