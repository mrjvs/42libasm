/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-sni <jvan-sni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:13:03 by jvan-sni       #+#    #+#                */
/*   Updated: 2020/01/06 17:37:52 by jvan-sni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"
#include <string.h>

void		test_all()
{
	test_ft_read();
	test_ft_write();
	test_ft_strlen();
	test_ft_strdup();
	test_ft_strcpy();
	test_ft_strcmp();
	test_ft_list_size();
}

int			main(int argc, char *argv[])
{
	if (argc < 2)
		return (1);
	if (strcmp(argv[1], "ft_read") == 0)
		test_ft_read();
	else if (strcmp(argv[1], "ft_write") == 0)
		test_ft_write();
	else if (strcmp(argv[1], "ft_strlen") == 0)
		test_ft_strlen();
	else if (strcmp(argv[1], "ft_strdup") == 0)
		test_ft_strdup();
	else if (strcmp(argv[1], "ft_strcpy") == 0)
		test_ft_strcpy();
	else if (strcmp(argv[1], "ft_strcmp") == 0)
		test_ft_strcmp();
	else if (strcmp(argv[1], "ft_list_size") == 0)
		test_ft_list_size();
	else if (strcmp(argv[1], "ft_list_push_front") == 0)
		test_ft_list_push_front();
	else if (strcmp(argv[1], "ft_list_remove_if") == 0)
		test_ft_list_remove_if();
	else if (strcmp(argv[1], "all") == 0)
		test_all();
	return (0);
}
