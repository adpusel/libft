# include "ft_library_headerd.h"

// une fonction qui dit fuck au truc fuck

int is_ascii(int c)
{
	return (c >= ' ' && c <= '~');
}

// pas besoin de cat ici
int argv_test(char *argv, char *option_finded, char *real_option)
{
	while (*argv)
	{
		if (check_char_into_str(real_option, *argv) == TRUE)
		{
			if (check_char_into_str(option_finded, *argv) == FALSE)
				option_finded[ft_strlen(option_finded)] = *argv;
		}
		else
			return (FAIL);
		++argv;
	}
	return (TRUE);
}

int get_argv(int ac, char *av[], char *option_finded, char *real_op)
{
	// je boucle sur les arguments tant qu'il commence par -, il peuvent etre ensemble ou pas, je revois l'usage quand l'argv est fuck
	int i;

	i = 1;
	while (i < ac)
	{
		if (*av[i] != '-')
			return (TRUE);
		if (argv_test((av[i]) + 1, option_finded, real_op) == FAIL)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

int main(int ac, char **ap)
{
	(void) ac;
	(void) ap;
	//	all_test();
	char *all_op;
	char *real_op = "epd";

	ft_memory((void **) &all_op, 15);
	get_argv(ac, ap, all_op, real_op);
	ft_printf("%s \n", real_op);

	return (EXIT_SUCCESS);
}