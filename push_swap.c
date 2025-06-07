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
	long long	*nbr_tokens;
	char		**tokens;
	int			num_tokens;
	t_stack		*stack_a;

	num_tokens = 0;
	if (argc < 2)
		return (1);

	nbr_tokens = error_control_parse(argc, argv);
	if (!nbr_tokens)
		return (1);

	tokens = ft_parse(argc, argv);
	while (tokens[num_tokens])
		num_tokens++;

	stack_a = init_stack_a(nbr_tokens, num_tokens);
	if (!stack_a)
	{
		free(nbr_tokens);
		free_split(tokens);
		return (1);
	}

	assign_indexes(stack_a);
	print_stack(stack_a);

	free_stack(stack_a);
	free(nbr_tokens);
	if (argc == 2)
		free_split(tokens);

	return (0);
}



