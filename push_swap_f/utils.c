/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 10:07:52 by zqadiri           #+#    #+#             */
/*   Updated: 2021/05/08 12:15:18 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* sort the dup to find the perfect pivot   */

void	find_pivot(t_data *m)
{
	int	i;
	int	j;
	int	mid;
	int	temp;

	i = 0;
	while (i < m->a_size)
	{
		m->dup[i] = m->stack_a[i];
		i++;
	}
	i = 0;
	while (i < m->a_size)
	{
		j = 0;
		while (j < (m->a_size - i - 1))
		{
			if (m->dup[j] > m->dup[j + 1])
			{
				temp = m->dup[j];
				m->dup[j] = m->dup[j + 1];
				m->dup[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	mid = m->dup[m->a_size / 2];
	m->inst.pivot = mid;
	free (m->dup);
	m->dup = NULL;
}

/*
** take the smallest one from stack_b -> push it back to 
** stack_a -> rotate_a -> do it again (m->size_b == 0)
*/

void	find_best_way_b_a(t_data *m, int elem)
{
	int	i;

	i = 0;
	while (i < m->b_size)
	{
		if (m->stack_b[i] == elem)
		{
			m->inst.index = i;
			m->inst.elem = m->stack_b[i];
			break ;
		}
		i++;
	}
	if (m->inst.index >= m->b_size / 2)
		create_str(m, "rrb", 3);
	else
		create_str(m, "rb", 2);
}

void	move_from_b_to_a(t_data *m)
{
	int	done;

	done = 1;
	m->inst.start_value = m->stack_b[find_small_one(m->stack_b, m->b_size)];
	while (done)
	{
		m->inst.small = find_small_one(m->stack_b, m->b_size);
		if (m->inst.small == 0)
		{
			push_a(m);
			rotate_a(m);
		}
		if (m->inst.small == 0 && m->b_size == 0)
		{
			push_a(m);
			break ;
		}
		find_best_way_b_a(m, m->stack_b[m->inst.small]);
		while ((m->inst.small = find_small_one(m->stack_b, m->b_size)) != 0)
		{
			if (m->inst.best_rot[0] == 'r' && m->inst.best_rot[1] == 'b')
				rotate_b(m);
			else
				apply_rrb(m);
		}
		push_a(m);
		rotate_a(m);
	}
}

void	move_big_elem_b(t_data *m)
{
	int	i;
	int	j;
	int	org_size;

	org_size = m->a_size;
	i = 0;
	while (i < org_size)
	{
		j = 0;
		while (m->stack_a[j] == m->inst.start_value)
			if (m->stack_a[j++] == m->inst.start_value)
				return ;
		push_b(m);
		i++;
	}
}
