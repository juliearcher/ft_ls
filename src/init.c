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
	int				i;

	elem->strings.link[0] = 0;
	str = getgrgid(elem->infos.st_gid);
	elem->strings.group = str == NULL ? "" : str->gr_name;
	elem->max_length.group_length = ft_strlen(elem->strings.group);
	if (length->group_length < elem->max_length.group_length)
		length->group_length = elem->max_length.group_length;
	elem->strings.time = ft_strdup(ctime(opt & u ?
		&elem->infos.st_atime : &elem->infos.st_mtime));
	i = time(NULL);
	if (i < (opt & u ? elem->infos.st_atime : elem->infos.st_mtime) ||
		i - (opt & u ? elem->infos.st_atime : elem->infos.st_mtime) > 15552000)
	{
		i = 10;
		while (++i < 15)
			elem->strings.time[i] = elem->strings.time[i + 8];
	}
	i = -1;
	if (S_ISLNK(elem->infos.st_mode))
		i = readlink(elem->path, elem->strings.link, 256);
	if (i >= 0)
		elem->strings.link[i] = 0;
}

void		calc_length(t_length *length, t_file *elem, int opt)
{
	struct passwd	*str;
	int				res;

	elem->strings.time = NULL;
	elem->max_length.name_length = ft_strlen(elem->name);
	if (length->name_length < elem->max_length.name_length)
		length->name_length = elem->max_length.name_length;
	if (!(opt & l))
		return ;
	res = listxattr(elem->path, NULL, 0, XATTR_NOFOLLOW);
	elem->max_length.perm_length = 10 + (res > 0);
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
	elem->max_length.size_length = ft_strlen_int(elem->infos.st_size, 10);
	if (length->size_length < elem->max_length.size_length)
		length->size_length = elem->max_length.size_length;
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

void		free_file(t_file *file)
{
	if (file->first == 0)
	{
		free(file->name);
		free(file->path);
		if (file->strings.time != NULL)
			free(file->strings.time);
	}
	free(file);
}

void		free_structs(t_error *errors, t_file *files)
{
	t_error	*prev;
	t_file	*prev2;

	while (errors != NULL)
	{
		prev = errors;
		errors = errors->next;
		free(prev);
	}
	while (files != NULL)
	{
		prev2 = files;
		files = files->next;
		free(prev2->strings.time);
		free(prev2);
	}
}
