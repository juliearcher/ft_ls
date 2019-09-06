/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   directory.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/06 14:02:51 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/06 14:02:53 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		parse_directory(t_file *dir, int options)
{
	ft_printf(1, "%s is a directory\n", dir->path);
	return (options);
}
