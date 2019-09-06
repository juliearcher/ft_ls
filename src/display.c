/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/06 13:28:04 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/06 13:28:05 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		display_file(t_length *max, t_file *file, int options)
{
	if (S_ISDIR(file->infos.st_mode))
		return (parse_directory(file, options));
	if (!(options & l))
	{
		ft_printf(1, "%s\n", file->path);
		return (0);
	}
	ft_printf(1, "%*s %*d %*s  %*s  %*d %.12s %s\n", max->perm_length,
		"placeholder", max->links_length, file->infos.st_nlink,
		max->owner_length, file->strings.owner, max->group_length,
		file->strings.group, max->size_length, file->infos.st_size,
		ft_strlen(file->strings.time) > 4 ? &file->strings.time[4] :
		file->strings.time, file->path);
	return (0);
}
