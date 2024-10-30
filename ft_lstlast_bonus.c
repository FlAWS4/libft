/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:57:21 by mshariar          #+#    #+#             */
/*   Updated: 2024/10/30 16:25:40 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int	main()
{
	t_list	*node;
	
	node = ft_lstnew("Hello");
	node->next = ft_lstnew(" I ");
	node->next->next = ft_lstnew("am a ");
	node->next->next->next = ft_lstnew("list");
	node->next->next->next->next = NULL;

	node = ft_lstlast(node);
	printf("%s\n", (char *)(node->content));
}
*/