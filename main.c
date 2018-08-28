#include <fcntl.h>
#include "libft/header/memory.h"
#include "libft/test/test.h"
//#header "libft/ft_library_headerd.h"


// une fonction qui dit fuck au truc fuck

int is_ascii(int c)
{
	return (c >= ' ' && c <= '~');
}




// je recode gnl
// quand j'envois une ligne je vois s'il faut split ou pas.
// je

int main(int ac, char **ap)
{
	(void) ac;
	(void) ap;
//	all_test();
	char *lines;
	size_t t;

	int fd = open_file("/Users/adpusel/Dropbox/42/projects/test_libf/libft/test/test_GNL");
	(void)fd;
	while (ask_gnl(fd, &lines,&t) == OK)
	{
	    ft_printf("%s \n",lines);
	}
}