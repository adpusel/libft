/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:46:07 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_library_headerd.h"

int ft_strdup(char **dest, const char *src)
{
	int		ret;
	size_t	lenght_src;

	lenght_src = ft_strlen(src) + 1;
	ret = ft_memory((void **) dest, lenght_src);
	if (ret == OK)
		ft_memcpy(*dest, src, lenght_src);
	return (ret);
}
