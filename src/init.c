/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/06 12:40:42 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/06 12:40:44 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	calc_length2(t_length *length, t_file *elem, int opt)
{
	struct group	*str;

	str = getgrgid(elem->infos.st_gid);
	elem->strings.group = str == NULL ? "" : str->gr_name;
	elem->max_length.group_length = ft_strlen(elem->strings.group);
	if (length->group_length < elem->max_length.group_length)
		length->group_length = elem->max_length.group_length;
	elem->max_length.size_length = ft_strlen_int(elem->infos.st_size, 10);
	if (length->size_length < elem->max_length.size_length)
		length->size_length = elem->max_length.size_length;
	elem->strings.time = ctime(opt & u ?
		&elem->infos.st_atime : &elem->infos.st_mtime);
}

void		calc_length(t_length *length, t_file *elem, int opt)
{
	struct passwd	*str;
	int				res;

	elem->max_length.name_length = ft_strlen(elem->path);
	if (length->name_length < elem->max_length.name_length)
		length->name_length = elem->max_length.name_length;
	if (!(opt & l))
		return ;
	res = listxattr(elem->path, NULL, 0, elem->infos.st_mode);
	elem->max_length.perm_length = 10 + res > 0;
	if (length->perm_length < elem->max_length.perm_length)
		length->perm_length = elem->max_length.perm_length;
	elem->max_length.links_length = ft_strlen_int(elem->infos.st_nlink, 10);
	if (length->links_length < elem->max_length.links_length)
		length->links_length = elem->max_length.links_length;
	str = getpwuid(elem->infos.st_uid);
	elem->strings.owner = str == NULL ? "" : str->pw_name;
	elem->max_length.owner_length = ft_strlen(elem->strings.owner);
	if (length->owner_length < elem->max_length.owner_length)
		length->owner_length = elem->max_length.owner_length;
	calc_length2(length, elem, opt);
}

void		init_length(t_length *length)
{
	length->group_length = 0;
	length->links_length = 0;
	length->name_length = 0;
	length->owner_length = 0;
	length->perm_length = 0;
	length->size_length = 0;
	length->time_length = 12;
}
