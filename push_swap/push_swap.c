/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:34:07 by zqadiri           #+#    #+#             */
/*   Updated: 2021/03/31 10:34:07 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../checker/checker.h"

int find_big_one(t_data *m)
{
	int i;
	int big;

	i = 0;
	big = 0;
	if (m->a_size == 0)
		return (-1);
	int tmp = m->stack_a[i];
	while (i < m->a_size) 
	{
		if (tmp < m->stack_a[i])
		{
			tmp = m->stack_a[i];
			big = i;
		}
		i++;
	}
	return (big);
}

int find_small_one(t_data *m)
{
	int i;
	int small;

	i = 0;
	small = 0;
	if (m->a_size == 0)
		return (-1);
	int tmp = m->stack_a[i];
	while (i < m->a_size) 
	{
		if (tmp > m->stack_a[i])
		{
			tmp = m->stack_a[i];
			small = i;
		}
		i++;
	}
	return (small);
}

/*
** max 2 operations for 3 elements
*/

void sort_stack_3(t_data *m)
{
	int big;

	big = find_big_one(m);
	if (m->a_size == 1)
		return ;
	if (m->a_size == 2)
	{
		if (m->stack_a[0] > m->stack_a[1])
		{
			printf ("rra\n");
			apply_rra(m);
		}
	}
	else if (m->a_size == 3)
	{
		if (big == 0)
		{
			printf ("ra\n");
			rotate_a(m);
		}
		if (big == 1)
		{
			printf ("rra\n");
			apply_rra(m);
		}
		if (m->stack_a[0] > m->stack_a[1])
		{
			printf ("sa\n");
			swap_a(m);
		}
	}
}



void sort_stack_5(t_data *m)
{
	// printf ("sort 3\n");
	int small;
	int minimizing;

	small = find_small_one(m);
	minimizing = 2;
	if (m->a_size == 4)
	{
		if (small > minimizing)
		{
			while (small != 0)
			{
				printf ("rra\n");
				apply_rra (m);
				small = find_small_one(m);
			}
		}
		else
		{
			while (small != 0)
			{
				printf ("ra\n");
				rotate_a (m);
				small = find_small_one(m);
			}
			
		}
		push_b(m);
		printf ("pb\n");
		sort_stack_3 (m);
		push_a(m);
		printf ("pa\n");
	}
	// if (m->a_size == 5)
	// print (m);
}


void begin_sort(t_data *m)
{
	// printf ("begin_sort\n");
	// printf ("the size : %d\n", m->a_size);
	if (is_sorted(m))
		return ;
	if (m->a_size <= 3)
		sort_stack_3(m);
	if (m->a_size > 3 && m->a_size <= 5)
		sort_stack_5(m);
	else
	{
		global_sort(m);
	} 
}

int main(int argc, char *argv[])
{
	t_data m;
	int count;

	count = 1;
	if (argc-- < 2)
		exit (EXIT_FAILURE);
	init_struct(&m, argc);
	if (!(m.stack_a = malloc(sizeof(int) * (argc))))
		exit(EXIT_FAILURE);
	if (!(m.stack_b = malloc(sizeof(int) * (argc))))
		exit(EXIT_FAILURE);
	if (!(m.dup = malloc(sizeof(int) * (argc))))
		exit(EXIT_FAILURE);
	init_stacks(&m, argc);
	while (argv[count])
	{
		is_valid(&m, argv[count]);
		check_duplicate(&m);
		count++;
	}
	begin_sort(&m);
	print (&m);
	if (is_sorted(&m))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (EXIT_SUCCESS);
}
