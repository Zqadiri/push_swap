/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:38:10 by zqadiri           #+#    #+#             */
/*   Updated: 2021/04/21 11:41:53 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/*
** shit down all elements of stack b by 1. The last element
** becomes the first one.
*/

void 	apply_rrb(t_data *m)
{
	register int i;
	register int tmp;

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
	printf ("rrb\n");
}

/*
** shit down all elements of stack a by 1. The last element
** becomes the first one.
*/

void 	apply_rra(t_data *m)
{
	int i;
	int tmp;

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
	printf("rra\n");
}

/*
** swap the first 2 elements at the top of stack a.
** Do nothing if there is only one or no elements
*/

void    swap_a(t_data *m)
{
	int  tmp;

	if (m->a_size < 2)
		exit(EXIT_SUCCESS);
	else
	{
		tmp = m->stack_a[0];
		m->stack_a[0] = m->stack_a[1];
		m->stack_a[1] = tmp;
	}
	printf ("sa\n");
}

/*
** swap the first 2 elements at the top of stack b.
** Do nothing if there is only one or no elements
*/

void    swap_b(t_data *m)
{
	int  tmp;

	if (m->stack_b == NULL)
		exit (EXIT_SUCCESS);
	if (m->b_size < 2)
		exit(EXIT_SUCCESS);
	else
	{
		tmp = m->stack_b[0];
		m->stack_b[0] = m->stack_b[1];
		m->stack_b[1] = tmp;
	}
	printf ("sb\n");
}

/*
**  take the first element at the top of b 
**  and put it at the top of a. Do nothing if b is empty.
*/

void    push_a(t_data *m)
{
	int i;

	i = m->a_size;
	if (m->b_size == 0)
		return ;
	while (i-- > 0)
		m->stack_a[i + 1] = m->stack_a[i];
	m->stack_a[0] = m->stack_b[0];
	i = 0;
	while (i++ <= m->b_size)
		m->stack_b[i - 1] = m->stack_b[i];
	m->a_size++;
	m->b_size--;
	printf ("pa\n");
}

/*
**  take the first element at the top of a 
**  and put it at the top of b. Do nothing if a is empty.
*/

//functional programming
void    push_b(t_data *m)
{
	int i;

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
	printf ("pb\n");
}

/*
**  shift up all elements of stack a by 1. The first element
**  becomes the last one.
*/

void    rotate_a(t_data *m)
{
	int i;
	int tmp;

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
	printf ("ra\n");
}

/*
** shift up all elements of stack b by 1. The first 
** element becomes the last one.
*/

void    rotate_b(t_data *m)
{
	int i;
	int tmp;

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
	printf ("rb\n");
}