/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:49:07 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_library_header.h"

int ft_str_new(char **dest, size_t size)
{
	void *mem;
	static int ret;

	if (dest == NULL)
		return (PTR_NULL);
	mem = malloc(size == 0 ? 1 : size + 1);
	if (mem == NULL)
	{
		ret = MEM_LACK;
		*dest = NULL;
	}
	else
	{
		ret = TRUE;
		*dest = mem;
	}
	return (ret);
}
