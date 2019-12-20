/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-sni <jvan-sni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:13:03 by jvan-sni       #+#    #+#                */
/*   Updated: 2019/12/20 13:57:10 by jvan-sni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libasm.h>
#include <fcntl.h>

int			main(void)
{
	char	*src;
	char	dst[23] = "aaaaaaaaaaaaaaaaaaaaaa";
	char	dst2[23] = "aaaaaaaaaaaaaaaaaaaaaa";
	int		fd;

	src = "Bee movie script here!";
	printf("--> STRLEN-RET: %zu\n", ft_strlen("TESTING"));
	printf("--> STRLEN-RET: %zu\n", ft_strlen(NULL));

	printf("--> WRITE-RET: %zu\n", ft_write(1, "this is a write test.\n", 22));
	printf("--> WRITE-RET: %zu\n", ft_write(1, "", 0));
	printf("--> WRITE-RET: %zu\n", ft_write(1, NULL, 0));

	fd = open("test/test.txt", O_RDONLY);
	printf("--> FD %i\n", fd);
	printf("--> READ-RET: %zi > BUF |%s|\n", ft_read(fd, dst, 5), dst);
	printf("--> READ-RET: %zi > BUF |%s|\n", ft_read(fd, dst, 10), dst);
	printf("--> READ-RET: %zi > BUF |%s|\n", ft_read(fd, dst, 0), dst);

	printf("--> STRCPY ORI |%s| > DST |%s| > RET |%s|\n", src, dst, ft_strcpy(dst, src));
	printf("--> STRCPY ORI |%s| > DST |%s| > RET |%s|\n", src, NULL, ft_strcpy(NULL, src));
	printf("--> STRCPY ORI |%s| > DST |%s| > RET |%s|\n", NULL, dst2, ft_strcpy(dst2, NULL));
	return (0);
}
