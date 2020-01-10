/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_atoi_base.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-sni <jvan-sni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 14:27:07 by jvan-sni       #+#    #+#                */
/*   Updated: 2020/01/10 16:52:31 by jvan-sni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ATOI_PRINT "atoi input '%-17s' base '%-17s' --> %i\n"
#define ATOI_TEST1 "0123", "0123456789"
#define ATOI_TEST2 "010101010101", "01"
#define ATOI_TEST3 "-0000ff00", "0123456789abcdef"
#define ATOI_TEST4 "5555555555555", "5"
#define ATOI_TEST5 "-0000ff00", ""
#define ATOI_TEST6 "-0000ff00", "01234567+9abcdef"
#define ATOI_TEST7 "+0000ff00", "01234567-9abcdef"
#define ATOI_TEST8 "+0000ff00", "0123456799abcdef"
#define ATOI_TEST9 "-0000ff00", "0123456789abcd0f"
#define ATOI_TEST10 "-0g", "0123456789abcdef"
#define ATOI_TEST11 "12345678", "0123456789abcdef"
#define ATOI_TEST12 "+f", "0123456789abcdef"
#define ATOI_TEST13 "12345678", "0123456789"

void		test_ft_atoi_base(void)
{
	printf(ATOI_PRINT, ATOI_TEST1, ft_atoi_base(ATOI_TEST1));
	printf(ATOI_PRINT, ATOI_TEST2, ft_atoi_base(ATOI_TEST2));
	printf(ATOI_PRINT, ATOI_TEST3, ft_atoi_base(ATOI_TEST3));
	printf(ATOI_PRINT, ATOI_TEST4, ft_atoi_base(ATOI_TEST4));
	printf(ATOI_PRINT, ATOI_TEST5, ft_atoi_base(ATOI_TEST5));
	printf(ATOI_PRINT, ATOI_TEST6, ft_atoi_base(ATOI_TEST6));
	printf(ATOI_PRINT, ATOI_TEST7, ft_atoi_base(ATOI_TEST7));
	printf(ATOI_PRINT, ATOI_TEST8, ft_atoi_base(ATOI_TEST8));
	printf(ATOI_PRINT, ATOI_TEST9, ft_atoi_base(ATOI_TEST9));
	printf(ATOI_PRINT, ATOI_TEST10, ft_atoi_base(ATOI_TEST10));
	printf(ATOI_PRINT, ATOI_TEST11, ft_atoi_base(ATOI_TEST11));
	printf(ATOI_PRINT, ATOI_TEST12, ft_atoi_base(ATOI_TEST12));
	printf(ATOI_PRINT, ATOI_TEST13, ft_atoi_base(ATOI_TEST13));
}
