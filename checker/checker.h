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
#include "../libft/libft.h"

/*
** Store all the arguments 
*/
// typedef struct 		s_stack_a
// {
// 	int				data;
// }					t_stack_a;


typedef struct		s_instruction
{
	char			*stack_a_rot;
	char			*stack_b_rot;
	int				pos;
	int				pivot;
}					t_instruction;

typedef struct      s_data
{
	int				*stack_a;
	int				*stack_b;
	int				*dup;
	int             pos;
	int				a_size;
	int				b_size;
	t_instruction	inst;
}                   t_data;

void		init(t_data *data);
void        is_valid(t_data *data, char *arg);
void    	check_duplicate(t_data *data);
void        error_code(int  code);
void        init_struct(t_data *data, int argc);
int 		get_next_line(char **line);
void    	get_instruction(t_data *m);
void		init_stacks(t_data *data, int argc);
void		print(t_data *m);
void		ft_putstr(char const *s);
int			is_sorted(t_data *m);

void    	rotate_b(t_data *m);
void    	rotate_a(t_data *m);
void    	push_b(t_data *m);
void    	push_a(t_data *m);
void    	swap_b(t_data *m);
void    	swap_a(t_data *m);
void 		apply_rra(t_data *m);
void 		apply_rrb(t_data *m);

void		global_sort(t_data *m);
int     	find_pivot(t_data *m);
void		sort_stack_3(t_data *m);
void 		sort_stack_5(t_data *m);
void		begin_sort(t_data *m);

#endif