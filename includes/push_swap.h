/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:39:00 by zqadiri           #+#    #+#             */
/*   Updated: 2021/04/26 13:51:58 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../includes/helpers.h"

typedef struct		s_instruction
{
	char			*best_rot;
	int				index;
	int				pivot;
	int				elem;
	int				start_value;
	int				small;

}					t_instruction;

typedef struct		s_data
{
	int				*stack_a;
	int				*stack_b;
	int				*dup;
	int				*mid_point;
	int				pos;
	int				a_size;
	int				dup_size;
	int				b_size;
	t_instruction	inst;
}					t_data;

/*
**  Operations
*/

void				rotate_b(t_data *m);
void				rotate_a(t_data *m);
void				push_b(t_data *m);
void				push_a(t_data *m);
void				swap_b(t_data *m);
void				swap_a(t_data *m);
void				apply_rra(t_data *m);
void				apply_rrb(t_data *m);

/*
** Parsing
*/

void				is_valid(t_data *data, char *arg);
void				check_duplicate(t_data *data);
void				init_struct(t_data *data, int argc);
void				init_stacks(t_data *data, int argc);
int					is_sorted(t_data *m);

/*
** Sorting
*/

void				sort_stack_500(t_data *m);
void				sort_stack_100(t_data *m);
void				find_pivot(t_data *m);
void				sort_stack_3(t_data *m);
void				sort_stack_5(t_data *m);
void				begin_sort(t_data *m);
void				fill_dup(t_data *m, int *stack, int size);
int					find_small_one(int *stack, int size);
void				create_str(t_data *m, char *inst, int len);
void				move_from_b_to_a(t_data *m);
int					find_pos(int *stack, int size, int elem);
void				find_best_way_a_b(t_data *m, int elem);
void				move_big_elem_b(t_data *m);
int					find_big_one(int *stack, int size);
void				reverse_move_from_b_to_a(t_data *m);
void				apply_instruction(t_data *m);

#endif