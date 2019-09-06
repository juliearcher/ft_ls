/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/04 09:05:36 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/04 12:42:18 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <time.h>
# include <unistd.h>
# include "libft.h"

# define MALLOC_ERROR	-2
# define NAME			"./ft_ls"
# define OPT_NUM		11

typedef int		t_opt;

enum			e_options
{
	l = 1,
	R = 2,
	a = 4,
	r = 8,
	t = 16,
	G = 32,
	A = 64,
	F = 128,
	S = 256,
	p = 512,
	u = 1024
};

typedef struct	s_error
{
	char			*msg;
	char			*path;
	struct s_error	*next;
}				t_error;

typedef struct	s_length
{
	int			perm_length;
	int			links_length;
	int			owner_length;
	int			group_length;
	int			size_length;
	int			time_length;
	int			name_length;
}				t_length;

typedef struct	s_str
{
	char		*permissions;
	char		*owner;
	char		*group;
	char		*time;
}				t_str;

typedef struct	s_file
{
	struct dirent	*file;
	struct stat		infos;
	struct s_file	*content;
	char			*path;
	t_length		max_length;
	t_str			strings;
	struct s_file	*next;
}				t_file;

typedef struct	s_option
{
	t_file		*files;
	t_error		*errors;
	t_opt		options;
	t_length	max_length;
	char		*tabopts;
	int			values[OPT_NUM];
}				t_option;

/*
** directry.c
*/
int				parse_directory(t_file *dir, int options);

/*
** display.c
*/
int				display_file(t_length *max, t_file *file, int options);

/*
** errors.c
*/
void			print_errors(t_error *errors);
int				new_error(t_error **errors, char *name);

/*
** init.c
*/
void			calc_length(t_length *length, t_file *elem, int opt);
void			init_length(t_length *length);

/*
** options.c
*/
void			free_structs(t_error *errors, t_file *files);
int				get_options(t_option *options, char **tab);

/*
** sort.c
*/
int				ft_insert_file(t_file *a, t_file *b, t_opt options);
void			insert_file(t_file **files, t_file *elem, t_opt opt);

#endif
