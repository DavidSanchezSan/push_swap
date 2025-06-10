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
	t_stack		*stack_b;

	// Parseo y validación
	nbr_tokens = error_control_parse(argc, argv);
	if (!nbr_tokens)
		return (1);

	tokens = ft_parse(argc, argv);
	num_tokens = 0;
	while (tokens[num_tokens])
		num_tokens++;

	stack_a = init_stack_a(nbr_tokens, num_tokens);
	stack_b = init_stack_b();
	if (!stack_a || !stack_b)
	{
		free(nbr_tokens);
		free_split(tokens);
		return (1);
	}

	assign_indexes(stack_a);

	// Mostrar estado inicial
	printf("\nEstado inicial:\n");
	print_stack(stack_a);
	print_stack(stack_b);
	printf("\n");

	// Elegir el algoritmo según número de elementos
	if (stack_a->size <= 5)
		sort_small(stack_a, stack_b);

	// Mostrar estado final
	printf("\nEstado final:\n");
	print_stack(stack_a);
	print_stack(stack_b);
	printf("\n");

	// Limpieza
	free_stack(stack_a);
	free_stack(stack_b);
	free(nbr_tokens);
	if (argc == 2)
		free_split(tokens);

	return (0);
}


// int	main(int argc, char **argv)
// {
// 	long long	*nbr_tokens;
// 	char		**tokens;
// 	int			num_tokens;
// 	t_stack		*stack_a;
// 	t_stack		*stack_b;

// 	num_tokens = 0;
// 	if (argc < 2)
// 		return (1);

// 	nbr_tokens = error_control_parse(argc, argv);
// 	if (!nbr_tokens)
// 		return (1);

// 	tokens = ft_parse(argc, argv);
// 	while (tokens[num_tokens])
// 		num_tokens++;

// 	stack_a = init_stack_a(nbr_tokens, num_tokens);
// 	stack_b = init_stack_b();
// 	if (!stack_a || !stack_b)
// 	{
// 		printf("Error al crear stacks\n");
// 		free(nbr_tokens);
// 		free_split(tokens);
// 		return (1);
// 	}

// 	assign_indexes(stack_a);

// 	printf("Inicial:\n");
// 	print_stack(stack_a);
// 	print_stack(stack_b);

// 	// === PRUEBAS DE MOVIMIENTOS ===
// 	printf("\n---- Movimiento sa ----\n");
// 	sa(stack_a);
// 	print_stack(stack_a);

// 	printf("\n---- Movimiento pb ----\n");
// 	pb(stack_a, stack_b);
// 	print_stack(stack_a);
// 	print_stack(stack_b);

// 	printf("\n---- Movimiento pb ----\n");
// 	pb(stack_a, stack_b);
// 	print_stack(stack_a);
// 	print_stack(stack_b);

// 	printf("\n---- Movimiento sb ----\n");
// 	sb(stack_b);
// 	print_stack(stack_b);

// 	printf("\n---- Movimiento pa ----\n");
// 	pa(stack_a, stack_b);
// 	print_stack(stack_a);
// 	print_stack(stack_b);

// 	printf("\n---- Movimiento ra ----\n");
// 	ra(stack_a);
// 	print_stack(stack_a);

// 	printf("\n---- Movimiento rb ----\n");
// 	rb(stack_b);
// 	print_stack(stack_b);

// 	printf("\n---- Movimiento rr ----\n");
// 	rr(stack_a, stack_b);
// 	print_stack(stack_a);
// 	print_stack(stack_b);

// 	printf("\n---- Movimiento rra ----\n");
// 	rra(stack_a);
// 	print_stack(stack_a);

// 	printf("\n---- Movimiento rrb ----\n");
// 	rrb(stack_b);
// 	print_stack(stack_b);

// 	printf("\n---- Movimiento rrr ----\n");
// 	rrr(stack_a, stack_b);
// 	print_stack(stack_a);
// 	print_stack(stack_b);

// 	// === LIBERACIÓN DE MEMORIA ===
// 	free_stack(stack_a);
// 	free_stack(stack_b);
// 	free(nbr_tokens);
// 	if (argc == 2)
// 		free_split(tokens);

// 	return (0);
// }
