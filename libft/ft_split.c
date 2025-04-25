/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhoracek <vhoracek@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:32:02 by vhoracek          #+#    #+#             */
/*   Updated: 2024/12/15 18:32:02 by vhoracek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
// #include <stdio.h>

// char	**ft_split(char const *s, char c);
// static int	count_words(char const *s, char c);

// int	main(int argc, char* argv[])
// {
// 	(void)argc;
// /*
// 	if(argc != 3)
// 	{
// 		printf("Input 1/ String to be split 2/ Delimitter char\n");
// 		return(2);
// 	}
// 	if(argv[2][1] != '\0')
// 	{
// 		printf("Second argument is a single character\n");
// 		return(2);
// 	}
// */
// 	char c = argv[2][0];
// 	char const *s = argv[1];
// 	printf("\n string   :  :%s: \n delimiter:  :%c: \n\n", s, c);
// 	char** result = ft_split(s, c); 
// //	char** result = ft_split(s,'\0'); 

// 	printf("\n string   :  :%s: \n delimiter:  :%i: \n\n", s, c);
// 	printf(" Word Count: %i\n\n", count_words(s, c));

// 	int i = 0;

// 	if (result[0] == NULL)
// 		printf(" NULL\n");
// 	else if (*result[0] == '\0')
// 		printf(" null terminator\n");
// 	while(result[i] != NULL)
// 	{
// 		printf(" String %i: :%s:\n", i, result[i]);
// 		i++;
// 	}

// 	i = 0;
//     while (result[i] != NULL)
//     {
//         free(result[i]);
//         i++;
//     }
// 	free(result);
// 	return 0;
// }

static char	**edge_check(const char *s, int c, char **result)
{
	if (!s || *s == 0)
	{
		result = (char **)malloc(sizeof(char *));
		if (!result)
			return (NULL);
		result[0] = NULL;
		return (result);
	}
	else if (ft_strchr(s, c) == NULL || c == 0)
	{
		result = malloc(2 * sizeof(char *));
		if (result == NULL)
			return (NULL);
		result[0] = ft_strdup(s);
		if (result[0] == NULL)
			return (free(result), NULL);
		result[1] = NULL;
		return (result);
	}
	result = (char **)malloc(sizeof(char *));
	if (!result)
		return (NULL);
	return (result[0] = NULL, result);
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (s && *s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*get_word(char const *s, char c, int *index)
{
	int		len;
	char	*word;

	if (!s || !index)
		return (NULL);
	len = 0;
	while (s[*index] && s[*index] == c)
		(*index)++;
	while (s[*index + len] && s[*index + len] != c)
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	len = 0;
	while (s[*index] && s[*index] != c)
	{
		word[len] = s[*index];
		(*index)++;
		len++;
	}
	word[len] = '\0';
	return (word);
}

static void	*clean_up(char **result, int i)
{
	while (i > 0)
		free(result[--i]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;
	int		index;

	result = NULL;
	if (!s || *s == '\0' || c == '\0' || ft_strchr(s, c) == NULL )
		return (edge_check(s, c, result));
	words = count_words(s, c);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	index = 0;
	while (i < words)
	{
		result[i] = get_word(s, c, &index);
		if (!result[i++])
			return (clean_up(result, i));
	}
	result[i] = NULL;
	return (result);
}
