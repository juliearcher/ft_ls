/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   directory.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/06 14:02:51 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/06 14:02:53 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int	add_file(t_file *dir, t_file *elem, int options)
{
	int			(*f)();

	f = options & l ? &lstat : &stat;
	if (f(elem->path, &elem->infos) == -1)
	{
		ft_printf(2, "%s: %s: %s\n", NAME, elem->name, strerror(errno));
		return (0);
	}
	elem->print_rec = 0;
	elem->time = dir->time;
	dir->blocks += elem->infos.st_blocks;
	insert_file(&dir->content, elem, options);
	calc_length(&dir->max_length, elem, options);
	return (1);
}

static int	create_file(t_file *dir, struct dirent *infos, t_file *elem)
{
	if ((elem->name = ft_strdup(infos->d_name)) == NULL ||
		(elem->path = (char *)malloc(ft_strlen(dir->path) +
			ft_strlen(infos->d_name) + 2)) == NULL)
		return (MALLOC_ERROR);
	ft_strcpy(elem->path, dir->path);
	if (elem->path[ft_strlen(elem->path) - 1] != '/')
		ft_strcat(elem->path, "/");
	ft_strcat(elem->path, infos->d_name);
	elem->first = 0;
	return (0);
}

static int	get_files(DIR *fd, t_file *dir, int options)
{
	struct dirent	*infos;
	t_file			*elem;

	errno = 0;
	if ((elem = (t_file *)malloc(sizeof(t_file))) == 0)
		return (MALLOC_ERROR);
	while ((infos = readdir(fd)) != NULL)
	{
		if (((ft_strcmp(".", infos->d_name) == 0 ||
			ft_strcmp("..", infos->d_name) == 0) && !(options & a)) ||
			(infos->d_name[0] == '.' && (!(options & a) && !(options & A))))
			continue ;
		if (create_file(dir, infos, elem) == MALLOC_ERROR)
			return (MALLOC_ERROR);
		if (!add_file(dir, elem, options))
		{
			free(elem->name);
			free(elem->path);
			continue ;
		}
		if ((elem = (t_file *)malloc(sizeof(t_file))) == 0)
			return (MALLOC_ERROR);
	}
	free(elem);
	return (0);
}

static int	print_directory(t_file *dir, int options)
{
	t_file	*tmp;
	t_file	*prev;

	tmp = dir->content;
	while (tmp != NULL)
	{
		if (display_file(&dir->max_length, tmp, options) == MALLOC_ERROR)
			return (MALLOC_ERROR);
		tmp = tmp->next;
	}
	tmp = dir->content;
	prev = NULL;
	while (tmp != NULL)
	{
		tmp->print_rec = (options & R) ? 1 : 0;
		if (S_ISDIR(tmp->infos.st_mode) && tmp->print_rec &&
		ft_strcmp(tmp->name, ".") != 0 && ft_strcmp(tmp->name, "..") != 0 &&
			display_file(&dir->max_length, tmp, options) == MALLOC_ERROR)
			return (MALLOC_ERROR);
		prev = tmp;
		tmp = tmp->next;
		free_file(prev);
	}
	return (0);
}

int			parse_directory(t_file *dir, int options)
{
	DIR		*fd;

	if ((fd = opendir(dir->path)) == NULL)
	{
		ft_printf(2, "%s: %s: %s\n", NAME, dir->name, strerror(errno));
		return (-1);
	}
	dir->blocks = 0;
	dir->content = 0;
	if (get_files(fd, dir, options) == MALLOC_ERROR)
	{
		closedir(fd);
		ft_putstr_fd("Malloc error\n", 2);
		return (MALLOC_ERROR);
	}
	closedir(fd);
	if (!dir->first || dir->dirname)
		ft_printf(1, "%s%s:\n", dir->first &&
			dir->first_file == 1 ? "" : "\n", dir->path);
	if (options & l && dir->content != 0)
		ft_printf(1, "total %d\n", dir->blocks);
	return (print_directory(dir, options));
}
