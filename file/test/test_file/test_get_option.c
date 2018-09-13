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

# include "ft_library_header.h"

char *real_option = "ief";

static char *test_option()
{
	// test tout va bien
	char *options[8] = {
	 "name", "-f", "-i", "-e", "stop"
	};
	char *found_option;
	ft_str_new(&found_option, 10);

	get_option(4, options, found_option, real_option);
	TEST("test get_option -- 1", STR_EQ("fie", found_option) == TRUE)


	// test option en double
	char *option_1[8] = {
	 "name", "-fiii", "-fffieeee", "-iiieff", "stop"
	};
	ft_str_new(&found_option, 10);

	get_option(4, option_1, found_option, real_option);
	TEST("test get_option -- 2", STR_EQ("fie", found_option) == TRUE)

	// test wrong option l
	char *option_2[8] = {
	 "name", "-iii", "-ieeee", "-liiieff", "stop"
	};
	ft_str_new(&found_option, 10);

	get_option(4, option_2, found_option, real_option);
	TEST("test get_option -- 2", STR_EQ("ie", found_option) == TRUE)

	// no option
	char *option_3[8] = {
	 "name", "iii", "-ieeee", "-liiieff", "stop"
	};
	ft_str_new(&found_option, 10);

	get_option(4, option_3, found_option, real_option);
	TEST("test get_option -- 2", STR_EQ("", found_option) == TRUE)

	return 0;
}

char *all_test_memory()
{
	mu_run_test(test_option);
	return (NULL);
}
