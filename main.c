#include <fcntl.h>
#include "libft/header/memory.h"
#include "libft/test/test.h"
//#header "libft/ft_library_headerd.h"


// une fonction qui dit fuck au truc fuck

int is_ascii(int c)
{
	return (c >= ' ' && c <= '~');
}

int main(int ac, char **ap)
{
	(void) ac;
	(void) ap;
	//	all_test();
	char *lines;
	size_t t;

	int fd = open_file("/Users/adpusel/code/42/libft/libft/test/test_GNL");
	(void) fd;
	while (ask_gnl(0, &lines, &t) == OK)
	{
//				ft_printf("d");
		printf("%s \n", lines);
	}
}