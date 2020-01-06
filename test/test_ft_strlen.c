/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strlen.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-sni <jvan-sni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 11:59:42 by jvan-sni       #+#    #+#                */
/*   Updated: 2020/01/06 12:35:49 by jvan-sni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <fcntl.h>
#define STRLEN_TEST_1 "test1"
#define STRLEN_TEST_2 "test2"
#define STRLEN_TEST_3 "asdfjhbjasdkfbaskhbsdkjfhls"
#define STRLEN_TEST_4 NULL

void	test_ft_strlen(void)
{
	printf("IN = '%s', STD %zu, FT %zu\n", STRLEN_TEST_1,
		strlen(STRLEN_TEST_1), ft_strlen(STRLEN_TEST_1));
	printf("IN = '%s', STD %zu, FT %zu\n", STRLEN_TEST_2,
		strlen(STRLEN_TEST_2), ft_strlen(STRLEN_TEST_2));
	printf("IN = '%s', STD %zu, FT %zu\n", STRLEN_TEST_3,
		strlen(STRLEN_TEST_3), ft_strlen(STRLEN_TEST_3));
	puts("NEXT WILL SEGFAULT, requires manual testing");
	printf("IN = '%s', STD %zu, FT %zu\n", STRLEN_TEST_4,
		strlen(STRLEN_TEST_4), ft_strlen(STRLEN_TEST_4));
}
