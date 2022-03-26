/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:53:35 by mmaythaw          #+#    #+#             */
/*   Updated: 2022/03/15 10:52:24 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	error_free(int count, char **arr)
{
	while (count >= 0)
	{
		if (arr[count])
			free(arr[count]);
		count--;
	}
	free(arr);
}

static int	count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (!(ft_isprint(s[i])))
			return (0);
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	walloc(char const *s, char **arr, char c)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i] && s[i++] != c)
				len++;
			arr[count] = (char *)malloc((len + 1) * sizeof(char));
			if (arr == NULL)
			{
				error_free(count, arr);
				return (0);
			}
			count++;
		}
	}
	return (1);
}

static void	split(char const *s, char **arr, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (s[i] && s[i] != c)
			{
				arr[count][j] = s[i];
				i++;
				j++;
			}
			arr[count][j] = 0;
			count++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**arr;

	if (s == NULL)
	{
		arr = (char **)malloc(sizeof(char *) * 1);
		if (arr == NULL)
			return (NULL);
		arr[0] = 0;
		return (arr);
	}
	words = count(s, c);
	arr = (char **)malloc((words + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	walloc(s, arr, c);
	split(s, arr, c);
	arr[words] = 0;
	return (arr);
}
