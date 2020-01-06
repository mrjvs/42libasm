/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_write.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-sni <jvan-sni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 11:59:42 by jvan-sni       #+#    #+#                */
/*   Updated: 2020/01/06 12:27:10 by jvan-sni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <fcntl.h>

void	test_ft_write(void)
{
	ssize_t	ret1std = write(1, "test\n", 5);
	ssize_t	ret1asm = ft_write(1, "test\n", 5);
	ssize_t	ret2std = write(1, "t\ntest", 2);
	ssize_t	ret2asm = ft_write(1, "t\ntest", 2);
	ssize_t	ret3std = write(112345, "test3\n", 6);
	ssize_t	ret3asm = ft_write(112345, "test3\n", 6);
	ssize_t	ret4std = write(1, NULL, 5);
	ssize_t	ret4asm = ft_write(1, NULL, 5);
	ssize_t	ret5std = write(1, "test5\n", 0);
	ssize_t	ret5asm = ft_write(1, "test5\n", 0);
	printf("return values:\nSTD - ASM\n%zi - %zi\n%zi - %zi\n%zi - %zi\n%zi - %zi\n%zi - %zi",
		ret1std, ret1asm, ret2std, ret2asm, ret3std, ret3asm, ret4std, ret4asm, ret5std, ret5asm);
}
