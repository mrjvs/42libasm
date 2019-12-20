/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libasm.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-sni <jvan-sni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:27:11 by jvan-sni       #+#    #+#                */
/*   Updated: 2019/12/20 13:54:49 by jvan-sni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <inttypes.h>

extern int64_t	maxofthree(int64_t one, int64_t two, int64_t three);
extern int		hello_world(void);

extern size_t	ft_strlen(char *str);
extern ssize_t	ft_write(int fd, char *str, size_t len);
extern ssize_t	ft_read(int fd, char *buf, size_t len);
extern char		*ft_strcpy(char *dst, char *src);

#endif
