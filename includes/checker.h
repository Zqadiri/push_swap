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


#endif
// 1000
// 119 65 26 103 22 197 396 40 191 481 493 45 275 282 398 168 44 79 343 76 201 264 222 237 277 200 400 174 241 148 193 249 35 130 342 281 29 379 1 126 113 469 382 109 449 486 212 494 344 337 70 239 265 163 431 18 355 408 293 147 95 404 430 492 467 89 91 270 345 372 306 384 205 217 402 285 367 409 43 272 428 497 336 320 477 225 204 219 150 80 143 125 137 385 464 276 347 470 257 134