/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_read.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-sni <jvan-sni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 11:59:42 by jvan-sni       #+#    #+#                */
/*   Updated: 2020/01/06 12:15:20 by jvan-sni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <fcntl.h>

void	test_ft_read(void)
{
	char	*src;
	char	*src2;
	ssize_t	len;
	ssize_t	len2;
	int		fd;

	// test invalid fd
	src = calloc(15, 1);
	len = read(1234567, src, 5);
	src2 = calloc(15, 1);
	len2 = ft_read(1234567, src2, 5);
	printf("-= FT %zd - '%s' =- VS -= STDLIB %zd - '%s' =-\n",
		len2, src2, len, src);

	// test on fd
	fd = open("test/test.txt", O_RDONLY);
	bzero(src, 15);
	len = read(fd, src, 5);
	close(fd);

	fd = open("test/test.txt", O_RDONLY);
	bzero(src2, 15);
	len2 = ft_read(fd, src2, 5);
	close(fd);

	printf("-= FT %zd - '%s' =- VS -= STDLIB %zd - '%s' =-\n",
		len2, src2, len, src);
	
	// test on half fd
	fd = open("test/test1.txt", O_RDONLY);
	bzero(src, 15);
	len = read(fd, src, 7);
	close(fd);

	fd = open("test/test1.txt", O_RDONLY);
	bzero(src2, 15);
	len2 = ft_read(fd, src2, 7);
	close(fd);

	printf("-= FT %zd - '%s' =- VS -= STDLIB %zd - '%s' =-\n",
		len2, src2, len, src);

	// test on empty fd
	fd = open("test/test0.txt", O_RDONLY);
	bzero(src, 15);
	len = read(fd, src, 15);
	close(fd);

	fd = open("test/test0.txt", O_RDONLY);
	bzero(src2, 15);
	len2 = ft_read(fd, src2, 15);
	close(fd);

	printf("-= FT %zd - '%s' =- VS -= STDLIB %zd - '%s' =-\n",
		len2, src2, len, src);
}
