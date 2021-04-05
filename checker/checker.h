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
void     	find_pivot(t_data *m);
void		sort_stack_3(t_data *m);
void 		sort_stack_5(t_data *m);
void		begin_sort(t_data *m);
void		fill_dup(t_data *m, int *stack, int size);
int 		find_small_one(int *stack, int size);
void		create_str(t_data *m, char *inst, int len);
void		move_from_b_to_a(t_data *m);
int			find_pos(int *stack, int size, int elem);
void		find_best_way_a_b(t_data *m, int elem);
void		move_big_elem_b(t_data *m);
int 		find_big_one(int *stack, int size);
void	reverse_move_from_b_to_a(t_data *m);

#endif
//  251 191 295 301 233 329 213 269 84 56 150 469 461 105 266 156 216 182 281 241 96 21 72 131 257 492 87 413 457 344 325 487 109 152 176 76 410 422 420 119 399 267 54 282 193 288 481 491 60 95 430 59 0 172 343 338 398 36 143 382 106 317 466 434 284 497 336 407 173 394 45 444 53 187 303 316 133 396 421 196 123 484 314 15 215 78 43 347 165 425 229 228 180 157 55 450 28 400 20 345 383 127 207 230 278 264 426 447 174 177 184 265 50 221 471 395 195 225 433 304 40 401 261 108 321 198 121 217 242 206 170 472 327 85 67 2 385 5 259 223 439 374 365 360 79 296 393 391 359 376 431 99 162 66 243 330 211 299 57 470 377 188 350 142 279 94 355 237 348 353 126 480 14 247 352 341 305 82 117 319 263 250 326 388 370 358 161 416 473 120 351 419 41 453 112 438 436 74 17 220 443 277 111 440 49 323 171 232 387 91 486 11 372 286 297 110 16 186 236 80 411 125 335 163 149 302 274 446 412 320 311 346 107 135 18 246 379 448 132 435 197 452 129 293 390 136 190 454 69 208 140 306 160 166 429 337 39 134 192 478 175 90 349 249 357 219 298 366 363 81 209 179 212 32 25 475 245 402 256 414 226 29 235 312 300 368 210 479 272 239 7 124 287 214 130 26 500 285 334 128 437 354 389 47 427 218 104 154 92 77 118 406 381 380 37 86 373 181 445 449 71 51 200 356 137 476 139 424 271 499 148 158 194 168 386 292 289 280 153 493 199 494 465 415 116 485 322 101 58 19 68 294 64 307 141 310 455 392 31 258 441 488 155 73 12 178 290 489 70 234 52 308 122 331 313 253 255 342 464 495 167 46 6 483 185 268 88 222 283 63 459 404 397 315 145 456 102 482 339 93 496 462 428 328 202 44 474 262 30 100 114 498 164 42 275 3 309 384 417 273 423 463 467 33 318 270 4 369 364 204 98 409 227 61 159 378 27 205 115 22 151 75 147 89 8 189 332 138 183 405 113 248 276 1 103 254 13 367 418 240 333 10 24 408 375 451 38 340 244 260 361 231 169 23 458 371 403 477 48 490 362 34 62 9 97 238 203 468 460 291 65 146 324 144 201 432 442 252 224 83