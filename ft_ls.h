/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 07:21:36 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 07:21:38 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

# include "libft.h"

# define OPTIONS_NUMBER	11
# define EXEC_NAME		"ft_ls"
# define ARGUMENTS_LIST	"-FRacdilrt1"

# define ARGUMENT_ERROR	-1

enum	e_options
{
	l = 1,
	R = 2,
	a = 4,
	r = 8,
	t = 16,
	F = 32,
	c = 64,
	d = 128,
	i = 256,
	one = 521,
	color = 1024
};

typedef struct s_dir
{
	int			options;
}				t_dir;

int				get_arguments(int ac, char **av, int *options);
int				read_directory(char *path, int options);
int				print_file(char *path, int options);

#endif