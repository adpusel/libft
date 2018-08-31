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

#include "ft_library_headerd.h"

int ft_str_dup(char **dest, char const *src)
{
	int ret;
	size_t size_str;
	char *str_in;

	size_str = ft_strlen(src);
	ret = ft_memory((void **) &str_in, size_str + 1);
	if (ret == OK)
	{
		ft_memcpy(str_in, src, size_str);
		*dest = str_in;
	}
	return (ret);
}

int ft_str_n_dup(char **dest, char const *src, size_t size)
{
	int ret;
	char *str_in;

	ret = ft_memory((void **) &str_in, size + 1);
	if (ret == OK)
	{
		ft_memcpy(str_in, src, size);
		*dest = str_in;
	}
	return (ret);
}
