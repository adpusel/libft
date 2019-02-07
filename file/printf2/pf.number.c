# include "ft_library_header.h"

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

int calcul(t_pf2 *s, long long data)
{
	static int i;

	i = 0;
	if (s->type == UNSIGNED)
		s->tab[IS_U] = 1;
	if (s->type == UNSIGNED || s->type == DECIMAL || s->type == LONG)
	{
		get_nb_to_str(data, s->tab);
		while (s->tab[NB_SIZE]--)
			s->tab_str[i++] = s->tab[(int) s->tab[NB_SIZE]];
		s->tab_str[i] = '\0';
		s->dataParsed = s->tab_str;
	}
		// dataParsed
	else if (s->type == CHAR)
		s->cha = data;
	else if (s->type == STR)
		s->dataParsed = (char *) data;
	else
		return (1);
	return (0);
}

