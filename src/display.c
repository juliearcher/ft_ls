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

static void	get_permissions(t_file *file)
{
	char	*str;

	str = file->strings.perm;
	str[11] = 0;
	str[0] = '-';
	if (S_ISDIR(file->infos.st_mode))
		str[0] = 'd';
	else if (S_ISLNK(file->infos.st_mode))
		str[0] = 'l';
	else if (S_ISFIFO(file->infos.st_mode))
		str[0] = 'p';
	str[1] = file->infos.st_mode & S_IRUSR ? 'r' : '-';
	str[2] = file->infos.st_mode & S_IWUSR ? 'w' : '-';
	str[3] = file->infos.st_mode & S_IXUSR ? 'x' : '-';
	str[4] = file->infos.st_mode & S_IRGRP ? 'r' : '-';
	str[5] = file->infos.st_mode & S_IWGRP ? 'w' : '-';
	str[6] = file->infos.st_mode & S_IXGRP ? 'x' : '-';
	str[7] = file->infos.st_mode & S_IROTH ? 'r' : '-';
	str[8] = file->infos.st_mode & S_IWOTH ? 'w' : '-';
	str[9] = file->infos.st_mode & S_IXOTH ? 'x' : '-';
	if (file->infos.st_mode & S_ISVTX)
		str[9] = (str[3] == 'x' || str[6] == 'x' || str[9] == 'x') ? 't' : 'T';
	str[10] = file->max_length.perm_length == 10 ? 0 : '@';
}

static char	*get_type_str(t_file *file, int options)
{
	if (S_ISDIR(file->infos.st_mode) && (options & F || options & p))
		return ("/");
	else if (options & F)
	{
		if (S_ISLNK(file->infos.st_mode))
			return ("@");
		else if (S_ISSOCK(file->infos.st_mode))
			return ("=");
		else if (S_ISFIFO(file->infos.st_mode))
			return ("|");
		else if (file->infos.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH))
			return ("*");
	}
	return ("");
}

static char	*get_color(int infos, int options)
{
	if (!(options & G))
		return ("");
	if (infos & S_ISVTX && !(infos & (S_IRUSR | S_IRGRP | S_IROTH)))
		return (BLACKGREEN);
	else if (S_ISDIR(infos) && infos & S_IRUSR && infos & S_IWUSR &&
		infos & S_IXUSR && infos & S_IRGRP && infos & S_IWGRP &&
		infos & S_IXGRP && infos & S_IROTH && infos & S_IWOTH &&
		infos & S_IXOTH)
		return (BLACKYELLOW);
	else if (S_ISBLK(infos))
		return (BLUECYAN);
	else if (S_ISCHR(infos))
		return (BLUEYELLOW);
	else if (S_ISDIR(infos))
		return (BLUE);
	else if (S_ISLNK(infos))
		return (MAGENTA);
	else if (S_ISSOCK(infos))
		return (GREEN);
	else if (S_ISFIFO(infos))
		return (YELLOW);
	else if (infos & S_IXUSR || infos & S_IXGRP || infos & S_IXOTH)
		return (RED);
	return (DEFAULT);
}

int			display_file(t_length *max, t_file *file, int options)
{
	if (S_ISDIR(file->infos.st_mode) &&
		(file->first == 1 || file->print_rec == 1))
		return (parse_directory(file, options));
	if (!(options & l))
	{
		ft_printf(1, "%s%s%s\n", get_color(file->infos.st_mode, options),
		file->name, options & G ? END : "", get_type_str(file, options));
		return (0);
	}
	get_permissions(file);
	ft_printf(1, "%-*s %*d %*s  %*s  %*d %.12s %s%s%s%s%s%s\n",
		max->perm_length, file->strings.perm, max->links_length,
		file->infos.st_nlink, max->owner_length, file->strings.owner,
		max->group_length, file->strings.group, max->size_length,
		file->infos.st_size, ft_strlen(file->strings.time) > 4 ?
		&file->strings.time[4] : file->strings.time,
		get_color(file->infos.st_mode, options), file->name, options & G ?
		END : "", get_type_str(file, options), S_ISLNK(file->infos.st_mode) ?
		" -> " : "", S_ISLNK(file->infos.st_mode) ? file->strings.link : "");
	return (0);
}
