/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:20:37 by mevangel          #+#    #+#             */
/*   Updated: 2023/09/29 22:37:22 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

/*****************************    PARSING UTILS   *****************************/
bool		input_is_numeric(char *str);
int			*check_and_split(char *str, int args_num);
long long	ft_atoll(char *str);
int			word_length(char *word);

/*****************************    GENERAL UTILS   *****************************/
void		error_free_exit(void *to_free1, void *to_free2, void *to_free3);
int			ft_strlen(char *str);
int			ft_sqrt(int num);

/*****************************    STACKS' UTILS    ****************************/
void		initialize_stacks(t_stack *a, t_stack *b, int *arr, int size);
void		free_stack(t_node *to_free);
bool		is_sorted(t_node *check);

/******************************    OPERATIONS    ******************************/
void		swap(t_stack *stack, char x);
void		push(t_stack *to, t_stack *from, char x);
void		rotate(t_stack *stack, char x);
void		reverse_rotate(t_stack *stack, char x);

/********************************    SORTING    *******************************/
void		sort_three(t_stack *stack, char x);
void		small_sort(t_stack *a, t_stack *b, int size);
void		fill_b_to_k_shape(t_stack *a, t_stack *b, int size);
void		filter_and_return_to_a(t_stack *a, t_stack *b, int curr_highest);

#endif	//PUSH_SWAP_H
