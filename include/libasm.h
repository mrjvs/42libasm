/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libasm.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-sni <jvan-sni@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:27:11 by jvan-sni       #+#    #+#                */
/*   Updated: 2020/01/06 17:28:05 by jvan-sni      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <sys/types.h>

extern size_t	ft_strlen(char *str) asm("_ft_strlen");
extern ssize_t	ft_write(int fd, char *str, size_t len) asm("_ft_write");
extern ssize_t	ft_read(int fd, char *buf, size_t len) asm("_ft_read");
extern char		*ft_strcpy(char *dst, char *src) asm("_ft_strcpy");
extern char		*ft_strdup(const char *src) asm("_ft_strdup");
extern int		ft_strcmp(const char *str1, const char *str2) asm("_ft_strcmp");

typedef struct s_list	t_list;
struct			s_list
{
	void		*data;
	t_list		*next;
};

extern size_t	ft_list_size(t_list *begin_list) asm("_ft_list_size");
extern void		ft_list_push_front(t_list **begin_list, void *data)
	asm("_ft_list_push_front");
extern void		ft_list_remove_if(
	t_list **begin_list, void *data_ref, int (*cmp)()) asm("_ft_list_remove_if");

#endif
