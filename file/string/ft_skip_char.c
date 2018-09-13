/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_library_header.h"

/**
 * \do 	avance ptr_str a chaque fois que le c match avec la chaine a skip
 * 		s'arrete si end_str
 * @param ptr_str
 * @param skipped_char
 */
void	ft_skip_char(char **ptr_str, char *skipped_char)
{
	while (**ptr_str && check_char_into_str(skipped_char, **ptr_str) == TRUE)
	{
	    ++(*ptr_str);
	}
}