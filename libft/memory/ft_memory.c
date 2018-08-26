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

#include <stdlib.h>
#include <define.h>
#include "string.h"
#include "../header/memory.h"

int ft_memory(size_t size, void **mem_ptr)
{
	void *mem;
	static int ret;

	mem = malloc(size);
	if (mem == NULL)
	{
		ret = MEM_LACK;
		*mem_ptr = NULL;
	}
	else
	{
		ft_memset(mem, 0, size);
		*mem_ptr = mem;
		ret = OK;
	}
	return (ret);
}
