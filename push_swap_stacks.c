/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanche <dasanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:59:47 by dasanche          #+#    #+#             */
/*   Updated: 2025/06/07 12:59:47 by dasanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función que imprime el stack:

void	print_stack(t_stack *stack)
{
	t_node	*current;

	printf("-------------------------------\n");
	if (!stack)
	{
		printf("Stack vacio(NULL)\n");
		return;
	}
	printf("Stack %c (cantidad: %d):\n", stack->name, stack->size);
	current = stack->top;
	while (current)
	{
		printf("  Numero: [%d] con indice: %d\n", current->value, current->index);
		current = current->next;
	}
	printf("-------------------------------\n");
}

// Función que crea nodos para el stack:

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

// Función que libera el stack:

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return;
	while (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	free(stack);
}

// Función que asigna el índice correspondiente al nodo del stack:

void	assign_indexes(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;
	int		index;

	current = stack->top;
	while (current)
	{
		index = 0;
		tmp = stack->top;
		while (tmp)
		{
			if (tmp->value < current->value)
				index++;
			tmp = tmp->next;
		}
		current->index = index;
		current = current->next;
	}
}

// Función para inicializar el stack 'A' con los elementos (números) recibidos:

t_stack	*init_stack_a(long long *nbrs, int count)
{
	t_stack	*a;
	t_node	*new;
	int		i;

	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->top = NULL;
	a->size = 0;
	a->name = 'A';
	i = count - 1;
	while (i >= 0)
	{
		new = new_node((int)nbrs[i]);
		if (!new)
		{
			free_stack(a);
			return (NULL);
		}
		new->next = a->top;
		a->top = new;
		a->size++;
		i--;
	}
	return (a);
}