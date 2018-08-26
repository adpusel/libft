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

int ft_dup_memory(void **dest, const void *src, size_t size)
{
	void *mem;
	static int ret;

	mem = malloc(size);
	if (mem == NULL)
	{
		ret = FAIL;
		*dest = NULL;
	}
	else
	{
		ret = TRUE;
		ft_memcpy(*dest, src, size);
	}
	return (ret);
}
