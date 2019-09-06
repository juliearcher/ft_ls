/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putchar_printf.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 12:00:24 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 12:01:14 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_printf.h"

void	ft_putchar_printf(char c, t_printf *str)
{
	char	*temp;

	str->output[str->length] = c;
	str->length += 1;
	str->output[str->length] = 0;
	if (str->length == str->output_length)
	{
		str->output_length += 100;
		temp = str->output;
		if ((str->output = (char *)malloc(str->output_length + 1)) == 0)
			exit(str->length);
		ft_strcpy(str->output, temp);
		free(temp);
	}
}
