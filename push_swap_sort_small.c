/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_small.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanche <dasanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:27:12 by dasanche          #+#    #+#             */
/*   Updated: 2025/06/10 13:27:12 by dasanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para dos elementos:

void	sort_2(t_stack *a)
{
	if (a->size != 2 || is_sorted(a))
		return ;
	if (a->top->index > a->top->next->index)
		sa(a);
}

// Función para tres elementos:

void	sort_3(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (a->size != 3 || is_sorted(a))
		return ;
	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	if (first < second && second < third) // Caso 1: 0 1 2 → ya está ordenado
		return ;
	else if (first < third && third < second) // Caso 2: 0 2 1 → sa + ra
	{
		sa(a);
		ra(a);
	}
	else if (second < first && first < third) // Caso 3: 1 0 2 → sa
		sa(a);
	else if (third < first && first < second) // Caso 4: 1 2 0 → rra
		rra(a);
	else if (second < third && third < first) // Caso 5: 2 0 1 → ra
		ra(a);
	else if (third < second && second < first) // Caso 6: 2 1 0 → sa + rra
	{
		sa(a);
		rra(a);
	}
}

// Función para cuatro elementos:

void	sort_4(t_stack *a, t_stack *b)
{
	t_node	*min;

	if (a->size != 4 || is_sorted(a))
		return ;
	min = find_min_node(a);
	move_node_to_top(a, min, 'a');
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

// Función para cinco elementos:

void	sort_5(t_stack *a, t_stack *b)
{
	t_node	*min;

	if (a->size != 5 || is_sorted(a))
		return ;
	min = find_min_node(a); // Sacar primer mínimo
	move_node_to_top(a, min, 'a');
	pb(a, b);
	min = find_min_node(a); // Sacar segundo mínimo
	move_node_to_top(a, min, 'a');
	pb(a, b);
	sort_3(a); // Ordenar los 3 restantes
	if (b->top->index < b->top->next->index) // Ordenar stack B si hace falta (solo 2 elementos)
		sb(b);
	pa(a, b); // Volver a meter los dos mínimos
	pa(a, b);
}

// Función que unifica el ordenamiento de poco elementos:
void	sort_small(t_stack *a, t_stack *b)
{
    if (is_sorted(a))
 	   return ;
	if (a->size == 1)
 	   return ;
    if (a->size == 2)
 	   sort_2(a);
    else if (a->size == 3)
 	   sort_3(a);
    else if (a->size == 4)
 	   sort_4(a, b);
    else if (a->size == 5)
 	   sort_5(a, b);
}