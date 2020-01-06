/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_list_push_front.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-sni <jvan-sni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 14:27:07 by jvan-sni       #+#    #+#                */
/*   Updated: 2020/01/06 17:36:25 by jvan-sni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void	print_ft_list(t_list *lst)
{
	if (lst == NULL)
		printf("%s", (char *)lst);
	while (lst)
	{
		printf("-> '%s' ", (char *)lst->data);
		lst = lst->next;
	}
	printf("\n");
}

void		test_ft_list_push_front(void)
{
	t_list	list1;
	t_list	list2;
	t_list	list3;
	t_list	*lst;

	list1.next = &list2;
	list1.data = "HALLO";
	list2.next = &list3;
	list2.data = "HALLO2";
	list3.next = NULL;
	list3.data = "HALLO3";
	lst = &list1;
	print_ft_list(lst);
	ft_list_push_front(&lst, "hey");
	print_ft_list(lst);
	lst = NULL;
	print_ft_list(lst);
	ft_list_push_front(&lst, "hey");
	print_ft_list(lst);
}
