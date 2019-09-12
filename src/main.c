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

int		main(int ac, char **av)
{
	t_option	opts;

	ac = 1;
	opts.errors = NULL;
	opts.files = NULL;
	opts.dirnum = 0;
	opts.time = time(NULL);
	init_length(&opts.max_length);
	if ((opts.options = (get_options(&opts, &av[1]))) < 0)
	{
		free_structs(opts.errors, opts.files);
		ft_putstr_fd(opts.options == -1 ?
		"usage: ./ft_ls [-AFGRSalprtu] [file ...]\n" : "malloc error\n", 2);
		return (1);
	}
	print_errors(opts.errors);
	if (print_options(&opts) == MALLOC_ERROR)
	{
		free_structs(opts.errors, opts.files);
		ft_putstr_fd("malloc error\n", 2);
		return (1);
	}
	free_structs(opts.errors, opts.files);
	return (0);
}
