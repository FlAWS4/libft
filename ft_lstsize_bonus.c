/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:42:09 by mshariar          #+#    #+#             */
/*   Updated: 2024/10/29 14:28:02 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
int	main()
{
	t_list	*node;
	
	node = ft_lstnew("Hello");
	node->next = ft_lstnew(" I ");
	node->next->next = ft_lstnew("am a ");
	node->next->next->next = ft_lstnew("list");
		
	printf("%d", ft_lstsize(node));
}
*/