#ifndef LIBFT_TEST_H
#define LIBFT_TEST_H

# include "../ft_library_headerd.h"

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

#define STR_EQ(str_1, str_2)  (ft_str_eq(str_1, str_2))
#define STR_NULL(str) str == NULL

/*
**    function
*/
char *all_test_str();
char *all_test_memory();

#endif

