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

t_dll_l *dll_func
 (
  t_dll *lst,
  int (*func)(t_dll_l *, void *),
  void *data_ptr,
  ssize_t lim
 )
{
	t_dll_l *link;

	link = lst->top;
	lim = lim == ALL_LIST ? lst->length : lim;
	while (lim)
	{
		if (func(link, data_ptr) == TRUE)
			return (link);
		link = link->next;
		--lim;
	}
	return (NULL);
}

t_dll_l *dll_func_where
 (
  t_dll *lst,
  int (*func)(t_dll_l *, void *),
  void *data_ptr,
  ssize_t lim
 )
{
	t_dll_l *link;

	link = lst->where;
	lim = lim == ALL_LIST ? lst->length : lim;
	while (lim && link)
	{
		if (func(link, data_ptr) == TRUE)
			return (link);
		link = link->next;
		--lim;
	}
	return (NULL);
}

size_t dll_func_index
 (
  t_dll *lst,
  int (*func)(t_dll_l *, void *),
  void *data_ptr,
  ssize_t lim
 )
{
	t_dll_l *link;
	size_t	i;

	link = lst->top;
	i = 0;
	lim = lim == ALL_LIST ? lst->length : lim;
	while (lim)
	{
		if (func(link, data_ptr) == TRUE)
			return (i);
		i++;
		link = link->next;
		--lim;
	}
	return (-1);
}