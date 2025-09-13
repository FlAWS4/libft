/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:21:28 by mshariar          #+#    #+#             */
/*   Updated: 2024/10/31 15:31:32 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newmap;
	t_list	*newnode;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	newmap = NULL;
	while (lst != NULL)
	{
		tmp = f(lst->content);
		newnode = ft_lstnew(tmp);
		if (!newnode)
		{
			del(tmp);
			ft_lstclear(&newmap, del);
			return (NULL);
		}
		ft_lstadd_back(&newmap, newnode);
		lst = lst->next;
	}
	return (newmap);
}
/*
void	del(void *content)
{
		free(content);
}
void	*count(void *content)
{
	*(int *) content += 1;
	return (content);
}

void	*cap(void *content)
{
	int i;
	
	i = 0;
	char *str = (char *)content;
	while (str[i])
	{
		((char *) content)[i] = ft_toupper(str[i]);
		i++;
	}
	return (content);
}

int	main()
{
	int *first = malloc(sizeof(int));
	int	*second = malloc(sizeof(int));
	int	*third = malloc(sizeof(int));
	char *first = ft_strdup("hello");
	char *second = ft_strdup("i");
	char *third = ft_strdup("am a ");
	char *str3 = ft_strdup("list");
	t_list *list = NULL;
	
	*first = 1;
	*second = 2;
	*third = 3;
	ft_lstadd_back(&list, ft_lstnew(str));
	ft_lstadd_back(&list, ft_lstnew(first));
	ft_lstadd_back(&list, ft_lstnew(second));
	ft_lstadd_back(&list, ft_lstnew(third));
	t_list *newmap = ft_lstmap(list, count, del);
	t_list *newmap = ft_lstmap(list, cap, del);
	t_list  *tmp = newmap;
	while(newmap)
	{
		printf("%s\n", (char *)newmap->content);
		newmap = newmap->next;
	}
	ft_lstclear(&newmap, del);
	ft_lstclear(&list, del);
}
*/