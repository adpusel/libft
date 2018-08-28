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



/*
**    function =================================================================
*/
int all_test();


#endif
