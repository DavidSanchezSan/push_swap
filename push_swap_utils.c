/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanche <dasanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:27:29 by dasanche          #+#    #+#             */
/*   Updated: 2025/06/03 13:08:35 by dasanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para validar el string controlando que solo haya dígitos o un único sigo
//	+ dígitos:
int	ft_check_valid_input_string(char *s)
{
	int	x;

	x = 0;
	while (s[x])
	{
		if ((s[x] == '-' || s[x] == '+') && (!s[x + 1] || (s[x + 1] < '0' || s[x + 1] > '9')))
    		return (0);
		else if ((s[x] < '0' || s[x] > '9') && s[x] != ' ' && s[x] != '-'
			&& s[x] != '+')
			return (0);
		x++;
	}
	return (1);
}



// Función para dividir y tokenizar cada uno de los elementos que se reciban como input:
char	**ft_parse(int argc, char **argv)
{
	char	**tokens;

	tokens = NULL;
	if (argc == 2)
		tokens = ft_split(argv[1], ' ');
	else
		tokens = &argv[1];
	return (tokens);
}

// Función atol que convierte en long los arrays:

static void	ft_advance_spaces(const char *nptr, int *i)
{
	while (nptr[*i] == ' ' || (nptr[*i] >= 9 && nptr[*i] <= 13))
		(*i)++;
}

static void	ft_check_sign(const char *nptr, int *i, int *s)
{
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			*s = -1;
		(*i)++;
	}
}

long ft_atol(const char *nptr)
{
    long     c;
	int      i;
	int	     s;

	c = 0;
	s = 1;
	i = 0;
	ft_advance_spaces(nptr, &i);
	ft_check_sign(nptr, &i, &s);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (c > (2147483647 / 10) || (c == (2147483647 / 10)
				&& (nptr[i] - '0') > (2147483647 % 10)))
		{
			if (s == 1)
				return (2147483647);
			else
				return (-2147483648);
		}
		c = c * 10 + (nptr[i] - '0');
		i++;
	}
	return (c * s);
}

// Función que controla que no haya números repetidos:

int	ft_check_duplicate(long *nbrs, int num_tokens)
{
	int	x;
    int j;

	x = 0;
	while (x < num_tokens)
	{
        j = x + 1;
        while(j < num_tokens)
		{
            if(nbrs[x] == nbrs[j])
                return (0);
            j++;
        }
		x++;
	}
	return (1);
}

long *error_control_parse(int argc, char **argv)
{
    int j = 0;
	char **tokens = NULL;
	long *nbr_tokens = NULL;
	int num_tokens = 0;
	
	// Dividir el input en diferentes elementos para gestionar cada número por separado:
	tokens = ft_parse(argc, argv);

	// Conocer el tamaño del array de números y reservar memoria:
	while (tokens[num_tokens])
        num_tokens++;

    nbr_tokens = malloc(num_tokens * sizeof(long));
    if (!nbr_tokens)
	{
        write(2, "Error\n", 6);
        return (0);
    }
	// Controlar que cada elemento se compone de dígitos o un único signo
	//	+ dígitos, convertirlo a long y guardarlo:
	while (tokens[j])
	{
		if(!ft_check_valid_input_string(tokens[j]))
		{
			free(nbr_tokens);
			write(2, "Error\n", 6);
			return(0);
		}
		nbr_tokens[j] = ft_atol(tokens[j]);
		if (nbr_tokens[j] > INT_MAX ||nbr_tokens[j] < INT_MIN)
		{
			free(nbr_tokens);
			write(2, "Error\n", 6);
			return (0);
		}
		j++;
	}
	//Controlar duplicados:
	if (!ft_check_duplicate(nbr_tokens, num_tokens))
	{
		free(nbr_tokens);
		write(2, "Error\n", 6);
		return (0);
	}
    return (nbr_tokens);
}