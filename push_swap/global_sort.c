/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:33:47 by zqadiri           #+#    #+#             */
/*   Updated: 2021/04/04 12:29:00 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../checker/checker.h"

/*
**
*/

void	move_from_b_to_a(t_data *m)
{

	
}


/*
** apply the best moves to push an element from a to b
*/

int		find_pos(t_data *m)
{
	int i;
	int index;

	i = 0;
	index = 0;
	if (m->a_size == 0)
		return (-1);
	while (i < m->a_size) 
	{
		if (m->stack_a[i] == m->inst.elem)
			break;
		else
			i++;	
	}
	// printf ("m->inst.elem : %d\n", m->inst.elem);
	// printf ("m->inst.index %d\n", m->inst.index);
	return (i);
}

void	apply_instruction(t_data *m)
{
	int i;
	int index;
	
	i = 0;
	// printf ("--> %s\n", m->inst.best_rot);
	while (m->inst.index != 0)
	{
		m->inst.index = find_pos(m);
		if (m->inst.index == 0)
			push_b(m);
		if (m->inst.best_rot[0] == 'r' && m->inst.best_rot[1] == 'a')
		{
			// printf ("ra++\n");
			rotate_a(m);
			// printf ("------\n");
			// print(m);
		}
		else
		{
			// printf ("rra++\n");
			apply_rra(m);
		}
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
			// printf ("elem : %d\n", m->inst.elem);
			// printf ("index : %d\n", m->inst.index);
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
	int i;

	i = 0;
	fill_dup(m);
	while (i < m->dup_size)
	{
		if (m->dup[i] < m->inst.pivot)
		{
			find_best_way_a_b(m, m->dup[i]);
			apply_instruction(m);
 			// printf ("%s\n", m->inst.best_rot);
		}
		i++;
	}
}

/*
** main function
*/

void	global_sort(t_data *m)
{
	int i;

	i = 0;
	find_pivot(m);
	push_to_b(m);
	move_from_b_to_a(m);
}