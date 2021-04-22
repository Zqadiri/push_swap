/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:15:23 by zqadiri           #+#    #+#             */
/*   Updated: 2021/03/18 10:53:42 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct		s_instruction
{
	char			*stack_a_rot;
	char			*stack_b_rot;
	char			*best_rot;
	int				index;
	int				pivot;
	int 			elem;
	int 			start_value;
	int				small;
	int				big;
}					t_instruction;

typedef struct      s_data
{
	int				*stack_a;
	int				*stack_b;
	int				*dup;
	int             pos;
	int				a_size;
	int				dup_size;
	int				b_size;
	t_instruction	inst;
}                   t_data;

/*
**  Operations
*/

void    	rotate_b(t_data *m);
void    	rotate_a(t_data *m);
void    	push_b(t_data *m);
void    	push_a(t_data *m);
void    	swap_b(t_data *m);
void    	swap_a(t_data *m);
void 		apply_rra(t_data *m);
void 		apply_rrb(t_data *m);
void    	get_instruction(t_data *m);

/*
** Parsing
*/

void        is_valid(t_data *data, char *arg);
void    	check_duplicate(t_data *data);
void        init_struct(t_data *data, int argc);
void		init_stacks(t_data *data, int argc);
int			is_sorted(t_data *m);

/*
** Utils
*/

void		ft_putstr(char const *s);
char		*ft_strdup(const char *src);
void        error_code(int  code);
int 		get_next_line(char **line);
int			is_sorted(t_data *m);

// ./push_swap 5 4 1 2
#endif