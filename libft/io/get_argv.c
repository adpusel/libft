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

int argv_test(char *argv, char *found_options, char *real_option)
{
	while (*argv)
	{
		if (check_char_into_str(real_option, *argv) == TRUE)
		{
			if (check_char_into_str(found_options, *argv) == FALSE)
				found_options[ft_strlen(found_options)] = *argv;
		}
		else
			return (FAIL);
		++argv;
	}
	return (TRUE);
}

int get_option(int ac, char **av, char *found_options, char *real_op)
{
	static int i;

	i = 1;
	while (i < ac)
	{
		if (*av[i] != '-')
			return (TRUE);
		if (argv_test((av[i]) + 1, found_options, real_op) == FAIL)
			return (FALSE);
		++i;
	}
	return (TRUE);
}