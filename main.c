# include "ft_library_header.h"

void get_nb_to_str(long long nb, char *tab);
void printNumber(long long nb);
// en lisant la str je garde la trace de ce que j'ai get pour
// genre 1 -> 33 nombre de char a print la premiere fois puis argv, puis on refais, puis argv ...
// je print tout le but c'est pas de refaire super pf

// sens
#define STR 0
#define UNSIGNED 1
#define NUMBER 2
#define CHAR 3

// manage number
#define NB_SIZE 22
#define IS_NEG  23
#define IS_U  24

typedef struct s_testPr
{
	char *str; // le ptr a write
	int type;  // int la suite //  ou str

	// si
	int length;// la taille de ma str si side, is needed

	// char
	char cha;

	// si c'est color
	int color;
	int pagination;

	// si c'est number
	char tab[25]; // si c'est un nb, sera pointer par str
	char tab_str[22];
} t_pf_data;

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

/*
 * il est trigger des que j'ai une % qui apparait
 * */
int parser(char **str_ptr, t_pf_data *data)
{
	char *str = *str_ptr;

	if (ft_isdigit(*str))
		data->pagination = ft_atoi(str);
	while (ft_isdigit(*str))
		++str;
	if (*str == 'd')
		data->type = NUMBER;
	else if (*str == 'u')
		data->type = UNSIGNED;
	else if (*str == 's')
		data->type = STR;
	else if (*str == 'c')
		data->type = CHAR;
	else
		return 1;
	return 0;
}

int calcul(t_pf_data *all, long long data)
{
	static int i;

	i = 0;
	// nb
	if (all->type == UNSIGNED)
		all->tab[IS_U] = 1;
	if (all->type == UNSIGNED || all->type == NUMBER)
	{
		get_nb_to_str(data, all->tab);
		while (all->tab[NB_SIZE]--)
			all->tab_str[i++] = all->tab[(int) all->tab[NB_SIZE]];
		all->str = all->tab_str;
	}
		// str
	else if (all->type == CHAR)
		all->cha = data;
	else if (all->type == STR)
		all->str = (char *) data;
	else
		return (1);
	return (0);

	// calculer la taille a garder en fonction
	if (all->pagination)
	{
		all->pagination -=
		 ft_strlen(all
					->str);
		if (all->pagination < 0)
			all->
			 pagination = 0;
	}
}

int test_va(char *str, ...)
{
	long long data_var;
	t_pf_data all;

	va_list ap;

	va_start(ap, str);

	while (*str)
	{
		if (*str == '%')
		{
			++str;
			parser(&str, &all);
			data_var = va_arg(ap, long long);
			calcul(&all, data_var);
			// tant que str est different de mon nb j'avance
		}
		str++;
	}

	va_end(ap);
	return (TRUE);
}

int main(int ac, char **ap)
{
	(void) ac;
	(void) ap;

	char *str = "%33d";
	test_va(str, 22);

	return (EXIT_SUCCESS);
}








// la structure pour get les nb,
//  "sens|nb|color|close"













// le parseur de str
// le buffer

// le

// une struct avec les type possible a print, qui en fonction de ce que me demande la str,
// le print, les data de mon parsing sont mis dans un unum ? j'ai juste besoin de mettre un
// longlong pour stocker les data

// je col 10 arg a ma function ca suffit, si plus je lance un malloc

// un buffer pour les data a copier

// faire une boucle pour voir si je capte bien les data et faire des err pour voir ci c'est pertinant

// ;

