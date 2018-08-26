/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:46:09 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_library_headerd.h"

int	ft_strjoin(void **dest, char const *s1, char const *s2)
{
	int		ret;
	size_t	size_1;
	size_t	size_2;

	if (s1 == NULL && s2 == NULL)
		return (FAIL);
	size_1 = ft_strlen(s1);
	size_2 = ft_strlen(s2);
	ret = OK;
	ALLOC_MEM(ret, ft_memory(size_1 + size_2 + 1, dest))
	if (ret == OK)
	{
		ft_memcpy(dest, s1, size_1);
		ft_memcpy(dest + size_1, s2, size_2);
	}
	return (ret);
}
