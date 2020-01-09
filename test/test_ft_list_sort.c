/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_list_sort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-sni <jvan-sni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 14:27:07 by jvan-sni       #+#    #+#                */
/*   Updated: 2020/01/09 18:32:22 by jvan-sni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int	compare(int *i, int *j)
{
	return (*i - *j);
}

static void	print_ft_list(t_list *lst)
{
	if (lst == NULL)
		printf("%s", (char *)lst);
	while (lst)
	{
		printf("-> '%i' ", *((int *)lst->data));
		lst = lst->next;
	}
	printf("\n");
}

void		test_ft_list_sort(void)
{
	t_list	list1;
	t_list	list2;
	t_list	list3;
	t_list	*lst;

	int	one = 1;
	int	two = 2;
	int three = 3;
	list1.next = &list2;
	list1.data = &two;
	list2.next = &list3;
	list2.data = &one;
	list3.next = NULL;
	list3.data = &three;
	lst = &list1;
	printf("PTRS %p\n %p\n %p\n\n", &one, &two, &three);
	print_ft_list(lst);
	ft_list_sort(&lst, compare);
	print_ft_list(lst);
	lst = NULL;
	print_ft_list(lst);
	ft_list_sort(&lst, compare);
	print_ft_list(lst);
}
