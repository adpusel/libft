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

#ifndef ARGV_H
# define ARGV_H
# include <ntsid.h>

# define GNL_BUFF 512

typedef struct		s_gnl
{
	int				start;
	char			*str;
	int				fd;
	int				ret_read;
}					t_gnl;

typedef struct		s_split
{
	char			*line;
	char 			**tab;
	char			*char_skipped;
	int 			size;
} 					t_split;



/*
**    gnl ======================================================================
*/

/**
 *
 * @param fd			get by open file
 * @param line			out for the new line
 * @param nb_line_ptr	nb of the current line
 * @return
 * 			1 ==> while not EFO\n
 * 			0 ==> if EFO
 */
int					get_next_line(const int fd, char **line);
int					ask_gnl(int fd, char **line_ptr, size_t *nb_line_ptr,
 int need_new_line);

int					open_file(char *name);
void				raise_errno(void *ptr);
int					ft_atoi(const char *s);

/**
 * //todo prendre un ptr ou retourne le nb de parametre avancer pour la suite du
 * 	programme
 * \brief get les options de la premiere line donner par argv et
 * @param ac
 * @param av
 * @param found_options
 * @param real_op
 * @return
 */
int					get_option(int ac, char **av, char *found_options,
 char *real_op);

/**
 * \brief loop sur le tab tant que *tab != NULL
 * @param splitted_tab
 * @param found_options
 * @param real_op
 * @return
 */
int get_option_gnl(char **splitted_tab, char *found_options, char *real_op);

/*
**    error funtion
*/
int errno_exit();

#endif
