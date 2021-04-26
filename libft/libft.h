/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:19:59 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/11/14 19:09:23 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int					ft_atoi(const char *str);

void				ft_bzero(void *s, size_t n);

void				*ft_memset(void *dest, int c, size_t n);

void				*ft_memcpy(void *dest, const void *source, size_t n);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memchr(const void *arr, int c, size_t n);

int					ft_memcmp(const void *arr1, const void *arr2, size_t n);

void				*ft_memmove(void *dest, const void *src, size_t len);

char				*ft_strdup(const char *str);

char				*ft_strchr(const char *str, int ch);

size_t				ft_strlen(const char *str);

char				*ft_strnstr(const char *s1, const char *s2, size_t n);

int					ft_strlcat(char *dest, char *src, size_t size);

void				*ft_calloc(size_t num, size_t size);

size_t				ft_strlcpy(char *dest, const char *src, size_t size);

int					ft_strncmp(const char *str1, const char *str2, size_t n);

char				*ft_strrchr(const char *str, int ch);

int					ft_isdigit(int ch);

int					ft_isalpha(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_substr(char const *s, unsigned int start, size_t len);

void				ft_putendl_fd(char *s, int fd);

void				ft_putstr_fd(char *s, int fd);

void				ft_putchar_fd(char s, int fd);

void				ft_putnbr_fd(int n, int fd);

char				*ft_itoa(int n);

char				*ft_strtrim(char const *s1, char const *set);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char				**ft_split(char const *s, char c);

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);

void				ft_lstadd_front(t_list **list, t_list *new);

int					ft_lstsize(t_list *lst);

t_list				*ft_lstlast(t_list *lst);

void				ft_lstadd_back(t_list **lst, t_list *new);

void				ft_lstdelone(t_list *lst, void (*del)(void *));

void				ft_lstclear(t_list **lst, void (*del)(void *));

void				ft_lstiter(t_list *lst, void (*f)(void *));

#endif
