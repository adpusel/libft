# include "ft_library_header.h"

// define un enum et je cherche dans ces trois fonction
// j'ai toujours le pb du typage


#define NB_SIZE 22
#define IS_NEG  23
#define IS_U  24

/*
 *  lim de 20 + 1  \\  1                    // 1
 * [la suite de nb, la taille de cette liste, si le nb est neg)
 * */

void get_nb_to_str(long long nb, char *tab)
{
	if (tab[IS_U] == FALSE)
	{
		if (nb < 0)
			nb *= -1;
		tab[IS_NEG] = TRUE;
	}
	while ((unsigned long long) nb)
	{
		tab[(int) tab[NB_SIZE]] = (((unsigned long long) nb % 10) + '0');
		nb /= 10;
		tab[NB_SIZE]++;
	}
}

void printNumber(long long nb)
{
	static char tab[25];

	ft_zero(&tab, sizeof(char) * 25);

	get_nb_to_str(nb, tab);

	ft_printf("%c", tab[IS_NEG] ? '-' : ' ');
	while (tab[NB_SIZE]--)
	{
	    putchar(tab[(int)tab[NB_SIZE]]);
	}
}

int main(int ac, char **ap)
{
	(void) ac;
	(void) ap;
	//	all_test();

	long long b = -3141241;
	printNumber(b);
	printf("\n pf: %lld \n", b);

	return (EXIT_SUCCESS);
}


// je file le tab a mes deux fonctions

// une struct avec les type possible a print, qui en fonction de ce que me demande la str,
// le print, les data de mon parsing sont mis dans un unum ? j'ai juste besoin de mettre un
// longlong pour stocker les data

// je col 10 arg a ma function ca suffit

// les nb, si le nb est signer, ou pas signer je dois pouvoir le
//

// un buffer pour les data a copier

// faire une boucle pour voir si je capte bien les data et faire des err pour voir ci c'est pertinant

// ;

