/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:08:58 by zqadiri           #+#    #+#             */
/*   Updated: 2021/03/18 11:05:32 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "checker.h"

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
}

/*
**  take the first element at the top of a 
**  and put it at the top of b. Do nothing if a is empty.
*/

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
	while (i++ <= m->a_size)
		m->stack_a[i - 1] = m->stack_a[i];
	m->b_size++;
	m->a_size--;
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
}

void    get_instruction(t_data *m)
{
	int ret;
	char *line;

	ret = 1;
	if (is_sorted(m))
		return ;
	while (ret)
	{
		ret = get_next_line(&line);
		if (line[0] == 's' && line[1] == 'a')
			swap_a(m);      
		else if (line[0] == 's' && line[1] == 'b')
			swap_b(m);
		else if (line[0] == 's' && line[1] == 's')
		{
			swap_a(m);
			swap_b(m);
		}
		else if (line[0] == 'p' && line[1] == 'a')
			push_a(m);
		else if (line[0] == 'p' && line[1] == 'b')
			push_b(m);
		else if (line[0] == 'r' && line[1] == 'a')
			rotate_a(m);
		else if (line[0] == 'r' && line[1] == 'b')
			rotate_b(m);
		else if (line[0] == 'r' && line[1] == 'r')
		{
			rotate_a(m);
			rotate_b(m);
		}      
		else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
			apply_rra(m);
		else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
			apply_rrb(m);
		else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
		{
			apply_rrb(m);
			apply_rra(m);
		}
		else
			return ;
	}
}
