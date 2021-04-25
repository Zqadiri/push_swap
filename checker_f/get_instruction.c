/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:08:58 by zqadiri           #+#    #+#             */
/*   Updated: 2021/03/18 11:05:32 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*
** swap the first 2 elements at the top of stack a.
** Do nothing if there is only one or no elements
*/

void	swap_a(t_data *m)
{
	int	tmp;

	if (m->a_size > 1)
	{
		tmp = m->stack_a[0];
		m->stack_a[0] = m->stack_a[1];
		m->stack_a[1] = tmp;
	}
}

/*
** swap the first 2 elements at the top of stack b.
** Do nothing if there is only one or no elements
*/

void	swap_b(t_data *m)
{
	int	tmp;

	if (m->b_size > 1)
	{
		tmp = m->stack_b[0];
		m->stack_b[0] = m->stack_b[1];
		m->stack_b[1] = tmp;
	}
}

/*
**  take the first element at the top of b 
**  and put it at the top of a. Do nothing if b is empty.
*/

void	push_a(t_data *m)
{
	int	i;

	i = m->a_size;
	if (m->b_size == 0)
		return ;
	while (i-- > 0)
		m->stack_a[i + 1] = m->stack_a[i];
	m->stack_a[0] = m->stack_b[0];
	i = 0;
	while (i++ <= m->b_size)
		m->stack_b[i - 1] = m->stack_b[i];
	m->a_size++;
	m->b_size--;
}

/*
** fix this mess !!!!
*/

void	check_valid_instr(t_data *m, char *inst)
{
	if (inst[0] == '\0')
		error_code(4);
	else
	{
		if (!ft_strcmp(inst, "sa"))
			swap_a(m);
		else if (!ft_strcmp(inst, "sb"))
			swap_b(m);
		else if (!ft_strcmp(inst, "ss"))
		{
			swap_a(m);
			swap_b(m);
		}
		else if (!ft_strcmp(inst, "pa"))
			push_a(m);
		else if (!ft_strcmp(inst, "pb"))
			push_b(m);
		else if (!ft_strcmp(inst, "ra"))
			rotate_a(m);
		else if (!ft_strcmp(inst, "rb"))
			rotate_b(m);
		else if (!ft_strcmp(inst, "rr"))
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
		{
			ft_putstr("Error\n");
			exit (EXIT_FAILURE);
		}
	}
}

void	get_instruction(t_data *m)
{
	char	*buff;
	char	*inst;
	char	*pfree;
	int		new;

	new = 1;
	while (get_next_line(&buff) > 0)
	{
		if (new)
			inst = ft_strdup("");
		if (buff[0] != '\0')
		{
			new = 0;
			pfree = inst;
			inst = ft_strjoin (inst, &buff[0]);
			free (pfree);
			check_valid_instr(m, inst);
		}
		else
			error_code(4);
		free_param(buff, inst);
		new = 1;
	}
	if (buff[0])
		check_valid_instr(m, buff);
}
