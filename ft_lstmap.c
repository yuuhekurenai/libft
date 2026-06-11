/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcelesti <gcelesti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:58:08 by gcelesti          #+#    #+#             */
/*   Updated: 2026/06/09 17:58:08 by gcelesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*new_list;
	void	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = f(lst->content);
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		node = ft_lstnew(new_node);
		if (!node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node);
		lst = lst->next;
	}
	return (new_list);
}