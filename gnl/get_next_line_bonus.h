/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:16:30 by jheras-f          #+#    #+#             */
/*   Updated: 2019/11/27 14:12:40 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void				*ft_memcpy(void *dest, const void *source, size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
int					get_next_line(int fd, char **line);

typedef struct		s_file
{
	char			*strbuf;
	long			len;
	int				rsz;
	long			pos;
	char			*endl;
}					t_file;

#endif
