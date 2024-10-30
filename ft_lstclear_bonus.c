/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:01:00 by mshariar          #+#    #+#             */
/*   Updated: 2024/10/30 15:27:44 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
/*
void	del(void *node)
{
	free(node);
}

int	main()
{
	char *str = ft_strdup("Hello");
	char *str1 = ft_strdup(" I ");
	char *str2 = ft_strdup("am a ");
	char *str3 = ft_strdup("list");
	t_list	*node;
	
	node = ft_lstnew(str);
	node->next = ft_lstnew(str1);
	node->next->next = ft_lstnew(str2);
	node->next->next->next = ft_lstnew(str3);
	node->next->next->next->next = NULL;

	ft_lstclear(&node, del);
	if (node == NULL)
	{
		printf("freed");
	}
	return (0);
}
*/