/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_library_header.h"

void
*tab_func_double(void **tab,
	int (*func)(void *, void *), void *ptr, ssize_t lim)
{
	size_t i;

	i = 0;
	if (tab == NULL)
		return (NULL);
	if (lim == END_BY_NULL)
	{
		while (*tab != NULL)
		{
			if (func(*tab, ptr) == TRUE)
				return (*tab);
			++tab;
		}
	}
	else
	{
		while (i < (size_t)lim)
		{
			if (func(tab[i], ptr) == TRUE)
				return (tab[i]);
			++i;
		}
	}
	return (NULL);
}
