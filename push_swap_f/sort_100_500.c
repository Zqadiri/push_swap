/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:23:32 by zqadiri           #+#    #+#             */
/*   Updated: 2021/05/08 12:16:56 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int *fill_dup(int *array, int len)
{
	int i;
	int j;
	int temp;
	int *new_array;

	new_array = malloc(sizeof(int) * (len - 1));
	i = -1;
	while (++i <= len)
		new_array[i] = array[i];
	i = 0;
	while (i <= len)
	{
		j = i + 1;
		while (j <= len)
		{
			if(new_array[i] > new_array[j])
			{
				temp = new_array[i];
				new_array[i] = new_array[j];
				new_array[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (new_array);
}

int find_position(t_data *m, int el)
{
	int i;

	i = -1;
	while (++i < m->b_size)
	{
		if (m->stack_b[i] == el)
			return (i);
	}
	return (0);
}

int hold_bottom(t_data *m, int start, int end)
{
	int i;

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

int hold_first(t_data *m, int start, int end)
{
	int i;

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

void    calculate_best_way(t_data *m, int top, int bottom)
{
	int from_bottom;

	from_bottom = m->a_size - bottom;
	// printf ("---->: [%d]\n", from_bottom);
	// printf ("----> : [%d]\n",top);
	// 		printf ("a_size : [%d]\n", m->a_size);
	// 	printf ("b_size :[%d]\n", m->b_size);
	if (top == -1 )
		return;
	if (from_bottom < top)
	{
		m->inst.index = bottom;
		m->inst.elem = m->stack_a[m->inst.index];
		create_str(m ,"rra", 3);
	} 
	else
	{
		m->inst.index = top;
		m->inst.elem = m->stack_a[m->inst.index];
		create_str(m ,"ra", 2);
	}
	while (m->inst.index != 0)
	{
		m->inst.index = find_pos(m->stack_a, m->a_size, m->inst.elem);
		if (m->inst.index == 0)
				break;
		if (m->inst.best_rot[0] == 'r' && m->inst.best_rot[1] == 'a')
			rotate_a(m);
		else
			apply_rra(m);
	}
}


void    move_b(t_data *m, int start, int end)
{
	int done;
	int found_it;
	int h_first;
	int h_second;

	done = 1;
	h_second = -1;
	while (m->a_size != 0)
	{
		done++;
		found_it = 0;
		h_first =  hold_first(m, start, end);
		h_second = hold_bottom(m, start, end);
		if (h_first > -1)
			found_it = 1;
		if (h_second > -1)
			found_it = 1;
		calculate_best_way(m, h_first, h_second);
		if (found_it)
			push_b(m);
		else
			break;
	} 
}

void    sort_100_500(t_data *m, int delim, int step)
{
	int start_value;
	int index;
	int *result;

	start_value = 0;
	while (start_value < delim)
	{
		
		move_b(m, start_value, start_value + (step-1));
		start_value += step;
	}
	result = fill_dup(m->stack_b, m->b_size);
	index = 0;
	while (m->b_size != 0)
	{
		index = find_big_one(m->stack_b, m->b_size);
		if (index > (int)(m->b_size / 2))
			while (index < m->b_size)
			{
				index = find_pos(m->stack_b, m->b_size, m->stack_b[index]);
				index++;
				apply_rrb(m);
			}
		else
			while (index != 0)
			{
				index = find_pos(m->stack_b, m->b_size, m->stack_b[index]);
				index--;	
				rotate_b(m);
			}
		push_a(m); 
	}
}
