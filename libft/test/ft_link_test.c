/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:46:02 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_library_headerd.h"

int ft_link_test(t_dll_l *link_1, t_dll_l *link_2)
{
	int res_cmp;

	res_cmp = link_1->content_size == link_2->content_size;
	if (res_cmp)
		res_cmp = ft_memcmp(link_1, link_2, sizeof(t_dll_l));
	if (res_cmp)
		res_cmp = ft_memcmp(link_1->content, link_2->content, link_1->content_size);
	return (res_cmp);
}