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

# define BLUE			"\e[0;34m"
# define MAGENTA		"\e[0;35m"
# define GREEN			"\e[0;32m"
# define YELLOW			"\e[0;33m"
# define RED			"\e[0;31m"
# define DEFAULT		"\e[0;39m"
# define BLUECYAN		"\e[0;34;46m"
# define BLUEYELLOW		"\e[0;34;43m"
# define BLACKGREEN		"\e[0;30;42m"
# define BLACKYELLOW	"\e[0;30;43m"
# define END			"\e[0m"

typedef int		t_opt;

enum			e_option
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
	char		*owner;
	char		*group;
	char		*time;
	char		link[256];
	char		perm[12];
}				t_str;

typedef struct	s_file
{
	struct stat		infos;
	struct s_file	*content;
	char			*path;
	char			*name;
	t_length		max_length;
	t_str			strings;
	int				first;
	int				first_file;
	int				print_rec;
	int				dirname;
	int				blocks;
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
	int			dirnum;
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
void			free_file(t_file *file);
void			free_structs(t_error *errors, t_file *files);

/*
** options.c
*/
int				get_options(t_option *options, char **tab);

/*
** print_options.c
*/
int				print_options(t_option *opts);

/*
** sort.c
*/
int				ft_insert_file(t_file *a, t_file *b, t_opt options);
void			insert_file(t_file **files, t_file *elem, t_opt opt);

#endif
