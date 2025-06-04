/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanche <dasanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:49:51 by dasanche          #+#    #+#             */
/*   Updated: 2025/06/03 13:08:33 by dasanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	long	*nbr_tokens;
	char	**tokens;
	int		num_tokens;

	num_tokens = 0;
	if (argc < 2)
		return (1);
	nbr_tokens = error_control_parse(argc, argv);
	if (!nbr_tokens)
		return (1);
	tokens = ft_parse(argc, argv);
	while (tokens[num_tokens])
		num_tokens++;
	for (int x = 0; x < num_tokens; x++)
		printf("%ld\n", nbr_tokens[x]);
	if (argc == 2)
		free_split(tokens);
	free(nbr_tokens);
	return (0);
}
