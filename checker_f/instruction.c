/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:46:51 by zqadiri           #+#    #+#             */
/*   Updated: 2021/04/25 12:48:57 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
** shit down all elements of stack b by 1. The last element
** becomes the first one.
*/

void 	apply_rrb(t_data *m)
{
	int	i;
	int	tmp;

	if (m->b_size == 0)
		return ;
	i = m->b_size - 1;
	tmp = m->stack_b[i];
	while (i > 0)
	{
		m->stack_b[i] = m->stack_b[i - 1];
		i--;
	}
	m->stack_b[0] = tmp;
}

/*
** shit down all elements of stack a by 1. The last element
** becomes the first one.
*/

void 	apply_rra(t_data *m)
{
	int	i;
	int	tmp;

	if (m->a_size == 0)
		return ;
	i = m->a_size - 1;
	tmp = m->stack_a[i];
	while (i > 0)
	{
		m->stack_a[i] = m->stack_a[i - 1];
		i--;
	}
	m->stack_a[0] = tmp;
}

/*
**  shift up all elements of stack a by 1. The first element
**  becomes the last one.
*/

void	rotate_a(t_data *m)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = m->stack_a[0];
	if (m->a_size == 0)
		return ;
	while (i < m->a_size)
	{
		m->stack_a[i - 1] = m->stack_a[i];
		i++;
	}
	m->stack_a[i - 1] = tmp;
}

/*
** shift up all elements of stack b by 1. The first 
** element becomes the last one.
*/

void	rotate_b(t_data *m)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = m->stack_b[0];
	if (m->b_size == 0)
		return ;
	while (i < m->b_size)
	{
		m->stack_b[i - 1] = m->stack_b[i];
		i++;
	}
	m->stack_b[i - 1] = tmp;
}

/*
**  take the first element at the top of a 
**  and put it at the top of b. Do nothing if a is empty.
*/

void	push_b(t_data *m)
{
	int	i;

	i = m->b_size;
	if (m->a_size == 0)
		return ;
	while (i-- > 0)
		m->stack_b[i + 1] = m->stack_b[i];
	m->stack_b[0] = m->stack_a[0];
	i = 0;
	while (++i < m->a_size)
		m->stack_a[i - 1] = m->stack_a[i];
	m->b_size++;
	m->a_size--;
}
