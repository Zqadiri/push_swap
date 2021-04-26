/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:27:21 by zqadiri           #+#    #+#             */
/*   Updated: 2021/04/25 16:54:08 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void    is_valid(t_data *m, char *arg)
{
	long digit;
	int i;
	int signe;

	i = 0;
	digit = 0;
	signe = 1;
	if (arg[i] == '-')
	{
		signe = -1;
		i++;
	}	
	while (arg[i] != '\0')
	{
		if (arg[i] >= '0' && arg[i] <= '9')
		{
			digit = (digit * 10) + arg[i] - '0';
		}	
		else
			error_code(1);
		i++;
	}
	if (!(check_overflow(digit * signe)))
		error_code (2);
	m->pos++;
	m->stack_a[m->pos] = (int)digit * signe;

}

void        init_struct(t_data *m, int argc )
{
	m->pos = -1;
	m->a_size = argc;
	m->b_size = 0;
	m->stack_b = NULL;
	m->stack_a = NULL;
	m->inst.index = -1;
	m->inst.pivot = -1;
	m->inst.best_rot = NULL;
}

void		init_stacks(t_data *m, int argc)
{
	int i;
	
	i = 0;
	while (i < argc)
	{
		m->stack_a[i] = 0;
		i++;
	}
	i = 0;
	while (i < argc)
	{
		m->stack_b[i] = 0;
		i++;
	}
	i = 0;
	while (i < argc)
	{
		m->dup[i] = 0;
		i++;
	}
}

int		is_sorted(t_data *m)
{
	int i;
	int len;

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

void    check_duplicate(t_data *m)
{
	int i;
	int j;

	i = 0;
	while (i < m->a_size)
	{
		j = i + 1;
		while (j < m->a_size)
		{
			if (m->stack_a[i] == m->stack_a[j])
				error_code(3);
			j++;
		}
		i++;
	}
}

