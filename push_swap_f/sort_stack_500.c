/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_500.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:32:24 by zqadiri           #+#    #+#             */
/*   Updated: 2021/04/23 15:02:41 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"


/*
** Not working !!!!!
*/
// find_pivot(m);
// int nb_int_mov;
// // int i = 0;
// // int done = 1;
// nb_int_mov = m->a_size;
// m->inst.index = 0;
// m->inst.small = 0;
// while (m->b_size < 250)
// {
// 	m->inst.small = find_small_one(m->stack_a, m->a_size);
// 	// printf ("small :{%d}\n", m->stack_a[m->inst.small]);
// 	// printf ("pivot :{%d}\n", m->inst.pivot);
// 	if (m->stack_a[m->inst.small] < m->inst.pivot)
// 	{
// 		if (m->inst.small == 0)
// 			push_b(m);
// 		else 
// 		{
// 			find_best_way_a_b(m, m->stack_a[m->inst.small]);
// 			apply_instruction(m);
// 		}
// 	}
// }

/*
**  stack_a to 4 part -> move the first part to stack_b -> push it back to stack_a
** 	(sort it) and move it to the bottom
**	part_1 0->quarter_1
**	part_2 quarter_1->quarter_2
**	part_3 quarter_2->quarter_3
**  part_4 quarter_3->a_size - 1
*/

void    sort_stack_500(t_data *m)
{
	int i;
	
	i = 0;
	fill_dup(m, m->stack_a, m->a_size);
}