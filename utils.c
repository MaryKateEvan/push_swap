/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:58:32 by mevangel          #+#    #+#             */
/*   Updated: 2023/09/29 04:21:35 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	word_length(char *word)
{
	int	len;

	len = 0;
	while (word[len] && word[len] != ' ')
		len++;
	return (len);
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

int	ft_sqrt(int num)
{
	int	x;
	int	y;

	if (num <= 0)
		return (0);
	x = num;
	y = (x + 1) / 2;
	while (y < x)
	{
		x = y;
		y = (x + num / x) / 2;
	}
	return (x);
}
