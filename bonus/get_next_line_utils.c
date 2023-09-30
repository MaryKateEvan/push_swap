/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:37:42 by mevangel          #+#    #+#             */
/*   Updated: 2023/09/29 02:45:15 by mevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

char	*ft_char_calloc(int num)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(num * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < num)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	char	*joined;
	int		i;
	int		j;

	joined = ft_char_calloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	if (!joined)
		return (NULL);
	i = -1;
	j = -1;
	while (stash[++i] != '\0')
		joined[i] = stash[i];
	while (buffer[++j] != '\0')
		joined[i + j] = buffer[j];
	free(stash);
	return (joined);
}
