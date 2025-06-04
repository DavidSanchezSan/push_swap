/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanche <dasanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:49:44 by dasanche          #+#    #+#             */
/*   Updated: 2025/06/03 13:08:37 by dasanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
	char	name; // 'A' o 'B'
}	t_stack;

// Funciones auxiliares
long long			*error_control_parse(int argc, char **argv);
char				**ft_parse(int argc, char **argv);
int					ft_check_valid_input_string(char *s);
char				**ft_split(char const *s, char c);
long long				ft_atol(const char *nptr);
void				free_split(char **split);
int					ft_check_duplicate(long long *nbrs, int num_tokens);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
// End of preprocessor directives / guards:
#endif // PUSH_SWAP_H