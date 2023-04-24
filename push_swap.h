/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:58:54 by yabad             #+#    #+#             */
/*   Updated: 2023/02/04 12:34:20 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* Header files */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"
# define R 1
# define RR 2

//na 	:	number of instructions that will be executed on stack A
//oa 	: 	the operation that will be executed on stack A ==> either R or RR
//count :	is the total number of operations that will be executed 
//			on stack A and B including common instructions
typedef struct s_pos
{
	int	na;
	int	oa;
	int	nb;
	int	ob;
	int	count;
}	t_pos;
// a 	: is stack A converted to an array
// s_a	: is the size of array a
typedef struct s_arr
{
	int	*a;
	int	s_a;
	int	*b;
	int	s_b;
}	t_arr;
/* Stack implementation */
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;
typedef struct s_stack
{
	t_node	*top;
}	t_stack;
//
typedef struct s_vars
{
	int	min_pos;
	int	size;
	int	index;
	int	*lis;
	int	lis_len;
}	t_vars;
/* Functions to check if args are valid */
char		**is_valid(char *arg);
char		*join_args(char **av);
long int	ft_long_atoi(const char *str);
int			is_special_chars(char *arg);
int			is_plus_minus_valid(char *number);
int			is_range_valid(char *number);
int			is_number_valid(char **splited);
int			is_not_duplicated(char **splited);
/* Simple function to free content from HEAP */
void		freemem(char **ptr, void *ptr2, t_node *stack);
/* Stack functions */
t_stack		fill_stack(char **splited);
void		printstack(t_stack *stack_b);
int			is_empty(t_stack stack);
int			peek(t_stack stack);
int			pop(t_stack *stack);
void		push(t_stack *stack, int value);
int			stack_size(t_stack *stack);
/* The FUCKING Rules */
void		action_runner(char *action, t_stack *a, t_stack *b);
void		_swap(t_stack *stack);
void		_push(t_stack *from, t_stack *to);
void		_rotate(t_stack *stack);
void		_r_rotate(t_stack *stack);
/* Sorting functions */
void		start_sorting(char **splited);
int			is_sorted(t_stack *stack);
int			minimum_value_of_stack(t_stack *stack, int *pos);
void		sort_three(t_stack *sa);
void		sort_five(t_stack *a, t_stack *b);
/* LIS functions */
int			*push_min_to_top(t_stack *stack, int min, t_vars *vars);
int			*from_stack_to_array(t_stack *stack, int size);
void		_rotate_arr(int *arr, int size);
void		_r_rotate_arr(int *arr, int size);
int			find_max_arr(int *dp, t_vars *vars);
void		fill_arr(int *dp, int *prev, int size);
/* Push back */
void		push_to_stack_a(t_stack *a, t_stack *b);
int			get_min(int a, int b);
int			ft_max(int a, int b);
int			get_max(int *arr, int size);
int			get_min_pos(int *arr, int size);
int			get_perfect_position(int n, int *arr, int size);
void		init(t_stack *a, t_stack *b, t_arr *arr);

#endif