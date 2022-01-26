/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdawson <tdawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:07:34 by tdawson           #+#    #+#             */
/*   Updated: 2019/10/22 13:15:06 by tdawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*next_link;
	t_list	*link;

	if (!alst)
		return ;
	link = *alst;
	while (link)
	{
		next_link = link->next;
		(*del)(link->content, link->content_size);
		free(link);
		link = next_link;
	}
	*alst = NULL;
}
