/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-sni <jvan-sni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:13:03 by jvan-sni       #+#    #+#                */
/*   Updated: 2019/12/20 18:19:50 by jvan-sni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libasm.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int			main(void)
{
	char	*src;

	src = ft_strdup("tesitng!!");
	printf("%zu\n", ft_strlen(src));
	return (0);
}
