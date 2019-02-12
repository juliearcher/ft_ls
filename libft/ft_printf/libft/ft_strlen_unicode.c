/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen_unicode.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 15:15:54 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 12:58:14 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include <wchar.h>

int		ft_strlen_unicode(wchar_t *str, int precision)
{
	int	i;
	int	length;
	int	temp;

	i = 0;
	length = 0;
	while (str[i] && (precision <= -1 || precision > 0))
	{
		temp = 4;
		if (str[i] <= 0xFFFF)
			--temp;
		if (str[i] <= 0x7FF)
			--temp;
		if (str[i] <= 0x7F)
			--temp;
		if (precision > 0 && precision - temp < 0)
			break ;
		precision -= temp;
		length += temp;
		++i;
	}
	return (length);
}
