/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strcpy.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-sni <jvan-sni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 11:59:42 by jvan-sni       #+#    #+#                */
/*   Updated: 2020/01/06 13:34:21 by jvan-sni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <fcntl.h>
#define STRCPY_TEST_1 "test1"
#define STRCPY_TEST_2 "test2-1234"
#define STRCPY_TEST_3 "test3\0sadflkj"
#define STRCPY_TEST_4 NULL

void	test_ft_strcpy(void)
{
	char	*new;
	char	*new2;

	new = calloc(15, 1);
	new2 = calloc(15, 1);
	printf("ORI '%s'\nLIBASM '%s' - '%s'\nSTDLIB '%s' - '%s'\n-=-\n",
		STRCPY_TEST_1,
		ft_strcpy(new, STRCPY_TEST_1), new,
		strcpy(new2, STRCPY_TEST_1), new2);
	free(new);
	free(new2);
	new = calloc(15, 1);
	new2 = calloc(15, 1);
	printf("ORI '%s'\nLIBASM '%s' - '%s'\nSTDLIB '%s' - '%s'\n-=-\n",
		STRCPY_TEST_2,
		ft_strcpy(new, STRCPY_TEST_2), new,
		strcpy(new2, STRCPY_TEST_2), new2);
	free(new);
	free(new2);
	new = calloc(15, 1);
	new2 = calloc(15, 1);
	printf("ORI '%s'\nLIBASM '%s' - '%s'\nSTDLIB '%s' - '%s'\n-=-\n",
		STRCPY_TEST_3,
		ft_strcpy(new, STRCPY_TEST_3), new,
		strcpy(new2, STRCPY_TEST_3), new2);
	free(new);
	free(new2);
	new = calloc(15, 1);
	new2 = calloc(15, 1);
	puts("NEXT WILL SEGFAULT, requires manual testing");
	printf("ORI '%s'\nLIBASM '%s' - '%s'\nSTDLIB '%s' - '%s'\n-=-\n",
		STRCPY_TEST_1,
		ft_strcpy(NULL, STRCPY_TEST_1), NULL,
		strcpy(NULL, STRCPY_TEST_1), NULL);
	free(new);
	free(new2);
	new = calloc(15, 1);
	new2 = calloc(15, 1);
	printf("ORI '%s'\nLIBASM '%s' - '%s'\nSTDLIB '%s' - '%s'\n-=-\n",
		STRCPY_TEST_4,
		ft_strcpy(new, STRCPY_TEST_4), new,
		strcpy(new2, STRCPY_TEST_4), new2);
	free(new);
	free(new2);
}
