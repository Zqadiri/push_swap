/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_100.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:33:47 by zqadiri           #+#    #+#             */
/*   Updated: 2021/04/26 12:38:56 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

/*
** apply the best moves to push an element from a to b
*/

int		find_pos(int *stack, int size, int elem)
{
	
	int i;
	int index;

	i = 0;
	index = 0;
	if (size == 0)
		return (-1);

	while (i < size) 
	{
		if (stack[i] == elem)
			break;
		else
			i++;	
	}
	return (i);
}

void	apply_instruction(t_data *m)
{
	int i;
	
	i = 0;
	if (m->inst.index == 0)
		push_b(m);
	while (m->inst.index != 0)
	{
		m->inst.index = find_pos(m->stack_a, m->a_size, m->inst.elem);
		if (m->inst.index == 0)
			push_b(m);
		if (m->inst.best_rot[0] == 'r' && m->inst.best_rot[1] == 'a')
			rotate_a(m);
		else
			apply_rra(m);
	}
}

/*
** find the best moves to push an element to the top
*/

void	create_str(t_data *m, char *inst, int len)
{
	int i;

	i = 0;
	if (!(m->inst.best_rot = malloc(sizeof(char) * len + 1)))
		exit (EXIT_FAILURE);
	while (inst[i])
	{
		m->inst.best_rot[i] = inst[i];
		i++;
	}
	m->inst.best_rot[i] = '\0';
}

void	find_best_way_a_b(t_data *m, int elem)
{
	int i;

	i = 0;
	while (i < m->a_size)
	{
		if (m->stack_a[i] == elem)
		{
			m->inst.index = i;
			m->inst.elem = m->stack_a[i];
			break;
		}
		i++;
	}
	if (m->inst.index > m->a_size / 2)
		create_str(m ,"rra", 3);
	else
		create_str(m, "ra", 2);
}

/*
** push element below the 
*/

void	push_to_b(t_data *m)
{
	int	done;
	int	i;
	int start_value;

	i = 0;
	done = 1;
	while (i++ < m->a_size)
	{
		if (m->stack_a[i] > m->inst.pivot)
		{
			start_value = m->stack_a[i]; 
			break;
		}
	}
	i = 0;
	while (done)
	{
		if (m->stack_a[0] == start_value)
			i = 1;
		if (m->stack_a[0] > m->inst.pivot)
			rotate_a(m);
		else
			push_b(m);
		if (m->stack_a[0] == start_value && i == 1)
			done = 0;
	}
}

/*
** main function
*/

void	sort_stack_100(t_data *m)
{
	find_pivot(m);
	push_to_b(m);
	move_from_b_to_a(m);
	move_big_elem_b(m);
	move_from_b_to_a(m);
}