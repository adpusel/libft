/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:48 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_library_header.h"
// TODO : tester si le memory set bien a null en cas d'errer le mallc

void ft_free_split(char ***t)
{
	char **tab;

	if (t == NULL)
		return;
	tab = *t;
	if (tab)
	{
		while (*tab != NULL)
		{
			free(*tab);
			tab++;
		}
		free(*t);
		*t = NULL;
	}
}

int count_split(char **tab)
{
	int i;

	i = 0;
	if (tab == NULL)
		return (FAIL);
	while (tab[i])
	{
		i++;
	}
	return (i);
}

int fill_word(char **dest, const char *src, size_t size)
{
	int ret;

	ret = ft_str_new(dest, size);
	ft_memcpy(*dest, src, size);
	return (ret);
}

// j'ai deja 3 argv sur cette struct
// je dois pouvoir convertir en simple ptr, comme je demande juste un block de memoir. c'est trop chiant sinon !!
// je fais le test avec les deux malloc
// trop relou a faire en recursif ce truc // un peu comme gnl,
static int ft_split(char const *str, int size_tab, char *skipped_char,
 char ***tab_ptr)
{
	int i;
	int ret;
	char **tab;

	i = 0;
	ft_skip_char((char **) &str, skipped_char);

	// taille du mot
	while (str[i] && check_char_into_str(skipped_char, str[i]) == FALSE)
	{
		i++;
	}

	// arret
	if (*str == '\0')
		return (ft_memory((void **) tab_ptr, sizeof(char *) * (size_tab + 1)));

	// suite
	ret = ft_split(str + i, size_tab + 1, skipped_char, tab_ptr);
	tab = *tab_ptr;
	// si ok memoire, fill word
	if (ret == OK)
	{
		ret = fill_word(tab + size_tab, str, i);
	}

		// si mem fuck
	else
	{
		*tab = NULL;
		return (ret);
	}
	return (ret);
}

int ft_str_split(char const *string, char *char_skipped, char ***tab,
 int *size_tab)
{
	int ret;

	if (string == NULL || char_skipped == NULL)
		return (PTR_NULL);
	ret = ft_split(string, 0, char_skipped, tab);
	if (ret == OK && *tab == NULL)
		ret = FAIL;
	if (size_tab != NULL)
		*size_tab = count_split(*tab);
	return (ret);
}

