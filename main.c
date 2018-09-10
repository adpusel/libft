# include "ft_library_header.h"

// une fonction qui dit fuck au truc fuck

int is_ascii(int c)
{
	return (c >= ' ' && c <= '~');
}


// je veux tester les ce qu'il se passe si je force une convertion entre un **ptr et un ***p
// mon changement entrre les ptr,
// je veux allouer un ptr ** en le convertissant en *
// il pointe bien vers le meme emplacement memoir, si je le met a nul ?
// je veux envoyer l'address d'un double ptr a convertir en simple ptr
// c'est cool ca mec !!

int main(int ac, char **ap)
{
	(void) ac;
	(void) ap;
	all_test();
//	char *a = "super";
//	char **a1 = &a;
	// j'ai mon tab, je veux mettre ce ptr dans un autre ptr

//	char **a2 = (char**)&a1;
//	*a2 = NULL;

	return (EXIT_SUCCESS);
}