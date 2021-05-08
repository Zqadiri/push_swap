/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:23:32 by zqadiri           #+#    #+#             */
/*   Updated: 2021/05/08 17:14:23 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	calculate_best_way_h(t_data *m)
{
	while (m->inst.index != 0)
	{
		m->inst.index = find_pos(m->stack_a, m->a_size, m->inst.elem);
		if (m->inst.index == 0)
			break ;
		if (m->inst.best_rot[0] == 'r' && m->inst.best_rot[1] == 'a')
			rotate_a(m);
		else
			apply_rra(m);
	}	
}

void	calculate_best_way(t_data *m, int top, int bottom)
{
	int	from_bottom;

	from_bottom = m->a_size - bottom;
	if (top == -1 )
		return ;
	if (from_bottom < top)
	{
		m->inst.index = bottom;
		m->inst.elem = m->stack_a[m->inst.index];
		create_str(m, "rra", 3);
	}
	else
	{
		m->inst.index = top;
		m->inst.elem = m->stack_a[m->inst.index];
		create_str(m, "ra", 2);
	}
	calculate_best_way_h(m);
}

void	move_b(t_data *m, int start, int end)
{
	int	done;
	int	found_it;
	int	h_first;
	int	h_second;

	done = 1;
	h_second = -1;
	while (m->a_size != 0)
	{
		done++;
		found_it = 0;
		h_first = hold_first(m, start, end);
		h_second = hold_bottom(m, start, end);
		if (h_first > -1)
			found_it = 1;
		if (h_second > -1)
			found_it = 1;
		calculate_best_way(m, h_first, h_second);
		if (found_it)
			push_b(m);
		else
			break ;
	}
}

void	move_to_b(t_data *m, int delim, int step)
{
	while (m->inst.start_value < delim)
	{
		move_b(m, m->inst.start_value, m->inst.start_value + (step - 1));
		m->inst.start_value += step;
	}
}

int	find_init_values(t_data *m)
{
	int	delim;

	m->inst.start_value = m->stack_a[find_small_one(m->stack_a, m->a_size)];
	delim = m->stack_a[find_big_one(m->stack_a, m->a_size)];
	return (delim);
}

void	sort_100_500(t_data *m, int delim, int step)
{
	delim = find_init_values(m);
	move_to_b(m, delim, step);
	m->pos = 0;
	while (m->b_size != 0)
	{
		m->pos = find_big_one(m->stack_b, m->b_size);
		if (m->pos > (int)(m->b_size / 2))
		{
			while (m->pos < m->b_size)
			{
				m->pos = find_pos(m->stack_b, m->b_size, m->stack_b[m->pos]);
				m->pos++;
				apply_rrb(m);
			}
		}
		else
		{
			while (m->pos != 0)
			{
				m->pos = find_pos(m->stack_b, m->b_size, m->stack_b[m->pos]);
				m->pos--;
				rotate_b(m);
			}
		}
		push_a(m);
	}
}
