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
	if (argc < 2)
		return (1);

	long *nbr_tokens = error_control_parse(argc, argv);
	
	int num_tokens = 0;
	
	while (nbr_tokens[num_tokens])
    	num_tokens++;
	
	for (int x = 0; x < num_tokens; x++)
	    printf("%ld\n", nbr_tokens[x]);
	
	free(nbr_tokens);
	return (0);
}