/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_directory.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 08:39:39 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 08:39:41 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int				read_directory(char *path, int options)
{
	t_directory		directory;
	struct dirent	*entry;

	if ((directory.dir = opendir(path)) == NULL)
		return (print_error(path));
	directory.file_list = NULL;
	(void)options;
	while ((entry = readdir(directory.dir)))
	{
		if ((add_entry_to_list(&directory, entry)) == -1)
			return (print_error(path));
	}
	ft_printf("%s is a directory\n", path);
	if (free_list(&directory) == -1 || closedir(directory.dir) == -1)
		return (print_error(path));
	return (0);
}
