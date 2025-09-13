/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:11:30 by mshariar          #+#    #+#             */
/*   Updated: 2024/12/19 17:59:41 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	func(void *content)
{
	*(int *)content += 1;
}

int	main()
{
	int	*data1 = malloc(sizeof(int));
	int	*data2 = malloc(sizeof(int));
	int	*data3 = malloc(sizeof(int));

	*data1 = 1;
	*data2 = 2;
	*data3 = 3;
	t_list *list = NULL;

	ft_lstadd_back(&list, ft_lstnew(data1));
	ft_lstadd_back(&list, ft_lstnew(data2));
	ft_lstadd_back(&list, ft_lstnew(data3));
	
	ft_lstiter(list, func);
	while (list)
	{
		printf("%d\n", *(int *)list->content);
		list = list->next;
	}	
}*/