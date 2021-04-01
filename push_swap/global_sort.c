/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:33:47 by zqadiri           #+#    #+#             */
/*   Updated: 2021/03/31 11:26:08 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../checker/checker.h"

int     find_pivot(t_data *m)
{
    int left;
    int right;
    int mid;
    
    left = m->stack_a[0].data;
    right = m->stack_a[m->a_size - 1].data;
    mid = (left + right) / 2;
    
}


void	global_sort(t_data *m)
{
	int minimizing;
    
    if (m->a_size > 200)
        minimizing = 100;
    else
        minimizing = 10; // find the best value 
    ///// choose the pivot 
    m->inst.pivot = find_pivot(m);
}