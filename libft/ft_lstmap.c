/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 12:42:08 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 13:19:42 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*elem;
	t_list	*last;

	first = 0;
	while (lst != 0)
	{
		elem = (*f)(lst);
		if (first == 0)
			first = elem;
		else
			last->next = elem;
		last = elem;
		lst = lst->next;
	}
	return (first);
}
