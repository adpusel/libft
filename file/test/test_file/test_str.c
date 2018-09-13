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

/*------------------------------------*\
    lines
\*------------------------------------*/
char *test_1;

char *test_2;

char *test_3;

char *test_4;

char *test_5;

/*------------------------------------*\
    ret
\*------------------------------------*/
char *str_ret_1;

char *str_ret_2;

char *str_ret_3;

char *str_ret_4;

char *str_ret_5;

/*------------------------------------*\
    ret
\*------------------------------------*/
int ret_1;

int ret_2;

int ret_3;

int ret_4;

int ret_5;

/*------------------------------------*\
    function test
\*------------------------------------*/
int print_tab_char(void *tab_ptr, void *ptr)
{
	(void) ptr;
	printf("-%s ", tab_ptr);
	return (FALSE);
}

static char *test_join_str()
{
	int *ret;
	(void) ret;
	char *test;
	(void) test;

	ret_1 = ft_str_join(&test_1, "super", NULL);
	ret_2 = ft_str_join(&test_2, NULL, "super");
	ret_3 = ft_str_join(&test_3, "sup", "er");
	ret_4 = ft_str_join(&test_4, "", "super");
	ret_5 = ft_str_join(&test_5, "super", "");

	test = test_1;
	ret = &ret_1;

	TEST("test join 1", STR_EQ(NULL, test_1) == PTR_NULL && ret_1 == PTR_NULL)
	TEST("test join 2", STR_EQ(NULL, test_2) == PTR_NULL && ret_2 == PTR_NULL)
	TEST("test join 3", STR_EQ("super", test_3) == TRUE && ret_3 == TRUE)
	TEST("test join 4", STR_EQ("super", test_4) == TRUE && ret_4 == TRUE)
	TEST("test join 5", STR_EQ("super", test_5) == TRUE && ret_5 == TRUE)

	return 0;
}

static char *split_str()
{
	int ret;
	char **split_tab;
	char *skipped = " 	";
	char *chaine;
	int nb;

	char *empty = " 	   ";
	ret = ft_str_split(empty, skipped, &split_tab, &nb);
	TEST("split_str -- 1", *split_tab == NULL && nb == FAIL)
	printf(" \n");
	//

	char *one = "   		super   		";
	ret = ft_str_split(one, skipped, &split_tab, &nb);
	TEST("split_str -- 2", STR_EQ("super", *split_tab) == TRUE &&
	nb == 1)
	printf(" \n");
	//
	//
	chaine = "super mager pas cher";
	ret = ft_str_split(chaine, skipped, &split_tab, &nb);
	tab_func_double((void **) split_tab, print_tab_char, NULL, END_BY_NULL);
	printf(" \n");


	//	char *one_1 = "one";
	//	char *one_space = " one ";



	return (NULL);
}

char *all_test_str()
{
	mu_run_test(test_join_str);
	mu_run_test(split_str);
	return (NULL);
}