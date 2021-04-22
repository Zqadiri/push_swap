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

# include "../includes/checker.h"

/*
** shit down all elements of stack b by 1. The last element
** becomes the first one.
*/

void 	apply_rrb(t_data *m)
{
	register int i;
	register int tmp;

	if (m->b_size == 0)
		return ;
	i = m->b_size - 1;
	tmp = m->stack_b[i];
	while (i > 0) 
	{
		m->stack_b[i] = m->stack_b[i - 1];
		i--;
	}
	m->stack_b[0] = tmp;
}

/*
** shit down all elements of stack a by 1. The last element
** becomes the first one.
*/

void 	apply_rra(t_data *m)
{
	int i;
	int tmp;

	if (m->a_size == 0)
		return ;
	i = m->a_size - 1;
	tmp = m->stack_a[i];
	while (i > 0) 
	{
		m->stack_a[i] = m->stack_a[i - 1];
		i--;
	}
	m->stack_a[0] = tmp;
}

/*
** swap the first 2 elements at the top of stack a.
** Do nothing if there is only one or no elements
*/

void    swap_a(t_data *m)
{
	int  tmp;

	// if (m->a_size < 2)
	// 	exit(EXIT_SUCCESS);
	// else
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

void    swap_b(t_data *m)
{
	int  tmp;

	// if (m->stack_b == NULL)
	// 	exit (EXIT_SUCCESS);
	// if (m->b_size < 2)
	// 	exit(EXIT_SUCCESS);
	//else
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

void    push_a(t_data *m)
{
	int i;

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
**  take the first element at the top of a 
**  and put it at the top of b. Do nothing if a is empty.
*/

//functional programming
void    push_b(t_data *m)
{
	int i;

	i = m->b_size;
	if (m->a_size == 0)
		return ;
	while (i-- > 0)
		m->stack_b[i + 1] = m->stack_b[i];
	m->stack_b[0] = m->stack_a[0];
	i = 0;
	while (++i < m->a_size)
		m->stack_a[i - 1] = m->stack_a[i];		
	m->b_size++;
	m->a_size--;
}

/*
**  shift up all elements of stack a by 1. The first element
**  becomes the last one.
*/

void    rotate_a(t_data *m)
{
	int i;
	int tmp;

	i = 1;
	tmp = m->stack_a[0];
	if (m->a_size == 0)
		return ;
	while (i < m->a_size)
	{
		m->stack_a[i - 1] = m->stack_a[i];
		i++;
	}
	m->stack_a[i - 1] = tmp;
}

/*
** shift up all elements of stack b by 1. The first 
** element becomes the last one.
*/

void    rotate_b(t_data *m)
{
	int i;
	int tmp;

	i = 1;
	tmp = m->stack_b[0];
	if (m->b_size == 0)
		return ;
	while (i < m->b_size)
	{
		m->stack_b[i - 1] = m->stack_b[i];
		i++;
	}
	m->stack_b[i - 1] = tmp;
}

void 	check_valid_instr(t_data *m, char *inst)
{
	if (inst[0] == '\0')
	{
		ft_putstr("Error\n");
		exit (EXIT_FAILURE);
	}
	else
	{
		if (inst[0] == 's' && inst[1] == 'a' && inst[2] == '\0')
			swap_a(m);
		else if (inst[0] == 's' && inst[1] == 'b' && inst[2] == '\0')
			swap_b(m);
		else if (inst[0] == 's' && inst[1] == 's' && inst[2] == '\0')
		{
			swap_a(m);
			swap_b(m);
		}
		else if (inst[0] == 'p' && inst[1] == 'a' && inst[2] == '\0')
			push_a(m);
		else if (inst[0] == 'p' && inst[1] == 'b' && inst[2] == '\0')
			push_b(m);
		else if (inst[0] == 'r' && inst[1] == 'a' && inst[2] == '\0')
			rotate_a(m);
		else if (inst[0] == 'r' && inst[1] == 'b' && inst[2] == '\0')
			rotate_b(m);
		else if (inst[0] == 'r' && inst[1] == 'r' && inst[2] == '\0')
		{
			rotate_a(m);
			rotate_b(m);
		}      
		else if (inst[0] == 'r' && inst[1] == 'r' && inst[2] == 'a' && inst[3] == '\0')
			apply_rra(m);
		else if (inst[0] == 'r' && inst[1] == 'r' && inst[2] == 'b' && inst[3] == '\0')
			apply_rrb(m);
		else if (inst[0] == 'r' && inst[1] == 'r' && inst[2] == 'r' && inst[3] == '\0')
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

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	int			j;
	char		*p;
	int			size_s1;
	int			size_s2;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen((char *)s1);
	size_s2 = ft_strlen((char *)s2);
	p = malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (p)
	{
		while (s1[++i] != '\0')
			p[i] = s1[i];
		while (s2[j])
			p[i++] = s2[j++];
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	int		size;
	char	*p;
	int		i;

	i = 0;
	size = 0;
	while (src[i] != '\0')
	{
		i++;
		size++;
	}
	size++;
	p = (char *)malloc(size * sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		*(p + i) = src[i];
		i++;
	}
	*(p + i) = '\0';
	return (p);
}


void    get_instruction(t_data *m)
{
	int  ret;
	char *buff;
	char *inst;
	char *pfree;
	int new;

	ret = 0;
	new = 1;
	while ((ret = get_next_line(&buff)) > 0)
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
		{
			ft_putstr("Error\n");
			exit (EXIT_FAILURE);
		}
		free(inst);
		inst = NULL;
		free (buff);
		new = 1;
	}
	if(buff[0])
		check_valid_instr(m, buff);

}

