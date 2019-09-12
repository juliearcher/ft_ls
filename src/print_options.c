/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_options.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/10 11:53:28 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/12 13:25:58 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int	create_new_file(t_option *opts)
{
	t_file	*elem;

	if ((elem = (t_file *)malloc(sizeof(t_file))) == NULL ||
		stat(".", &elem->infos) == -1)
		return (MALLOC_ERROR);
	elem->content = NULL;
	elem->path = ".";
	elem->name = ".";
	elem->first = 1;
	elem->dirname = 0;
	elem->blocks = 0;
	elem->time = opts->time;
	elem->next = NULL;
	opts->files = elem;
	calc_length(&elem->max_length, elem, opts->options);
	return (0);
}

static int	print_dir(t_option *opts, int first)
{
	t_file	*tmp;

	tmp = opts->files;
	while (tmp != NULL)
	{
		if (S_ISDIR(tmp->infos.st_mode))
		{
			if (opts->dirnum > 1 || first > 1)
				tmp->dirname = 1;
			tmp->first_file = first;
			if (display_file(&opts->max_length, tmp, opts->options) == -2)
				return (MALLOC_ERROR);
			++first;
		}
		tmp = tmp->next;
	}
	return (0);
}

int			print_options(t_option *opts)
{
	t_file	*tmp;
	int		first;

	first = 1;
	if (opts->files == NULL && opts->errors == NULL &&
		create_new_file(opts) == MALLOC_ERROR)
		return (MALLOC_ERROR);
	tmp = opts->files;
	while (tmp != NULL)
	{
		if (!(S_ISDIR(tmp->infos.st_mode)) && ++first &&
			display_file(&opts->max_length, tmp, opts->options) == MALLOC_ERROR)
			return (MALLOC_ERROR);
		tmp = tmp->next;
	}
	print_dir(opts, first);
	return (0);
}
