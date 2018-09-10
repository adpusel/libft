/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_library_header.h"

#ifndef TAB_H
#define TAB_H


/**
 * \brief 	if END_BY_NULL, stop when *tab == NULL
 * 			give all *tab at the func, if it return TRUE, stop loop and return
 * 			*tab
 */
void
*tab_func_double(void **tab,
 int (*func)(void *, void *), void *ptr, ssize_t lim);

#endif
