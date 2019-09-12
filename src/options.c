/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   options.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/04 13:05:09 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/04 13:05:10 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	init_file(t_option *str, char *name, t_file *elem, t_opt opt)
{
	if (S_ISDIR(elem->infos.st_mode))
		++str->dirnum;
	elem->path = name;
	elem->name = name;
	elem->first = 1;
	elem->dirname = 0;
	elem->time = str->time;
	insert_file(&str->files, elem, opt);
	calc_length(&str->max_length, elem, opt);
}

static int	get_files(t_option *str, char **names, t_opt opt)
{
	t_file		*elem;
	int			(*f)();
	int			i;

	if ((elem = (t_file *)malloc(sizeof(t_file))) == 0)
		return (-1);
	f = opt & l ? &lstat : &stat;
	i = -1;
	while (names[++i])
	{
		if (f(names[i], &elem->infos) == -1)
		{
			if (new_error(&str->errors, names[i]) == -1)
				return (-1);
			continue ;
		}
		init_file(str, names[i], elem, opt);
		if ((elem = (t_file *)malloc(sizeof(t_file))) == 0)
			return (-1);
	}
	free(elem);
	return (0);
}

static char	parse_arg(char *tabopts, int *values, char *str, t_opt *options)
{
	int		i;
	int		j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (tabopts[j] && str[i] != tabopts[j])
			++j;
		if (tabopts[j] == 0)
			break ;
		*options = *options | values[j];
		++i;
	}
	return (str[i]);
}

static void	init_options(char **tabopts, int *values)
{
	*tabopts = "lRartGAFSpu";
	values[0] = l;
	values[1] = R;
	values[2] = a;
	values[3] = r;
	values[4] = t;
	values[5] = G;
	values[6] = A;
	values[7] = F;
	values[8] = S;
	values[9] = p;
	values[10] = u;
}

int			get_options(t_option *str, char **tab)
{
	t_opt	options;
	char	c;
	int		i;

	options = 0;
	i = 0;
	init_options(&str->tabopts, str->values);
	while (tab[i] != NULL)
	{
		if (tab[i][0] != '-')
			break ;
		else if ((c = (parse_arg(str->tabopts, str->values,
							tab[i], &options))) != 0)
		{
			ft_printf(2, "%s: illegal option -- %c\n", NAME, c);
			return (-1);
		}
		++i;
	}
	if (tab[i] != NULL && get_files(str, &tab[i], options) == -1)
		return (-2);
	return (options);
}
