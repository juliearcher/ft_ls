/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/06 10:08:34 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/06 10:08:36 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_insert_file(t_file *a, t_file *b, t_opt options)
{
	t_file	*c;
	int		res;

	if (options & r)
	{
		c = a;
		a = b;
		b = c;
	}
	res = 0;
	if (options & t && options & u)
		res = a->infos.st_atime - b->infos.st_atime;
	else if (options & t)
		res = a->infos.st_mtime - b->infos.st_mtime;
	else if (options & S)
		res = a->infos.st_size - b->infos.st_size;
	return (res == 0 ? ft_strcmp(b->name, a->name) : res);
}

void	insert_file(t_file **files, t_file *elem, t_opt opt)
{
	t_file	*tmp;
	t_file	*prev;
	int		res;

	tmp = *files;
	if (tmp == NULL ||
		((res = ft_insert_file(elem, tmp, opt)) > 0))
	{
		elem->next = *files;
		*files = elem;
		return ;
	}
	while (tmp != NULL && (((res = ft_insert_file(elem, tmp, opt)) <= 0)))
	{
		prev = tmp;
		tmp = tmp->next;
	}
	elem->next = tmp;
	prev->next = elem;
}
