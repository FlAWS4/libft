/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:50:41 by mshariar          #+#    #+#             */
/*   Updated: 2024/10/30 15:27:16 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
void	del(void *content)
{
		free(content);
}

int	main()
{
	char *str = ft_strdup("Hello");
	char *str1 = ft_strdup(" I ");
	char *str2 = ft_strdup("am a ");
	char *str3 = ft_strdup("list");
	t_list	*node;
	t_list *tmp;
	
	node = ft_lstnew(str);
	node->next = ft_lstnew(str1);
	node->next->next = ft_lstnew(str2);
	node->next->next->next = ft_lstnew(str3);
	node->next->next->next->next = NULL;

	tmp = node->next;
	node->next = tmp ->next;
	ft_lstdelone(tmp, del);
	while(node)
	{
		printf("%s\n", (char *)node->content);
		tmp = node;
		node = node->next;
		free (tmp->content);
		free(tmp);
	}
}*/