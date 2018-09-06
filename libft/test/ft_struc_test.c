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

#include "ft_library_header.h"

int ft_struct_test_func(void *struct_1, void *struct_2,
	int (*func)(void *, void *))
{
	int res_cmp;

	if (struct_1 == NULL || struct_2 == NULL)
		return (PTR_NULL);
	res_cmp = func(struct_1, struct_2);
	return (res_cmp);
}