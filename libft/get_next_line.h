/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 09:45:05 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2019/04/05 07:09:37 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE	1024

typedef struct	s_list_gnl
{
	struct s_list_gnl	*next;
	char				*full_line;
	int					fd;
}				t_list_gnl;

int				get_next_line(const int fd, char **line);

#endif
