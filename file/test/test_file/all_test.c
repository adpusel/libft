
#include "test.h"

char *all_test_str();
char *all_test_memory();
char *all_test_test();

int tests_run = 0;

int all_test()
{

	char *result = all_test_str();
	if (result == NULL)
		result = all_test_memory();
//	if (result == NULL)
//		result = all_test_test();

	if (result != 0)
	{
		printf("%s\n", result);
	}
	else
	{
		printf("ALL TESTS PASSED\n");
	}
	printf("Tests run: %d\n", tests_run);

	return result != 0;
}
