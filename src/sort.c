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

	if (options & r)
	{
		c = a;
		a = b;
		b = c;
	}
	if (options & t && options & u)
		return (a->infos.st_atime - b->infos.st_atime);
	else if (options & t)
		return (a->infos.st_mtime - b->infos.st_mtime);
	else if (options & S)
		return (a->infos.st_size - b->infos.st_size);
	return (ft_strcmp(b->path, a->path));
}

void	insert_file(t_file **files, t_file *elem, t_opt opt)
{
	t_file	*tmp;
	t_file	*prev;
	int		res;

	tmp = *files;
	if (tmp == NULL ||
		(res = ft_insert_file(elem, tmp, opt) > 0) ||
		(res == 0 && (opt & r)))
	{
		elem->next = *files;
		*files = elem;
		return ;
	}
	while (tmp != NULL && ((res = ft_insert_file(elem, tmp, opt) < 0) ||
		(res == 0 && !(opt & r))))
	{
		prev = tmp;
		tmp = tmp->next;
	}
	elem->next = tmp;
	prev->next = elem;
}
