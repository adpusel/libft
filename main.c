# include "ft_library_header.h"

void get_nb_to_str(long long nb, char *tab);

// sens
#define STR 's'
#define UNSIGNED 'u'
#define DECIMAL 'd'
#define CHAR 'c'
#define LONG 'l'

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
} t_pf2;

/*
 *  lim de 20 + 1  \\  1                    // 1
 * [la suite de nb, la taille de cette liste, si le nb est neg)
 * */

void get_nb_to_str(long long nb, char *tab)
{
	if (nb == 0)
	{
		tab[(int) tab[NB_SIZE]] = '0';
		tab[NB_SIZE]++;
	}
	if (tab[IS_U] == FALSE && nb < 0)
	{
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
int parser(char **str_ptr, t_pf2 *data)
{
	char *str = *str_ptr;

	if (ft_isdigit(*str))
		data->pagination = ft_atoi(str);
	while (ft_isdigit(*str))
		++str;
	if (*str == 'd')
		data->type = DECIMAL;
	else if (*str == 'l')
		data->type = LONG;
	else if (*str == 'u')
		data->type = UNSIGNED;
	else if (*str == 's')
		data->type = STR;
	else if (*str == 'c')
		data->type = CHAR;
	else
	{
		ft_putstr_fd("pb dans le parcing des argv printf", 2);
		exit(EXIT_FAILURE);
	}
	return 0;
}

int calcul(t_pf2 *s, long long data)
{
	static int i;

	i = 0;
	// nb
	if (s->type == UNSIGNED)
		s->tab[IS_U] = 1;
	if (s->type == UNSIGNED || s->type == DECIMAL || s->type == LONG)
	{
		get_nb_to_str(data, s->tab);
		while (s->tab[NB_SIZE]--)
			s->tab_str[i++] = s->tab[(int) s->tab[NB_SIZE]];
		s->tab_str[i] = '\0';
		s->str = s->tab_str;
	}
		// str
	else if (s->type == CHAR)
		s->cha = data;
	else if (s->type == STR)
		s->str = (char *) data;
	else
		return (1);
	return (0);
}

int print_arg(t_pf2 *s)
{
	if (s->pagination)
	{
		if (s->tab[IS_NEG])
			s->pagination -= 1;
		if (s->type != CHAR)
			s->pagination -= ft_strlen(s->str);
		else
			s->pagination -= 1;
	}

	if (s->pagination < 0)
		s->pagination = 0;
	while (s->pagination--)
		ft_putchar(' ');
	if (s->tab[IS_NEG])
		ft_putchar('-');

	if (s->type == CHAR)
		ft_putchar(s->cha);
	else
		ft_putstr_fd(s->str, 1);

	return (0);
}

int test_va(char *str, ...)
{
	long long data_var;
	t_pf2 s;

	va_list ap;

	va_start(ap, str);

	while (*str)
	{
		if (*str == '%')
		{
			ft_zero(&s, sizeof(t_pf2));
			++str;
			parser(&str, &s);
			if (s.type == DECIMAL)
				data_var = va_arg(ap, int);
			else
				data_var = va_arg(ap, long long);
			calcul(&s, data_var);

			// print
			print_arg(&s);

			while (*str != s.type)
				str++;
			str++;
		}

		if (*str == 0)
			break;

		ft_putchar(*str);
		str++;
	}

	va_end(ap);
	return (TRUE);
}

int main(int ac, char **ap)
{
	(void) ac;
	(void) ap;

	char *str = "%33d, super sayan, %s,  %0l, eeaoeouau , %22c";
	test_va(str, 0, "lalara", -93871293712837, 'a');

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

