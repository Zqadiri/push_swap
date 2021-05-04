/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_500.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:32:24 by zqadiri           #+#    #+#             */
/*   Updated: 2021/05/04 16:15:02 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

/*
**  stack_a to 4 part -> move the first part to stack_b -> push it back to stack_a
** 	(sort it) and move it to the bottom
**	part_1 0->quarter_1
**	part_2 quarter_1->quarter_2
**	part_3 quarter_2->quarter_3
**  part_4 quarter_3->a_size - 1
*/

void	push_back_sorted(t_data *m)
{
	while (1)
	{
		m->inst.big = find_big_one(m->stack_b, m->b_size);
		if (m->inst.big == 0)
			push_a(m);
		if (m->inst.big == 0 && m->b_size == 0)
		{
			push_a(m);
			break ;
		}
		find_best_way_b_a(m, m->stack_b[m->inst.big]);
		while ((m->inst.big = find_big_one(m->stack_b, m->b_size)) != 0)
		{
			if (m->inst.best_rot[0] == 'r' && m->inst.best_rot[1] == 'b')
				rotate_b(m);
			else
				apply_rrb(m);
		}
		push_a(m);
	}
}

void	move_to_b(t_data *m, int delim)
{
	int i;

	i = 0;
	fill_dup(m, m->stack_a, m->a_size);
	while (i < m->dup_size)
	{
		if (m->dup[i] <= delim)
		{
			find_best_way_a_b(m, m->dup[i]);
			apply_instruction(m);
		}
		i++;
	}
	m->top[m->inst.index] = m->stack_b[0];
	m->inst.index++;
}

void    sort_stack_500(t_data *m)
{
	int i;
	int cursor;
	
	i = 0;
	cursor = 50;
	m->inst.index = 0;
	// split_stack_a(m);
	if (!(m->top = malloc(sizeof(int) * 3)))
		exit(EXIT_FAILURE);
	while (cursor < 500)
	{
		// printf ("-->%d\n", cursor);
		move_to_b(m, cursor);
		cursor+=50;
	}
	while (m->a_size != 0)
	{
		push_b(m);
	}
	push_back_sorted(m);
}	