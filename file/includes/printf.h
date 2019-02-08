/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sll_construct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:43:59 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_HEADER_H
# define PRINTF_HEADER_H

# include <stdio.h>

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <cxxabi.h>


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

typedef struct s_pf
{
	char *str;
	va_list ap;
	char *dataParsed; // le ptr a write
	int type;  // int la suite //  ou dataParsed

	// si
	int length;// la taille de ma dataParsed si side, is needed

	// char
	char cha;

	// si c'est color
	int color;
	int pagination;

	// si c'est number
	char tab[25]; // si c'est un nb, sera pointer par dataParsed
	char tab_str[22];
} t_pf;

int calcul(t_pf *s, long long data);

int pf(char *str, ...);


#endif
