/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_drop_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:24:37 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dll_deep_header.h"
#include "ft_library_headerd.h"

t_dll_l	*dll_drop_list_one(t_dll *list)
{
	t_dll_l *link;

	link = list->top;
	list->top = NULL;
	list->end = NULL;
	list->length -= 1;
	return (link);
}

t_dll_l	*dll_drop_top(t_dll *list)
{
	t_dll_l *link;
	t_dll_l *new_top;

	if (list->length == 0)
		return (NULL);
	else if (list->length == 1)
		return (dll_drop_list_one(list));
	link = list->top;
	new_top = list->top->next;
	list->top = new_top;
	new_top->prev = NULL;
	reset_ptr_dll_l(link);
	list->length -= 1;
	return (link);
}

t_dll_l	*dll_drop_end(t_dll *list)
{
	t_dll_l *link;
	t_dll_l *new_end;

	if (list->length == 0)
		return (NULL);
	else if (list->length == 1)
		return (dll_drop_list_one(list));
	link = list->end;
	new_end = list->end->prev;
	list->end = new_end;
	new_end->next = NULL;
	reset_ptr_dll_l(link);
	list->length -= 1;
	return (link);
}

static t_dll_l		*drop_index(t_dll *list, size_t index)
{
	t_dll_l *prev_link;
	t_dll_l *link;
	t_dll_l *next_link;

	link = get_good_link(index, list);
	next_link = link->next;
	prev_link = link->prev;
	next_link->prev = prev_link;
	prev_link->next = next_link;
	reset_ptr_dll_l(link);
	list->length -= 1;
	return (link);
}

t_dll_l				*dll_drop_index(t_dll *list, size_t index)
{
	if (list == NULL)
		return (NULL);
	if (list->length == 0)
		return (NULL);
	else if (list->length == 1)
		return (dll_drop_list_one(list));
	else if (index == 0)
		return (dll_drop_top(list));
	else if (index >= list->length)
		return (dll_drop_end(list));
	return (drop_index(list, index));
}
