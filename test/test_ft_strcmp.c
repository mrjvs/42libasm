/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strcmp.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-sni <jvan-sni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 11:59:42 by jvan-sni       #+#    #+#                */
/*   Updated: 2020/01/06 13:52:27 by jvan-sni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <fcntl.h>
#define STRCMP_TEST_1 "test1", "test1"
#define STRCMP_TEST_2 "test", "test2"
#define STRCMP_TEST_3 "test3", "test"
#define STRCMP_TEST_4 "b", "abcasdfasdga"
#define STRCMP_TEST_5 "", "test5"
#define STRCMP_TEST_6 "test6", ""
#define STRCMP_TEST_7 NULL, "test7"
#define STRCMP_TEST_8 "test8", NULL
#define STRCMP_TEST_9 NULL, NULL

void	test_ft_strcmp(void)
{
	printf("ORI '%s' = '%s'\nLIBASM %i - STDLIB %i\n-=-\n",
		STRCMP_TEST_1, ft_strcmp(STRCMP_TEST_1), strcmp(STRCMP_TEST_1));
	printf("ORI '%s' = '%s'\nLIBASM %i - STDLIB %i\n-=-\n",
		STRCMP_TEST_2, ft_strcmp(STRCMP_TEST_2), strcmp(STRCMP_TEST_2));
	printf("ORI '%s' = '%s'\nLIBASM %i - STDLIB %i\n-=-\n",
		STRCMP_TEST_3, ft_strcmp(STRCMP_TEST_3), strcmp(STRCMP_TEST_3));
	printf("ORI '%s' = '%s'\nLIBASM %i - STDLIB %i\n-=-\n",
		STRCMP_TEST_4, ft_strcmp(STRCMP_TEST_4), strcmp(STRCMP_TEST_4));
	printf("ORI '%s' = '%s'\nLIBASM %i - STDLIB %i\n-=-\n",
		STRCMP_TEST_5, ft_strcmp(STRCMP_TEST_5), strcmp(STRCMP_TEST_5));
	printf("ORI '%s' = '%s'\nLIBASM %i - STDLIB %i\n-=-\n",
		STRCMP_TEST_6, ft_strcmp(STRCMP_TEST_6), strcmp(STRCMP_TEST_6));
	puts("NEXT WILL SEGFAULT, requires manual testing");
	printf("ORI '%s' = '%s'\nLIBASM %i - STDLIB %i\n-=-\n",
		STRCMP_TEST_7, ft_strcmp(STRCMP_TEST_7), strcmp(STRCMP_TEST_7));
	printf("ORI '%s' = '%s'\nLIBASM %i - STDLIB %i\n-=-\n",
		STRCMP_TEST_8, ft_strcmp(STRCMP_TEST_8), strcmp(STRCMP_TEST_8));
	printf("ORI '%s' = '%s'\nLIBASM %i - STDLIB %i\n-=-\n",
		STRCMP_TEST_9, ft_strcmp(STRCMP_TEST_9), strcmp(STRCMP_TEST_9));
}
