/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_list_size.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-sni <jvan-sni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 14:27:07 by jvan-sni       #+#    #+#                */
/*   Updated: 2020/01/08 13:31:59 by jvan-sni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <stdlib.h>
#include <stdio.h>

void	test_ft_list_size(void)
{
	t_list list1;
	t_list list2;
	t_list list3;

	list1.next = &list2;
	list1.data = "HALLO";
	list2.next = &list3;
	list2.data = "HALLO2";
	list3.next = NULL;
	list3.data = "HALLO3";
	printf("%zu\n", ft_list_size(&list1));
	list1.next = &list2;
	list1.data = "HALLO";
	list2.next = NULL;
	list2.data = "HALLO2";
	printf("%zu\n", ft_list_size(&list1));
	list1.next = NULL;
	list1.data = "HALLO";
	printf("%zu\n", ft_list_size(&list1));
	printf("%zu\n", ft_list_size(NULL));
}
