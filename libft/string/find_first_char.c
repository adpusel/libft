/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:46:02 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_library_header.h"
/**
 * retur un ptr sur la premiere occurance d'en char de la chaine donner en
 * param
 * @param str
 * @param char_researched
 * @return
 */
char *c_first_occur(char *str, char *char_researched)
{
	if (str == NULL)
		return (NULL);
	while (*str)
	{
		if (check_char_into_str(char_researched, *str) == TRUE)
			return(str);
		++str;
	}
	return (NULL);
}
