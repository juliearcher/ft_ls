/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_list.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 09:04:40 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 09:04:42 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void			free_list(t_directory *directory)
{
	t_file		*temp;
	t_file		*prev;

	temp = directory->file_list;
	while (temp != NULL)
	{
		prev = temp;
		temp = temp->next;
		free(prev);
	}
	directory->file_list = NULL;
}

static t_file	*create_new_node(struct dirent *entry)
{
	t_file		*new;

	if ((new = (t_file *)malloc(sizeof(t_file))) == NULL ||
		lstat(entry->d_name, &(new->file_infos)) == -1)
		return (NULL);
	new->file = entry;
	new->next = NULL;
	return (new);
}

int				add_entry_to_list(t_directory *directory,
					struct dirent *entry, int options)
{
	t_file		*new_file;

	if ((new_file = create_new_node(entry)) == NULL)
		return (-1);
	add_elem_to_list(directory, new_file, options);
	new_file->next = directory->file_list;
	directory->file_list = new_file;
	return (0);
}
