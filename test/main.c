/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-sni <jvan-sni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:13:03 by jvan-sni       #+#    #+#                */
/*   Updated: 2019/12/20 10:44:22 by jvan-sni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libasm.h>

#include <stdio.h>
#include <libasm.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int		main(void)
{
	double	time1 = clock();
	for (int i = 0; i < 1000000; i++)
	{
		ft_strlen("dlkjalkdsfjklasdjflkasdjflkasdfasdfasdfasdfasdfasdfasdf");
	}
	printf("%f\n", (clock() - time1) / CLOCKS_PER_SEC);
}

// int			main(void)
// {
// 	char	*src;
// 	char	dst[23] = "aaaaaaaaaaaaaaaaaaaaaa";
// 	char	dst2[23] = "aaaaaaaaaaaaaaaaaaaaaa";

// 	src = "Bee movie script here!";
// 	printf("--> STRLEN-RET: %zu\n", ft_strlen("TESTING"));
// 	printf("--> STRLEN-RET: %zu\n", ft_strlen(NULL));

// 	printf("--> WRITE-RET: %zu\n", ft_write(1, "this is a write test.\n", 22));
// 	printf("--> WRITE-RET: %zu\n", ft_write(1, "", 0));
// 	printf("--> WRITE-RET: %zu\n", ft_write(1, NULL, 0));

// 	printf("--> STRCPY ORI |%s| > DST |%s| > RET |%s|\n", src, dst, ft_strcpy(dst, src));
// 	printf("--> STRCPY ORI |%s| > DST |%s| > RET |%s|\n", src, NULL, ft_strcpy(NULL, src));
// 	printf("--> STRCPY ORI |%s| > DST |%s| > RET |%s|\n", NULL, dst2, ft_strcpy(dst2, NULL));
// 	return (0);
// }
