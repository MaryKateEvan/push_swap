/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 01:38:54 by mevangel          #+#    #+#             */
/*   Updated: 2023/09/29 03:50:03 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char x)
{
	t_node	*first;
	t_node	*second;

	if (!stack->head || !stack->head->next)
		return ;
	first = stack->head;
	second = stack->head->next;
	first->next = second->next;
	second->next = first;
	stack->head = second;
	write(1, "s", 1);
	write(1, &x, 1);
	write(1, "\n", 1);
}

void	push(t_stack *to, t_stack *from, char x)
{
	t_node	*send;

	if (from->head == NULL)
		return ;
	send = from->head;
	from->head = from->head->next;
	send->next = to->head;
	to->head = send;
	write(1, "p", 1);
	write(1, &x, 1);
	write(1, "\n", 1);
	to->size++;
	from->size--;
}

void	rotate(t_stack *stack, char x)
{
	t_node	*ex_first;
	t_node	*find_last;

	if (!stack->head || !stack->head->next)
		return ;
	ex_first = stack->head;
	find_last = stack->head;
	while (find_last->next != NULL)
		find_last = find_last->next;
	stack->head = ex_first->next;
	ex_first->next = NULL;
	find_last->next = ex_first;
	write(1, "r", 1);
	write(1, &x, 1);
	write(1, "\n", 1);
}

void	reverse_rotate(t_stack *stack, char x)
{
	t_node	*ex_last;
	t_node	*prelast;

	if (!stack->head || !stack->head->next)
		return ;
	prelast = stack->head;
	ex_last = NULL;
	while (prelast->next->next != NULL)
		prelast = prelast->next;
	ex_last = prelast->next;
	prelast->next = NULL;
	ex_last->next = stack->head;
	stack->head = ex_last;
	write(1, "rr", 2);
	write(1, &x, 1);
	write(1, "\n", 1);
}
