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

void	check_valid_instr(t_data *m, char *inst)
{
	if (inst[0] == '\0')
		exit_error();
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
		else
			help(inst, m);
	}
}

void	get_instruction(t_data *m)
{
	char	*buff;
	char	*pfree;
	int		new;

	new = 1;
	while (get_next_line(&buff) > 0)
	{
		if (new)
			m->inst_tmp = ft_strdup("");
		if (buff[0] != '\0')
		{
			new = 0;
			pfree = m->inst_tmp;
			m->inst_tmp = ft_strjoin (m->inst_tmp, &buff[0]);
			free (pfree);
			check_valid_instr(m, m->inst_tmp);
		}
		else
			exit_error();
		free_param(buff, m->inst_tmp);
		new = 1;
	}
	if (buff[0])
		check_valid_instr(m, buff);
	free(buff);
}
