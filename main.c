/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 07:20:33 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 07:20:34 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static int	print_usage(void)
{
	ft_printf("usage: %s [%s] [--color] [file ...]\n",
				EXEC_NAME, ARGUMENTS_LIST);
	return (-1);
}

int			print_error(char *path)
{
	ft_printf("%s: %s: %s\n", EXEC_NAME, path, strerror(errno));
	return (-1);
}

static int	ls_directories(int ac, char **av, int current, int options)
{
	struct stat	file;

	while (current < ac)
	{
		if (av[i] != 0)
		{
			if ((lstat(av[current], &file)) == -1)
				return (print_error(av[current]));
			if (av[i] != 0 && file.st_mode & S_IFDIR)
				read_directory(av[current], options);
		}
		++current;
	}
	return (0);
}

int			begin_ls(int ac, char **av, int current, int options)
{
	struct stat	file;
	int			first;

	if (current == ac)
	{
		read_directory(".", options);
		return (0);
	}
	first = current;
	while (current < ac)
	{
		if ((lstat(av[current], &file)) == -1)
			return (print_error(av[current]));
		if (!(file.st_mode & S_IFDIR))
		{
			print_file(av[current], options);
			av[i] = 0;
		}
		++current;
	}
	ls_directories(ac, av, first, options);
	return (0);
}

int			main(int ac, char **av)
{
	int	options;
	int	i;

	if ((i = get_arguments(ac, av, &options)) == ARGUMENT_ERROR)
		return (print_usage());
	begin_ls(ac, av, i, options);
	return (0);
}
