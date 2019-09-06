/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 09:46:18 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/05 06:14:11 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

t_list_gnl	*get_current_struct(t_list_gnl **first, int fd)
{
	t_list_gnl	*tmp;
	t_list_gnl	*elem;

	tmp = *first;
	while (tmp != 0 && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp != 0)
		return (tmp);
	if ((elem = malloc(sizeof(t_list_gnl))) == 0)
		return (0);
	elem->fd = fd;
	elem->next = *first;
	elem->full_line = 0;
	*first = elem;
	return (elem);
}

void		free_current(t_list_gnl **all_fds, t_list_gnl *current)
{
	t_list_gnl	*tmp;

	tmp = *all_fds;
	while (tmp != 0 && tmp != current && tmp->next != current)
		tmp = tmp->next;
	if (tmp == 0)
		return ;
	if (tmp == current)
		*all_fds = current->next;
	else
		tmp->next = current->next;
	free(current);
}

int			get_line_end(t_list_gnl **all_fds, t_list_gnl *current, int size)
{
	char	*tmp;
	char	*str;
	size_t	i;

	if (size == -1)
		return (-1);
	else if (size == 0 && current->full_line == 0)
	{
		free_current(all_fds, current);
		return (0);
	}
	str = ft_strchr(current->full_line, '\n');
	i = str == 0 ? ft_strlen(current->full_line) - 1 : str - current->full_line;
	if (i == ft_strlen(current->full_line) - 1)
	{
		free(current->full_line);
		current->full_line = 0;
		return (1);
	}
	tmp = ft_strdup(str + 1);
	free(current->full_line);
	current->full_line = tmp;
	return (tmp == NULL ? -1 : 1);
}

int			get_next_line(const int fd, char **line)
{
	static t_list_gnl	*all_fds = 0;
	t_list_gnl			*current;
	char				*tmp;
	char				tab[BUFF_SIZE + 1];
	int					size;

	if (BUFF_SIZE <= 0 || (current = get_current_struct(&all_fds, fd)) == NULL)
		return (-1);
	while ((size = read(fd, tab, BUFF_SIZE)) > 0)
	{
		tab[size] = 0;
		tmp = ft_strjoin(current->full_line, tab);
		if (current->full_line != 0)
			free(current->full_line);
		current->full_line = tmp;
		if (ft_strchr(current->full_line, '\n'))
			break ;
	}
	if (size == -1 || (size == 0 && current->full_line == 0))
		return (get_line_end(&all_fds, current, size));
	*line = ft_strdup_until(current->full_line, '\n');
	return (get_line_end(&all_fds, current, size));
}
