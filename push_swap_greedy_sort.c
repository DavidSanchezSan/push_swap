/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_greedy_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanche <dasanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:36:22 by dasanche          #+#    #+#             */
/*   Updated: 2025/06/10 14:36:22 by dasanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función que devuelve la posición en a donde insertar el valor con índice b_index.

int	get_target_pos(t_stack *a, int b_index)
{
	t_node	*current;
	int		pos;
	int		best_index;
	int		best_pos;

	current = a->top;
	pos = 0;
	best_index = __INT_MAX__;
	best_pos = 0;
	while (current)
	{
		if (current->index > b_index && current->index < best_index)
		{
			best_index = current->index;
			best_pos = pos;
		}
		pos++;
		current = current->next;
	}
	if (best_index == __INT_MAX__)
	{
		current = a->top;
		pos = 0;
		best_index = __INT_MAX__;
		while (current)
		{
			if (current->index < best_index)
			{
				best_index = current->index;
				best_pos = pos;
			}
			pos++;
			current = current->next;
		}
	}
	return (best_pos);
}

// Función que calcula cuántas operaciones costaría hacer a y b girar para colocar el nodo de b en la posición a_pos:

int	get_cost(int a_size, int a_pos, int b_size, int b_pos)
{
	int	cost_a;
	int	cost_b;

	if (a_pos <= a_size / 2)
		cost_a = a_pos;
	else
		cost_a = a_size - a_pos;
	if (b_pos <= b_size / 2)
		cost_b = b_pos;
	else
		cost_b = b_size - b_pos;
	return (cost_a + cost_b);
}

// Calcula todos los costes de movimientos y hace el más barato:

void	do_cheapest_move(t_stack *a, t_stack *b)
{
	t_node	*current;
	int		best_cost;
	int		best_a_pos;
	int		best_b_pos;
	int		i;

	current = b->top;
	best_cost = __INT_MAX__;
	best_a_pos = 0;
	best_b_pos = 0;
	i = 0;
	while (current)
	{
		int	target_pos = get_target_pos(a, current->index);
		int	cost = get_cost(a->size, target_pos, b->size, i);
		if (cost < best_cost)
		{
			best_cost = cost;
			best_a_pos = target_pos;
			best_b_pos = i;
		}
		i++;
		current = current->next;
	}
	// Calculamos diferencias relativas
	int	a_rot = best_a_pos;
	int	b_rot = best_b_pos;
	int	a_size = a->size;
	int	b_size = b->size;
	// Caso 1: Ambos en mitad superior → usar rr
	while (a_rot > 0 && b_rot > 0 && a_rot <= a_size / 2 && b_rot <= b_size / 2)
	{
		rr(a, b);
		a_rot--;
		b_rot--;
	}
	while (a_rot-- > 0 && best_a_pos <= a_size / 2)
		ra(a);
	while (b_rot-- > 0 && best_b_pos <= b_size / 2)
		rb(b);
	// Caso 2: Ambos en mitad inferior → usar rrr
	a_rot = a_size - best_a_pos;
	b_rot = b_size - best_b_pos;
	while (a_rot > 0 && b_rot > 0 && best_a_pos > a_size / 2 && best_b_pos > b_size / 2)
	{
		rrr(a, b);
		a_rot--;
		b_rot--;
	}
	while (a_rot-- > 0 && best_a_pos > a_size / 2)
		rra(a);
	while (b_rot-- > 0 && best_b_pos > b_size / 2)
		rrb(b);
	// Inserta el nodo con el menor coste
	pa(a, b);
}


// Algortimo completo para casos superiores a 5:

void	greedy_sort(t_stack *a, t_stack *b)
{
	t_node	*min;

	while (a->size > 3)
		pb(a, b);
	sort_3(a); // Ordena los 3 que quedaron en A
	while (b->size > 0)
		do_cheapest_move(a, b); // Reinserta uno por uno
	// Finalmente rota A hasta que el más pequeño esté arriba
	min = find_min_node(a);
	move_node_to_top(a, min);
}