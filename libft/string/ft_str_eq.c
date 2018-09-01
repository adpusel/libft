/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_streq.c                                        :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:46:06 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
# include "ft_library_headerd.h"

int	ft_str_eq(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (PTR_NULL);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 == *s2 ? OK : FAIL);
}
