/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 01:38:54 by mevangel          #+#    #+#             */
/*   Updated: 2023/09/30 01:01:47 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	is_sorted(t_node *check)
{
	if (!check)
		return (false);
	while (check->next != NULL)
	{
		if (check->value > check->next->value)
			return (false);
		check = check->next;
	}
	return (true);
}

void	swap(t_stack *stack)
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
}

void	push(t_stack *to, t_stack *from)
{
	t_node	*send;

	if (from->head == NULL)
		return ;
	send = from->head;
	from->head = from->head->next;
	send->next = to->head;
	to->head = send;
	to->size++;
	from->size--;
}

void	rotate(t_stack *stack)
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
}

void	reverse_rotate(t_stack *stack)
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
}
