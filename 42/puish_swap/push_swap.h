/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duhkim <duhkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:44:17 by duhkim            #+#    #+#             */
/*   Updated: 2025/07/19 21:21:53 by duhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	struct s_list	*head;
	struct s_list	*tail;
}					t_node;

int					rank_check(t_node *node, t_list *new_node);
int					is_sort(t_node *head);
t_node				*parse(char **argv);
int					check_args(t_node *a_node, t_list **newlst, char *nbr);
int					make_list(char **args, t_node *a_node);
void				ft_free(char **tab);
void				free_list(t_node *node);
int					grid_count(t_node *a_node);
void				swap(t_node *node);
void				sa(t_node *a_node);
void				sb(t_node *b_node);
void				ss(t_node *a_node, t_node *_b_node);
void				push(t_node *node, t_node *to_node);
void				pa(t_node *a_node, t_node *b_node);
void				pb(t_node *a_node, t_node *b_node);
void				rotate(t_node *node);
void				ra(t_node *a_node);
void				rb(t_node *b_node);
void				rr(t_node *a_node, t_node *b_node);
void				rrb(t_node *b_node);
void				rrr(t_node *a_node, t_node *b_node);
void				rra(t_node *a_node);
t_node				*create_b_node(t_node *a_node);
void				grid_sort(t_node *a_node, t_node *b_node, int num_grids);
void				push_back_to_a(t_node *a_node, t_node *b_node);
void				push_grid_to_b(t_node *a_node, t_node *b_node, int grid_min,
						int grid_max);
int					find_max(t_list *head);
void				rotate_b_to_max(t_node *b_node, int pos, int size);
void				sort_two(t_node *node);
void				sort_three(t_node *node);
void				sort_five(t_node *a, t_node *b);
int					short_sort(t_node *a_node, t_node *b_node, int size);
void				sort_four(t_node *a, t_node *b);

#endif