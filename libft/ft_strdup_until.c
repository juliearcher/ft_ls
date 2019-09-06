/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup_until.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 11:23:38 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 11:24:04 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup_until(const char *s1, const char c)
{
	char	*dest;
	int		i;

	i = 0;
	while (s1[i] != 0 && s1[i] != c)
		i = i + 1;
	if ((dest = (char *)malloc(i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != 0 && s1[i] != c)
	{
		dest[i] = s1[i];
		i = i + 1;
	}
	dest[i] = 0;
	return (dest);
}
