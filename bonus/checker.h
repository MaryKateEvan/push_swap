/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:20:37 by mevangel          #+#    #+#             */
/*   Updated: 2023/09/30 00:57:20 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_node
{
	int				value;
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
int			count_arguments(char *s);

/*****************************    STACKS' UTILS    ****************************/
void		initialize_stacks(t_stack *a, t_stack *b, int *arr, int size);
void		free_stack(t_node *to_free);
bool		is_sorted(t_node *check);

/******************************    OPERATIONS    ******************************/
void		swap(t_stack *stack);
void		push(t_stack *to, t_stack *from);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);
void		swap_both(t_stack *stack_a, t_stack *stack_b);
void		rotate_both(t_stack *stack_a, t_stack *stack_b);
void		reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);

/*****************************    GET_NEXT_LINE    ****************************/
char		*get_next_line(int fd);
char		*ft_strchr(char *s, char c);
char		*ft_char_calloc(int num);
char		*ft_strjoin(char *stash, char *buffer);

#endif	//CHECKER_H
