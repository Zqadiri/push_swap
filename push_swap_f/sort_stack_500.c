/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_500.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:32:24 by zqadiri           #+#    #+#             */
/*   Updated: 2021/04/25 09:06:14 by zqadiri          ###   ########.fr       */
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

void	split_stack_a(t_data *m)
{
	// duplicate stack_a sort it and find midpoints
	int i;
	
	if (!(m->mid_point = malloc(sizeof(int) * 3)))
		exit(EXIT_FAILURE);
	fill_dup(m, m->stack_a, m->a_size);
	for (i = 0; i < m->a_size; i++)
	{
		for (int j = 0; j < (m->a_size - i - 1); j++)
		{
			if (m->dup[j] > m->dup[j + 1])
			{
				int temp = m->dup[j];
				m->dup[j] = m->dup[j + 1];
				m->dup[j + 1] = temp;
			}
		}
	}
	m->mid_point[0] = m->dup[m->a_size / 4];
	m->mid_point[1] = m->dup[m->a_size / 2];
	m->mid_point[2] = m->mid_point[1] + m->mid_point[0];
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
			printf ("delim :%d\n", delim);
			find_best_way_a_b(m, m->dup[i]);
			apply_instruction(m);
		}
		i++;
	}
}

void    sort_stack_500(t_data *m)
{
	int i;
	int cursor;
	
	i = 0;
	cursor = -1;
	find_pivot(m);
	split_stack_a(m);
	// chane the funtion parameters and turn it into a recursion
	move_to_b(m,  m->mid_point[0]);
	move_to_b(m,  m->mid_point[1]);
	move_to_b(m,  m->mid_point[2]);
	while (m->a_size != 0)
	{
		push_b(m);
	}
	// printf ("{%d}\n", m->inst.pivot);
	// while (m->b_size < 100) // work later with quater of the size of stack
	// {
	// 	m->inst.index = find_small_one(m->stack_a, m->a_size); 
	// 	if (m->stack_a[m->inst.index] > m->inst.pivot)
	// 		break ;
	// 	if (m->inst.index == 0)
	// 		push_b(m);
	// 	else 
	// 	{
	// 		find_best_way_a_b(m, m->stack_a[m->inst.index]);
	// 		m->inst.elem = m->stack_a[m->inst.index];
	// 		// think of another condition
	// 		while (m->inst.index != 0)
	// 		{
	// 			m->inst.index = find_pos(m->stack_a, m->a_size, m->inst.elem);
	// 			if (m->inst.index == 0)
	// 				push_b(m);
	// 			if (m->inst.best_rot[0] == 'r' && m->inst.best_rot[1] == 'a')
	// 				rotate_a(m);
	// 			else
	// 				apply_rra(m);
	// 		}
	// 		// printf ("[%d]\n", m->inst.index);
	// 		// printf ("{%d}\n",m->stack_a[m->inst.index]);
	// 	}
	// }
}				