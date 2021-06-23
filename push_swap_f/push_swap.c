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

#include "../includes/push_swap.h"

void	check_duplicate(t_data *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->a_size)
	{
		j = i + 1;
		while (j < m->a_size)
		{
			if (m->stack_a[i] == m->stack_a[j])
				exit_error(3);
			j++;
		}
		i++;
	}
}

/*
** max 2 operations for 3 elements
*/

void	sort_stack_3(t_data *m)
{
	int	big;

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

void	sort_stack_5(t_data *m)
{
	m->inst.small = 0;
	while (m->b_size < 2)
	{
		m->inst.small = find_small_one(m->stack_a, m->a_size);
		if (m->inst.small == 0)
			push_b(m);
		else
		{
			find_best_way_a_b(m, m->stack_a[m->inst.small]);
			while (m->inst.small != 0)
			{
				m->inst.small = find_small_one(m->stack_a, m->a_size);
				if (m->inst.best_rot[0] == 'r' && m->inst.best_rot[1] == 'a')
					rotate_a(m);
				else
					apply_rra(m);
			}
			push_b(m);
		}
	}
	sort_stack_3(m);
	if (m->stack_b[0] < m->stack_b[1])
		swap_b(m);
	while (m->b_size != 0)
		push_a(m);
}

void 	begin_sort(t_data *m)
{
	if (is_sorted(m))
		return ;
	if (m->a_size <= 3)
		sort_stack_3(m);
	else if (m->a_size == 5)
		sort_stack_5(m);
	else if (m->a_size <= 100)
		sort_100_500(m, 100, 4);
	else if (m->a_size <= 500)
		sort_100_500(m, 500, 11);
}

int	main(int argc, char *argv[])
{
	t_data	m;
	int		count;

	count = 1;
	if (argc == 2)
	{
		is_valid(&m, argv[1]);
		return (EXIT_SUCCESS);
	}
	if (argc <= 2)
		exit (EXIT_FAILURE);
 	init_struct(&m, argc);
	init_stacks(&m, argc);
	while (argv[count])
	{
		is_valid(&m, argv[count]);
		count++;
	}
	check_duplicate(&m);
	if (is_sorted(&m))
		exit(EXIT_SUCCESS);
	begin_sort(&m);
	if (is_sorted(&m))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (EXIT_SUCCESS);
}
