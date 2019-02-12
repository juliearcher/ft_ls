/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_directory.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 08:39:39 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 08:39:41 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int				read_directory(char *path, int options)
{
	(void)options;
	ft_printf("%s is a directory\n", path);
	return (0);
}