/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 11:14:25 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 15:01:41 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		i;

	i = 0;
	while (s != 0 && s[i] != 0)
		i = i + 1;
	if ((result = (char *)malloc(i + 1)) == 0)
		return (0);
	i = -1;
	while (s != 0 && s[++i] != 0)
		result[i] = (*f)(i, s[i]);
	result[i] = 0;
	return (result);
}
