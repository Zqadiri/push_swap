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

static int  check_overflow(long digit)
{
	if (digit > INT32_MAX || digit < INT32_MIN)
		return (0);
	return (1);
}

int find_big_one(int *stack, int size)
{
	int i;
	int big;

	i = 0;
	big = 0;
	// if (size == 0)
	// 	return (0);
	int tmp = stack[i];
	while (i < size) 
	{
		if (tmp < stack[i])
		{
			tmp = stack[i];
			big = i;
		}
		i++;
	}
	return (big);
}

int find_small_one(int	*stack, int size)
{
	int i;
	int small;

	i = 0;
	small = 0;
	// if (size == 0)
	// 	return (-1);
	int tmp = stack[i];
	while (i < size) 
	{
		if (tmp > stack[i])
		{
			tmp = stack[i];
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

	big = find_big_one(m->stack_a, m->a_size);
	if (m->a_size == 1)
		return ;
	if (m->a_size == 2)
	{
		if (m->stack_a[0] > m->stack_a[1])
		{
			apply_rra(m);
		}
	}
	else if (m->a_size == 3)
	{
		if (big == 0)
			rotate_a(m);
		if (big == 1)
			apply_rra(m);
		if (m->stack_a[0] > m->stack_a[1])
			swap_a(m);
	}
}

void sort_stack_5(t_data *m)
{
	int small;
	int minimizing;

	small = find_small_one(m->stack_a, m->a_size);
	minimizing = 2;
	if (m->a_size == 4)
	{
		if (small > minimizing)
		{
			while (small != 0)
			{
				apply_rra (m);
				small = find_small_one(m->stack_a, m->a_size);
			}
		}
		else
		{
			while (small != 0)
			{
				rotate_a (m);
				small = find_small_one(m->stack_a, m->a_size);
			}
			
		}
		push_b(m);
		sort_stack_3 (m);
		push_a(m);
	}
}

void begin_sort(t_data *m)
{
	if (is_sorted(m))
		return ;
	if (m->a_size <= 3)
		sort_stack_3(m);
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
	// printf ("*********************************************\n");
	if (is_sorted(&m))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (EXIT_SUCCESS);
}    
