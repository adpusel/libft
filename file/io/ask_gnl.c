/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_print_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:24:35 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_library_header.h"

int ask_gnl(int fd, char **line_ptr, size_t *nb_line_ptr, int need_new_line)
{
	static int ret = 0;
	static ssize_t nb_line = -1;
	static char *line = NULL;

	if (need_new_line == TRUE)
	{
		ft_str_free(&line);
		ret = get_next_line(fd, &line);
		nb_line += 1;
	}
	*line_ptr = line;
	if (nb_line_ptr)
		*nb_line_ptr = (size_t)nb_line;
	return (ret > 0);
}
