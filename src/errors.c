/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   errors.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/04 13:56:45 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/04 13:56:50 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_errors(t_error *errors)
{
	while (errors != NULL)
	{
		ft_printf(2, "%s: %s: %s\n", NAME, errors->path, errors->msg);
		errors = errors->next;
	}
}

static void	insert_new_error(t_error **errors, t_error *new_error)
{
	t_error	*tmp;
	t_error	*prev;

	tmp = *errors;
	prev = tmp;
	while (tmp != NULL && ft_strcmp(new_error->path, tmp->path) >= 0)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	new_error->next = tmp;
	prev->next = new_error;
}

int			new_error(t_error **errors, char *name)
{
	t_error	*elem;

	if ((elem = (t_error *)malloc(sizeof(t_error))) == NULL)
		return (-1);
	elem->path = name;
	elem->msg = strerror(errno);
	elem->next = NULL;
	if (*errors == NULL || ft_strcmp(name, (*errors)->path) < 0)
	{
		elem->next = *errors;
		*errors = elem;
		return (0);
	}
	insert_new_error(errors, elem);
	return (0);
}
