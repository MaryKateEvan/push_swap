/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:58:32 by mevangel          #+#    #+#             */
/*   Updated: 2023/09/30 01:07:46 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	word_length(char *word)
{
	int	len;

	len = 0;
	while (word[len] && word[len] != ' ')
		len++;
	return (len);
}

int	count_arguments(char *s)
{
	size_t	num;
	size_t	i;

	num = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != ' ' && s[i + 1] == ' ') || \
			(s[i] != ' ' && s[i + 1] == '\0'))
			num++;
		i++;
	}
	return (num);
}

void	error_free_exit(void *to_free1, void *to_free2, void *to_free3)
{
	write(2, "Error\n", 6);
	free(to_free1);
	to_free1 = NULL;
	free(to_free2);
	to_free2 = NULL;
	free(to_free3);
	to_free3 = NULL;
	exit(EXIT_FAILURE);
}

void	free_stack(t_node *to_free)
{
	t_node	*move;

	if (!to_free)
		return ;
	while (to_free != NULL)
	{
		move = to_free->next;
		free(to_free);
		to_free = move;
	}
	to_free = NULL;
}

long long	ft_atoll(char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (*str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * sign);
}
