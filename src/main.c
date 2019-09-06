/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/04 12:34:41 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/04 12:43:17 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(__attribute__((unused)) int ac, char **av)
{
	t_option	opts;

	opts.errors = NULL;
	opts.files = NULL;
	init_length(&opts.max_length);
	if ((opts.options = (get_options(&opts, &av[1]))) == -1)
	{
		free_structs(opts.errors, opts.files);
		ft_putstr_fd(opts.options == -1 ?
			"usage: ./ft_ls [-lRartG] [file ...]\n" : "malloc error\n", 2);
		return (1);
	}
	print_errors(opts.errors);

	t_file *tmp;
	tmp = opts.files;
	while (tmp)
	{
		display_file(&opts.max_length, tmp, opts.options);
		tmp = tmp->next;
	}
	free_structs(opts.errors, opts.files);
	return (0);
}
