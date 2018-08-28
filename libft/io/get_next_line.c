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

int read_left(t_gnl *gnl, char **line, ssize_t len_before_bn)
{
	char *tmp;
	int ret;

	if (len_before_bn != -1)
	{
		//		ft_printf("d");
		ret = ft_str_n_dup(line,
						   gnl->str,
						   len_before_bn);
		tmp = gnl->str;
		ret && (ret = ft_str_n_dup(&gnl->str,
								   gnl->str + len_before_bn + 1,
								   ft_strlen(gnl->str) - len_before_bn - 1));
		ft_mem_free(&tmp);
		return (ret);
	}
	else
	{
		ret = ft_str_n_dup(line, gnl->str, ft_strlen(gnl->str));
		ft_mem_free(&gnl->str);
		ret && (ret = ft_memory((void **)&gnl->str, 1));
		return (ret);
	}
}

int read_line(t_gnl *gnl, char **line)
{
	char buf[BUFF_SIZE + 1];
	char *tmp;
	int ret;
	int is_efo;

	ret = OK;
	while ((gnl->ret_read = read(gnl->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[gnl->ret_read] = '\0';
		tmp = gnl->str;
		ret = ft_str_join(&gnl->str, gnl->str, buf);
		ft_mem_free(&tmp);
		if (ret != OK)
			return (ret);
		if ((is_efo = ft_strclen(gnl->str, '\n')) != -1)
			return (read_left(gnl, line, is_efo));
	}
	if (gnl->ret_read == 0 && ft_strlen(gnl->str) > 0)
		return (read_left(gnl, line, -1));
	return (ret == OK ? gnl->ret_read : ret);
}

int init_gnl(int fd, t_gnl *gnl)
{
	int ret;

	gnl->start = 1;
	gnl->fd = fd;
	ret = ft_memory((void **) &gnl->str, 1);
	if (ret != OK)
		return (MEM_LACK);
	return (ret);
}

int get_next_line(const int fd, char **line)
{
	static t_gnl gnl = { 0, 0, 0, 0 };
	int ret;
	int is_efo;

	t_gnl *g = &gnl;
	(void)g;
	if (fd < 0 || !line)
		return (-1);
	if (gnl.start == FALSE && (ret = init_gnl(fd, &gnl)) != OK)
		return (ret);
	if ((is_efo = ft_strclen(gnl.str, '\n')) != -1)
		return (read_left(&gnl, line, is_efo));
	return (read_line(&gnl, line));
}
