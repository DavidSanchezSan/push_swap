/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanche <dasanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:49:51 by dasanche          #+#    #+#             */
/*   Updated: 2025/05/30 13:21:22 by dasanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	check_valid_input_string(char *s)
// {
// 	int x;
// 	int j;

// 	x = 0;
// 	j = x + 1;
// 	while(s[x])
// 	{
// 		if ((s[x] == '-' || s[x] == '+') && (s[x+1] < '0' || s[x+1] > '9'))
// 			return (0);
// 		else if ((s[x] < '0' || s[x] > '9') && s[x] != ' ' && s[x] != '-' && s[x] != '+')
// 			return(0);
// 		while(s[j])
// 		{
// 			if ((s[x]) != ' ' && ((s[x]) == s[j]))
// 				return (0);
// 			j++;
// 		}
// 		x++;
// 		j = x + 1;
// 	}
// 	return (1);
// }

char **parse(int argc, char **argv)
{
	char **tokens = NULL;

	if (argc == 2)
		tokens = ft_split(argv[1], ' ');
	else
		tokens = &argv[1];
	return (tokens);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return(0);
	printf("%d\n", argc);
	
	int j = 0;
	char **tokens = NULL;
	
	tokens  = parse(argc, argv);
	
	while(tokens[j])
	{
		printf("Ha entrado en posición %d = ", j);
		printf("%s\n", tokens[j]);
		j++;
	}
}

// int	main(int argc, char **argv)
// {
// 	int i;

// 	i = 1;
// 	while(i <= (argc -1))
// 	{
// 		if (!check_valid_input_string(argv[i]))
// 		{
// 			write(1, "Error", 5);
// 			write(1, "\n", 1);
// 			return(1);
// 		}
// 		i++;
// 	}
// 	printf("%d", argc);
// 	return (0);
// }
