/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_list_remove_if.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-sni <jvan-sni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 14:27:07 by jvan-sni       #+#    #+#                */
/*   Updated: 2020/01/07 17:55:04 by jvan-sni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int	compare(char *s1, char *s2)
{
	return (strcmp(s1, s2));
}

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

void		test_ft_list_remove_if(void)
{
	t_list	list1;
	t_list	list2;
	t_list	list3;
	t_list	*lst;

	list1.next = &list2;
	list1.data = strdup("no");
	list2.next = &list3;
	list2.data = strdup("no");
	list3.next = NULL;
	list3.data = strdup("123");
	printf("PTR %p\n", list1.data);
	lst = &list1;
	print_ft_list(lst);
	puts("rm 'no'");
	ft_list_remove_if(&lst, "no", compare);
	print_ft_list(lst);
	puts("---");
	list1.next = &list2;
	list1.data = strdup("yes");
	list2.next = &list3;
	list2.data = strdup("no");
	list3.next = NULL;
	list3.data = strdup("no");
	lst = &list1;
	print_ft_list(lst);
	puts("rm 'no'");
	ft_list_remove_if(&lst, "no", compare);
	print_ft_list(lst);
	puts("---");
	list1.next = &list2;
	list1.data = strdup("yes");
	list2.next = &list3;
	list2.data = strdup("no");
	list3.next = NULL;
	list3.data = strdup("yes");
	lst = &list1;
	print_ft_list(lst);
	puts("rm 'yes'");
	ft_list_remove_if(&lst, "yes", compare);
	print_ft_list(lst);
	puts("---");
	list1.next = &list2;
	list1.data = strdup("yes");
	list2.next = &list3;
	list2.data = strdup("yes");
	list3.next = NULL;
	list3.data = strdup("yes");
	lst = &list1;
	print_ft_list(lst);
	puts("rm 'yes'");
	ft_list_remove_if(&lst, "yes", compare);
	print_ft_list(lst);
	puts("---");
	lst = NULL;
	print_ft_list(lst);
	puts("rm 'yes'");
	ft_list_remove_if(&lst, "yes", compare);
	print_ft_list(lst);
	ft_list_remove_if(NULL, "yes", compare);
}
