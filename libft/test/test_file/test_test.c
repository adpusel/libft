#include "test.h"

#include "test.h"

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
    link
\*------------------------------------*/
t_dll_l *link_1;
t_dll_l *link_2;
t_dll_l *link_3;
t_dll_l *link_4;
t_dll_l *link_5;

static char *test_LINK_EQ()
{
	char *str = "manger";
	new_dll_l("super", ft_strlen(str), &link_1);
	new_dll_l("suer", ft_strlen(str), &link_2);
	new_dll_l("suer", ft_strlen(str), &link_3);
	TEST("test_LINK_EQ -- 1", LINK_EQ(link_1, link_2))
	TEST("test_LINK_EQ -- 2", LINK_EQ(link_1, link_3))

	//	printf("%s \n", test_1);

	return 0;
}

static char *is_bad_label()
{
	return (NULL);
}

char *all_test_test()
{
	mu_run_test(test_LINK_EQ);
	mu_run_test(is_bad_label);
	return (NULL);
}