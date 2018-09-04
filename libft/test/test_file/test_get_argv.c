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

#include "test.h"

char *real_option = "ief";

static char *test_option()
{
	char *options[8] = {
	 "name","-f", "-i", "-e"
	};
	char *finded_option;
	ft_memory(&finded_option,11);

	TEST("test test_dup_mem 1", STR_EQ("super", finded_option) == TRUE)
	return 0;
}


char *all_test_memory()
{
	mu_run_test(test_option);
	return (NULL);
}
