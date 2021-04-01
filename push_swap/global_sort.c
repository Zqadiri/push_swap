/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:33:47 by zqadiri           #+#    #+#             */
/*   Updated: 2021/04/01 18:27:34 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../checker/checker.h"

/* function to swap data of two nodes a and b*/

int sorted(int *dup)
{
   	int i;
	int len;

	i = 0;
	while (dup[i])
	{
		if (dup[i] < dup[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

/* Bubble sort the given linked list */

void     find_pivot(t_data *m)
{
	int i;	
	int index;
	int mid;

	i = 0;
	while (i < m->a_size)
	{
		m->dup[i] = m->stack_a[i];
		i++;
	}
	i = 0;
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
	mid = m->dup[m->a_size / 2];		
	i = 0;
	while (i < m->a_size)
	{
		if (m->stack_a[i] == mid)
			m->inst.pivot = i;
		i++;
	}
	printf ("mid : %d\n", mid);
	printf ("index : %d\n", m->inst.pivot);
}

/*
**  sort  stack_b elem and push it to stack a
*/

void	sort_b_move_a(t_data *m)
{
	
}

/*
** apply the best moves to push an element from a to b
*/

void	apply_instruction(t_data *m)
{
	
}

/*
** find the best moves to push an element to the top
*/
void	create_str(t_data *m, char *inst, int len)
{
	int i;

	i = 0;
	if (!(m->inst.best_rot = malloc(sizeof(char) * len + 1)));
		exit (EXIT_FAILURE);
	while (inst[i])
	{
		m->inst.best_rot[i] = inst[i];
		i++;
	}
	m->inst.best_rot[i] = '\0';
}

void	find_best_way_a_b(t_data *m)
{
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
	while (m->stack_a[i])
	{
		if (m->stack_a[i] < m->inst.pivot)
		{
			m->inst.index = i;
			find_best_way_a_b(m);
			apply_instruction(m);
		}
	}	
}

/*
** main function
*/

void	global_sort(t_data *m)
{
	int i;

	i = 0;
	// choose the pivot 
	find_pivot(m);
	push_to_b(m);
	
}