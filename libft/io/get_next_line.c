/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_argv_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:14:30 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_library_headerd.h"

size_t ft_strclen(char *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int read_left(t_gnl *gnl, char **line, char c)
{
	char *tmp;
	size_t len;
	size_t s_len;
	int ret;

	len = ft_strlen(gnl->str);
	if (c != 0)
	{
		s_len = ft_strclen(gnl->str, c);
		ret = ft_dup_memory((void **) line, gnl->str, s_len);

		tmp = gnl->str;
		if (ret == OK)
			ret = ft_dup_memory((void **) &gnl->str, gnl->str, len - s_len);
		free(tmp);
		return (ret);
	}
	else
	{
		ret = ft_dup_memory((void **) line, gnl->str, len);
		ft_mem_free(&gnl->str);
		return (ret);
	}
}

int read_line(t_gnl *gnl, char **line)
{
	char buf[BUFF_SIZE + 1];
	char *tmp;
	int ret;

	while ((gnl->r_stt = read(gnl->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[gnl->r_stt] = '\0';
		tmp = gnl->str;

		ret = ft_strjoin((void**)&gnl->str, buf, gnl->str);
		ft_mem_free(&tmp);
		if (ret != OK)
		    return (ret);

		if (ft_strclen(gnl->str, '\n') != -1)
			return (read_left(gnl, line, '\n'));
	}
	if (gnl->r_stt == 0 && ft_strlen(gnl->str) > 0)
		return (read_left(gnl, line, 0));
	return (gnl->r_stt);
}

int get_next_line(const int fd, char **line)
{
	static t_gnl gnl;
	static int count = 0;
	int ret;

	if (fd < 0 || !line)
		return (-1);
	if (count == 0)
	{
		gnl.str = ft_memory(0, (void **) &gnl.str);
		gnl.fd = fd;
		++count;
	}
	if (ft_strclen(gnl.str, '\n') != -1)
		return (read_left(&gnl, line, '\n'));
	return (read_line(&gnl, line));
}
