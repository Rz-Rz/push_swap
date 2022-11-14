/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:33:04 by kdhrif            #+#    #+#             */
/*   Updated: 2022/11/14 22:47:22 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "get_next_line.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct t_node
{
	struct t_node	*next;
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
}				t_node;

// ft_printf
int				ft_printf(const char *format, ...);

// linked_list_0.c
t_node			*lst_new(int value);
t_node			*lst_duplicate(t_node *stack);
void			lst_add_back(t_node **stack, t_node *new_t_node);
void			lst_swap(t_node *n1, t_node *n2);
t_node			*lst_last(t_node *stack);

// linked_list_1.c
void			lst_free(t_node *head);
int				lst_size(t_node *head);
t_node			*lst_search_target_pos(t_node *head, int target_pos);

// push_swap.c
void			print_t_node(t_node *n);
t_node			*fill_stack_a(char **av);
void			print_stack(t_node *stack);

// sorting_0.c
void			quick_sort(int *stack, int low, int high);
int				partition(int *arr, int low, int high);
int				*t_nodeval_to_int(t_node *stack_a, t_node *stack_b);
void			swap(int *a, int *b);
void			put_index(t_node *stack_a, t_node *stack_b);

// sorting_1.c
void			put_index_bis(t_node *stack_a, t_node *stack_b, int ac, int j, int *arr);

// parsing_0.c
int				is_ordered(t_node *stack);
int				is_duplicate(t_node *stack);

// parsing_1.c
char			**master_parser(char **av);

// action_b.c
void			sb(t_node **stack_b, int toggle);
void			rb(t_node **stack_b, int toggle);
void			pb(t_node **stack_a, t_node **stack_b, int toggle);
void			rrb(t_node **stack_b, int toggle);

// action_a.c
void			rra(t_node **stack_a, int toggle);
void			ra(t_node **stack_a, int toggle);
void			sa(t_node **stack_a, int toggle);
void			pa(t_node **stack_a, t_node **stack_b, int toggle);

// action_r.c
void			rrr(t_node **stack_a, t_node **stack_b, int toggle);
void			rr(t_node **stack_a, t_node **stack_b, int toggle);
void			ss(t_node **stack_a, t_node **stack_b, int toggle);

// ft_utils.c
int				ft_atoi(const char *nptr, int *error);
int				ft_abs(int nb);
int				ft_strlen(char *str);
char			*ft_strdup(char *str);
int				ft_strcmp(char *s1, char *s2);
void			free_str(char **av);

//algo_0.c
void			sort_3(t_node **stack_a);
void			sort_2(t_node **stack_a);
void			push_to_b(t_node **stack_a, t_node **stack_b);
void			put_pos(t_node *stack_a, t_node *stack_b);
void			sort(t_node **stack_a, t_node **stack_b);

//algo_1.c
int				is_superior(t_node *stack_b, t_node *stack_a);
int				get_pos_of_smallest_index(t_node *stack_a);
void			put_target_pos(t_node *stack_a, t_node *stack_b);
void			put_target_bis(t_node *tmp_b, t_node *stack_a, t_node *tmp_a);
void			put_costs(t_node *stack_b, t_node *stack_a);

//algo_2.c
int				compute_cost(t_node *t_node, int size);
int				compute_cost_a(t_node *t_node_b, t_node *stack_a, int size);
t_node			*find_cheapest_action(t_node *stack_b);
void			do_actions(t_node **stack_a, t_node **stack_b, t_node *to_sort);
void			rotate_until_sorted(t_node **stack_a);

//algo_3.c
void			r_actions_same_sign(t_node **stack_a, t_node **stack_b,
					t_node *to_sort);
void			median_sorter(t_node **stack_a, t_node **stack_b, int median,
					int size);

//ft_split.c
char			*ft_strdupm(char *s, char c);
int				ft_cntwrds(char const *s, char c);
char			**ft_split(char const *s, char c);

//ft_strjoin.c
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin(char const *s1, char const *s2);

// checker.c
int				execute_instruction(char *line, t_node **stack_a, t_node **stack_b);
int				checker(char **argv);

#endif
