/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:37:38 by tdawson           #+#    #+#             */
/*   Updated: 2022/01/11 19:15:52 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*list;

	if (!lst)
		return (NULL);
	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list = f(lst);
	new = list;
	while (lst->next)
	{
		lst = lst->next;
		list->next = (t_list *)malloc(sizeof(t_list));
		if (!list->next)
			return (NULL);
		list->next = f(lst);
		list = list->next;
	}
	return (new);
}
