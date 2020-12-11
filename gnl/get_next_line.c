/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 09:42:56 by jheras-f          #+#    #+#             */
/*   Updated: 2019/11/28 07:27:23 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_join(t_file *file)
{
	char		*tmpstr;
	long		sz;

	sz = file->len * 2;
	if (sz < file->len + BUFFER_SIZE)
		sz += BUFFER_SIZE;
	tmpstr = (char *)malloc((sz + 1) * sizeof(char));
	if (!tmpstr)
		return (1);
	ft_strcpy(tmpstr, file->strbuf);
	tmpstr[sz] = '\0';
	file->endl = tmpstr + (file->endl - file->strbuf);
	free(file->strbuf);
	file->strbuf = tmpstr;
	file->len = sz;
	return (0);
}

static int		ft_newline(t_file *file)
{
	while (file->pos > file->endl - file->strbuf
			&& *(file->endl) != '\n')
		file->endl++;
	if (*(file->endl) == '\n')
		return (file->pos > file->endl - file->strbuf);
	return (0);
}

static int		ft_newmem(t_file **file)
{
	if (!(*file = malloc(sizeof(t_file))))
		return (1);
	(*file)->len = BUFFER_SIZE;
	if (!((*file)->strbuf = malloc(((*file)->len + 1) * sizeof(char))))
		return (1);
	(*file)->strbuf[(*file)->len] = '\0';
	(*file)->pos = 0;
	(*file)->endl = (*file)->strbuf;
	(*file)->rsz = 1;
	return (0);
}

static int		ft_return(t_file **pfile, t_file *file, char **line)
{
	if (file->rsz < 0)
		return (-1);
	*line = ft_substr(file->strbuf, 0, file->endl - file->strbuf);
	if ((file->rsz <= 0 || file->pos <= 0))
	{
		if (file->strbuf)
			free(file->strbuf);
		free(file);
		*pfile = NULL;
		return (0);
	}
	file->pos += file->strbuf - file->endl - (file->rsz > 0
			&& *(file->endl) == '\n'
			&& file->pos != file->endl - file->strbuf);
	ft_memcpy(file->strbuf, file->endl + 1, file->pos);
	file->endl = file->strbuf;
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_file	*files[4096];
	int				bufsz;

	bufsz = BUFFER_SIZE;
	if (fd >= 4096 || fd < 0 || line == NULL || bufsz == 0)
		return (-1);
	if (files[fd] && files[fd]->rsz == 0)
		return (0);
	if (!files[fd] && ft_newmem(&files[fd]))
		return (-1);
	while (files[fd]->rsz > 0 && !((ft_newline(files[fd]))))
	{
		while (files[fd]->pos + bufsz > files[fd]->len)
			if (ft_join(files[fd]))
				return (-1);
		files[fd]->rsz = read(fd, files[fd]->strbuf + files[fd]->pos, bufsz);
		files[fd]->pos += files[fd]->rsz;
	}
	return (ft_return(&files[fd], files[fd], line));
}
