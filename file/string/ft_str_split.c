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
	if (ret == OK)
		ft_memcpy(*dest, src, size);
	return (ret);
}

static int ft_split(char const *str, int size_tab, char *skipped_char,
 char ***tab_ptr)
{
	int i;
	int ret;
	char **tab;

	i = 0;
	ft_skip_char((char **) &str, skipped_char);
	while (str[i] && check_char_into_str(skipped_char, str[i]) == FALSE)
	{
		i++;
	}
	if (*str == '\0')
		return (ft_memory((void **) tab_ptr, sizeof(char *) * (size_tab + 1)));
	ret = ft_split(str + i, size_tab + 1, skipped_char, tab_ptr);
	tab = *tab_ptr;
	if (ret == OK)
		ret = fill_word(tab + size_tab, str, i);
	else
	{
		*tab = NULL;
		return (ret);
	}
	return (ret);
}

int ft_str_split(char *string, char *skipped_char, t_split *split)
{
	int ret;

	if (string == NULL || split->char_skipped == NULL)
		return (PTR_NULL);
	split->char_skipped = skipped_char;
	ret = ft_split(string, 0, split->char_skipped, &split->tab);
	if (ret == OK && split->tab == NULL)
		ret = FAIL;
	split->size = count_split(split->tab);
	return (ret);
}
