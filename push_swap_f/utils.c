/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 10:07:52 by zqadiri           #+#    #+#             */
/*   Updated: 2021/05/08 17:35:08 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	hold_bottom(t_data *m, int start, int end)
{
	int	i;

	i = m->a_size - 1;
	while (i >= 0)
	{
		if (m->stack_a[i] >= start && m->stack_a[i] <= end)
		{
			return (i);
		}
		i--;
	}
	return (-1);
}

int	hold_first(t_data *m, int start, int end)
{
	int	i;

	i = 0;
	while (i <= m->a_size)
	{
		if (m->stack_a[i] >= start && m->stack_a[i] <= end)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

void	create_str(t_data *m, char *inst, int len)
{
	int	i;

	i = 0;
	m->inst.best_rot = malloc(sizeof(char) * len + 1);
	if (m->inst.best_rot == NULL)
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
	int	i;

	i = 0;
	while (i < m->a_size)
	{
		if (m->stack_a[i] == elem)
		{
			m->inst.index = i;
			m->inst.elem = m->stack_a[i];
			break ;
		}
		i++;
	}
	if (m->inst.index > m->a_size / 2)
		create_str(m, "rra", 3);
	else
		create_str(m, "ra", 2);
}

int	find_init_values(t_data *m)
{
	int	delim;

	m->inst.start_value = m->stack_a[find_small_one(m->stack_a, m->a_size)];
	delim = m->stack_a[find_big_one(m->stack_a, m->a_size)];
	return (delim);
}
