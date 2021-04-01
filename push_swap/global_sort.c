/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:33:47 by zqadiri           #+#    #+#             */
/*   Updated: 2021/04/01 15:03:38 by zqadiri          ###   ########.fr       */
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

int     find_pivot(t_data *m)
{
	// printf ("in");
	int i;

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
	// i = 0;
	// while (i < m->a_size)
	// {
	// 	printf ("%d\n", m->dup[i]);
	// 	i++;
	// }
	return (i);
}


void	global_sort(t_data *m)
{
	// printf ("in");

	// int minimizing;
	
	// if (m->a_size > 200)
	//     minimizing = 100;
	// else
	//     minimizing = 10; // find the best value 
	///// choose the pivot 
	m->inst.pivot = find_pivot(m);
}