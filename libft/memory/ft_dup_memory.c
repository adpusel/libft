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

int ft_dup_memory(void **dest, const void *src, size_t size)
{
	void *mem;
	static int ret;

	if (src == NULL)
		return (PTR_NULL);
	ret = ft_memory(&mem, size);
	if (ret == OK)
	{
		ft_memcpy(mem, src, size);
		*dest = mem;
	}
	return (ret);
}
