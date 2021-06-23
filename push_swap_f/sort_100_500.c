/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:23:32 by zqadiri           #+#    #+#             */
/*   Updated: 2021/06/23 20:52:56 by zqadiri          ###   ########.fr       */
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

void	ft_sorted(t_data *m)
{
	int i;
	int k;
	int tmp;

	i = 0;
	while ( i < m->a_size)
	{
		k = 0;
		while (k < m->a_size - i - 1)
		{
			if (m->dup[k] > m->dup[k + 1])
			{
				tmp = m->dup[k];
				m->dup[k] = m->dup[k + 1];
				m->dup[k + 1] = tmp;
			}
			k++;
		}
		i++;
	}
}

void	move_to_b(t_data *m, int delim)
{
	int step;
	int	i;

	m->pos = 0;
	i = 0;
	step = m->a_size / 5;
	while (i <= delim)
	{
		if (i == delim)
		{
			move_b(m, m->dup[i * step + 1], m->dup[m->dup_size - 1]);
			break;
		}
		if (i == 0)
		{
			move_b(m, m->dup[0], m->dup[step * (i + 1)]);
			i++;
			continue;
		}
		move_b(m, m->dup[i * step + 1], m->dup[step * (i + 1)]);
		i++;
	}
}

void	sort_100_500(t_data *m, int delim, int step)
{
	ft_sorted(m);
	delim = find_init_values(m);
	move_to_b(m, step);
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
