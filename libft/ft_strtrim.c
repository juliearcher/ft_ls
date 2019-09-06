/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 11:32:53 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 15:09:19 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_size(const char *s)
{
	int	size;
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i = i + 1;
	size = 0;
	while (s[i] != 0)
	{
		size = size + 1;
		i = i + 1;
	}
	i = i - 1;
	while (size > 0 && i >= 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		size = size - 1;
		i = i - 1;
	}
	return (size);
}

char		*ft_strtrim(char const *s)
{
	char	*result;
	int		size;
	int		i;
	int		j;

	if (s == 0)
		return (0);
	size = get_size(s);
	if ((result = (char *)malloc(size + 1)) == 0)
		return (0);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i = i + 1;
	j = 0;
	while (j < size)
		result[j++] = s[i++];
	result[j] = 0;
	return (result);
}
