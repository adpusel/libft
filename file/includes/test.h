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

#ifndef TEST_H
#define TEST_H

#include "struct/dll_struct.h"

#define TEST(message, test) do { \
    if (!(test)) return message; \
                                    \
} while (0);

#define mu_run_test(TEST) do { char *message = TEST(); tests_run++; \
                                if (message) return message; } while (0)
extern int tests_run;

/*------------------------------------*\
    les defines de str fils
\*------------------------------------*/

# define STR_EQ(str_1, str_2)  (ft_str_eq(str_1, str_2))
# define STR_NULL(str) str == NULL

/*------------------------------------*\
    NB
\*------------------------------------*/
# define NB_EQ(nb_1, nb_2) nb_1 == nb_2

/*------------------------------------*\
    DLL
\*------------------------------------*/
# define LINK_EQ(link_1, link_2)  (ft_link_test(link_1, link_2))
# define LINK_CONTENT_EQ(link_1, link_2)  (ft_link_content(link_1, link_2))
# define LINK_FUNC_EQ(link_1, link_2, func)  (ft_link_test_func(link_1, link_2, func))


/*------------------------------------*\
    STRUCT
\*------------------------------------*/
# define STRUCT_EQ(struct_1, struct_2, func)  (ft_struct_test_func(struct_1, struct_2, func))

/*
**    function =================================================================
*/
int all_test();

/*------------------------------------*\
    helper
\*------------------------------------*/
int ft_link_test(t_dll_l *link_1, t_dll_l *link_2);
int ft_link_test_content(t_dll_l *link_1, t_dll_l *link_2);
int ft_link_test_func(t_dll_l *link_1, t_dll_l *link_2,
	int (*func)(t_dll_l *, t_dll_l *));
int ft_struct_test_func(void *struct_1, void *struct_2,
	int (*func)(void *, void *));
#endif
