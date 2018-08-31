/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_how_many_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:46:04 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_library_headerd.h"

size_t ft_how_many_char(char c, char const *str)
{
	size_t nb;

	nb = 0;
	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str++ == c)
			nb++;
	}
	return (nb);
}
