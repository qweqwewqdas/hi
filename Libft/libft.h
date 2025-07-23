/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:00:25 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/19 19:27:49 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int num);
int					ft_isdigit(int num);
int					ft_isalnum(int num);
int					ft_isascii(int num);
int					ft_isprint(int num);
size_t				ft_strlen(const char *str);
void				*ft_memset(void *p, int num, size_t len);
void				ft_bzero(void *p, size_t len);
void				*ft_memcpy(void *dest, const void *p, size_t len);
void				*ft_memmove(void *dest, const void *p, size_t len);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_strncmp(const char *str1, const char *str2, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
void				*ft_memchr(const void *ptr, int value, size_t len);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t len);
char				*ft_strnstr(const char *s, const char *src, size_t len);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s);
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s1, const char *set);
char				**ft_split(const char *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_printf(const char *input, ...);
char				*get_next_line(int fd);
char				*ft_get_strjoin(char const *s1, char const *s2);
char				*ft_get_strchr(const char *string, int searchedChar);
void				ft_get_bzero(void *s, size_t n);
void				*ft_get_calloc(size_t elementCount, size_t elementSize);
size_t				ft_get_strlen(const char *theString);
#endif
