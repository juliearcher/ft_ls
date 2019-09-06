/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_modifiers.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 11:51:06 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 11:52:31 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flags(t_printf *str)
{
	int	i;

	while (*str->format)
	{
		i = 0;
		while (i < NB_FLAGS_TAB && str->flags[i] != *str->format)
			++i;
		if (i == NB_FLAGS_TAB)
			break ;
		str->flags_tab[i] = 1;
		++str->format;
		++str->prev;
	}
}

void	set_min_width(t_printf *str)
{
	if (*str->format != '*' && !ft_isdigit(*str->format))
		return ;
	if (*str->format == '*')
	{
		str->min_width = va_arg(str->ap, int);
		if (str->min_width < 0)
		{
			str->min_width *= -1;
			str->flags_tab[MINUS] = 1;
		}
		++str->format;
		++str->prev;
		return ;
	}
	str->min_width = ft_atoi(str->format);
	while (ft_isdigit(*str->format))
	{
		++str->format;
		++str->prev;
	}
}

void	set_precision(t_printf *str)
{
	if (*str->format != '.')
		return ;
	++str->format;
	++str->prev;
	if (*str->format != '*' && !ft_isdigit(*str->format))
	{
		str->precision = 0;
		return ;
	}
	if (*str->format == '*')
	{
		str->precision = va_arg(str->ap, int);
		if (str->precision < 0)
			str->precision = -1;
		++str->format;
		++str->prev;
		return ;
	}
	str->precision = ft_atoi(str->format);
	while (ft_isdigit(*str->format))
	{
		++str->prev;
		++str->format;
	}
}

void	set_length_modifier(t_printf *str)
{
	int	i;

	i = 0;
	while (i < NB_FLAGS && ft_strncmp(str->format, str->flags_type[i],
					ft_strlen(str->flags_type[i])) != 0)
		++i;
	if (i == NB_FLAGS)
		return ;
	if (i > str->type)
		str->type = i;
	str->format = str->format + ft_strlen(str->flags_type[i]);
	str->prev = str->prev + ft_strlen(str->flags_type[i]);
}
