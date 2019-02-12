/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_arguments.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 07:29:51 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 07:29:52 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int			print_argument_error(char *argument)
{
	ft_printf("%s: illegal option -- %s\n", EXEC_NAME, argument);
	return (ARGUMENT_ERROR);
}

static void	init_options_list(char **list, int *power)
{
	list[0] = "l";
	power[0] = 1;
	list[1] = "R";
	power[1] = 2;
	list[2] = "a";
	power[2] = 4;
	list[3] = "r";
	power[3] = 8;
	list[4] = "t";
	power[4] = 16;
	list[5] = "F";
	power[5] = 32;
	list[6] = "c";
	power[6] = 64;
	list[7] = "d";
	power[7] = 128;
	list[8] = "i";
	power[8] = 256;
	list[9] = "1";
	power[9] = 521;
	list[10] = "-color";
	power[10] = 1024;
}

int			get_arguments(int ac, char **av, int *options)
{
	char	*list[OPTIONS_NUMBER];
	int		power[OPTIONS_NUMBER];
	int		i;
	int		j;

	init_options_list(list, power);
	*options = 0;
	i = 1;
	while (i < ac && av[i][0] == '-' && av[i][1] != 0)
	{
		j = 0;
		while (j < OPTIONS_NUMBER && ft_strcmp(&av[i][1], list[j]) != 0)
			++j;
		if (j == OPTIONS_NUMBER)
			return (print_argument_error(&av[i][1]));
		*options = *options | power[j];
		++i;
	}
	return (i);
}