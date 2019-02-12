/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 12:27:51 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 12:30:20 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*ptr;

	ptr = *alst;
	while (ptr != 0)
	{
		tmp = ptr;
		(*del)(ptr->content, ptr->content_size);
		ptr = ptr->next;
		free(tmp);
	}
	*alst = 0;
}
