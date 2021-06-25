/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 09:07:16 by zqadiri           #+#    #+#             */
/*   Updated: 2021/03/18 10:57:57 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	init_(t_data *m, int argc )
{
	m->pos = -1;
	m->a_size = argc;
	m->b_size = 0;
	m->stack_b = NULL;
	m->stack_a = NULL;
	m->stack_a = malloc(sizeof(int) * (argc));
	if (m->stack_a == NULL)
		exit(EXIT_FAILURE);
	ft_memset(m->stack_a, 0, argc);
	m->stack_b = malloc(sizeof(int) * (argc));
	if (m->stack_b == NULL)
		exit(EXIT_FAILURE);
	ft_memset(m->stack_b, 0, argc);
}

int	is_sorted(t_data *m)
{
	int	i;
	int	len;

	i = 0;
	len = m->a_size;
	if (m->b_size != 0)
		return (0);
	while (i < len - 1)
	{
		if (m->stack_a[i] < m->stack_a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void	help(char *inst, t_data *m)
{
	if (!ft_strcmp(inst, "rr"))
	{
		rotate_a(m);
		rotate_b(m);
	}
	else if (!ft_strcmp(inst, "rra"))
		apply_rra(m);
	else if (!ft_strcmp(inst, "rrb"))
		apply_rrb(m);
	else if (!ft_strcmp(inst, "rrr"))
	{
		apply_rrb(m);
		apply_rra(m);
	}
	else
		exit_error();
}
