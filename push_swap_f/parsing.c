/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:27:21 by zqadiri           #+#    #+#             */
/*   Updated: 2021/04/21 14:30:48 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

static int  check_overflow(long digit)
{
	if (digit > INT32_MAX || digit < INT32_MIN)
		return (0);
	return (1);
}

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
	m->inst.big = 0;
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

void        error_code(int  code)
{
    write (2, "Error\n", 6);
    if (code == 1)
        write (2, "Checker gets as an argument a list of integers ...\n", 51);
    if (code == 2)
        write (2, "Overflow error !\n", 17);
    if (code == 3)
        write (2, "The list can not contain duplicates\n", 36);
    exit (EXIT_FAILURE);
}

int		is_sorted(t_data *m)
{
	int i;
	int len;

	i = 0;
	len = m->a_size;
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
		j = 0;
		while (j < m->pos)
		{
			if (i != j)
			{
				if (m->stack_a[i] == m->stack_a[j])
				{	
					error_code(3);
				}		
			}
			j++;
		}
		i++;
	}
	
}

