/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshariar <mshariar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:06:01 by mshariar          #+#    #+#             */
/*   Updated: 2024/10/24 15:32:01 by mshariar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	sep(char const *str, char c)
{
	int	i;
	int	token;

	i = 0;
	token = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			token++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (token);
}

char	*ft_dup(char const *str, char c)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (i > j)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

static int	split(char **tab, char const *s, char c, int tab_i)
{
	tab[tab_i] = ft_dup(s, c);
	if (!tab[tab_i])
		return (0);
	return (1);
}

static	char	**freeall(char **tab, int i)
{
	while (i > 0)
	{
		free (tab[i - 1]);
		i--;
	}
	free (tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		tab_i;
	int		i;

	if (!s)
		return (NULL);
	tab = malloc((sep(s, c) + 1) * sizeof (char *));
	if (!tab)
		return (NULL);
	i = 0;
	tab_i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			if (!split(tab, s + i, c, tab_i++))
				return (freeall(tab, tab_i));
		}
		while (s[i] && s[i] != c)
			i++;
	}
	tab[tab_i] = NULL;
	return (tab);
}
/*
int	main()
{
	int i = 0;
	//char *str = " *****h******ello * spsklfslkdsflit * this";
	//char c = '*';
	char **split = ft_split("  tripouille  42  ", '');
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	return (0);
}*/