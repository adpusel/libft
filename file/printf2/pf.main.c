# include "ft_library_header.h"

/*
 * il est trigger des que j'ai une % qui apparait
 * */
int parser(t_pf2 *s)
{
	char *str = s->str;

	if (ft_isdigit(*str))
		s->pagination = ft_atoi(str);
	while (ft_isdigit(*str))
		++str;
	if (*str == 'd')
		s->type = DECIMAL;
	else if (*str == 'l')
		s->type = LONG;
	else if (*str == 'u')
		s->type = UNSIGNED;
	else if (*str == 's')
		s->type = STR;
	else if (*str == 'c')
		s->type = CHAR;
	else
	{
		ft_putstr_fd("pb dans le parcing des argv printf", 2);
		exit(EXIT_FAILURE);
	}
	return 0;
}

int print_arg(t_pf2 *s)
{
	if (s->pagination)
	{
		if (s->tab[IS_NEG])
			s->pagination -= 1;
		if (s->type != CHAR)
			s->pagination -= ft_strlen(s->dataParsed);
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
		ft_putstr_fd(s->dataParsed, 1);

	return (0);
}

void parse_and_print(t_pf2 *s)
{
	long long data_var;

	ft_zero(((char *) s + sizeof(char *) + sizeof(va_list)), sizeof(t_pf2) - (sizeof(char *) + sizeof(va_list)));
	++(s->str);
	parser(s);
	if (s->type == DECIMAL)
		data_var = va_arg(s->ap, int);
	else
		data_var = va_arg(s->ap, long long);
	calcul(s, data_var);
	print_arg(s);
	while (*s->str != s->type)
		s->str++;
	s->str++;
}

int pf(char *str, ...)
{
	t_pf2 s;

	va_start(s.ap, str);
	s.str = str;
	while (s.str)
	{
		if (*s.str == '%')
		{
			parse_and_print(&s);
		}
		if (*s.str == 0)
			break;
		ft_putchar(*s.str);
		s.str++;
	}
	va_end(s.ap);
	return (TRUE);
}
