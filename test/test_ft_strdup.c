/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strdup.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-sni <jvan-sni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 11:59:42 by jvan-sni       #+#    #+#                */
/*   Updated: 2020/01/06 12:35:56 by jvan-sni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <fcntl.h>
#define STRDUP_TEST_1 "test1"
#define STRDUP_TEST_2 "test2"
#define STRDUP_TEST_3 "asdfjhbjasdkfbas\0khbsdkjfhls"
#define STRDUP_TEST_4 NULL

void	test_ft_strdup(void)
{
	printf("IN = '%s', STD '%s', FT '%s'\n", STRDUP_TEST_1,
		strdup(STRDUP_TEST_1), ft_strdup(STRDUP_TEST_1));
	printf("IN = '%s', STD '%s', FT '%s'\n", STRDUP_TEST_2,
		strdup(STRDUP_TEST_2), ft_strdup(STRDUP_TEST_2));
	printf("IN = '%s', STD '%s', FT '%s'\n", STRDUP_TEST_3,
		strdup(STRDUP_TEST_3), ft_strdup(STRDUP_TEST_3));
	puts("NEXT WILL SEGFAULT, requires manual testing");
	printf("IN = '%s', STD '%s', FT '%s'\n", STRDUP_TEST_4,
		strdup(STRDUP_TEST_4), ft_strdup(STRDUP_TEST_4));
}
