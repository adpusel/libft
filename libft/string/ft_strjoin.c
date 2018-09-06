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

#include "ft_library_header.h"

int	ft_str_join(char **dest, char const *s1, char const *s2)
{
	int		ret;
	size_t	size_1;
	size_t	size_2;

	if (s1 == NULL || s2 == NULL)
	{
		*dest = NULL;
		return (PTR_NULL);
	}
	size_1 = ft_strlen(s1);
	size_2 = ft_strlen(s2);
	ret = ft_memory((void**)dest, size_1 + size_2 + 1);
	if (ret == OK)
	{
		ft_memcpy(*dest, s1, size_1);
		ft_memcpy(*dest + size_1, s2, size_2);
	}
	return (ret);
}
