/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanche <dasanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:49:44 by dasanche          #+#    #+#             */
/*   Updated: 2025/05/30 13:08:18 by dasanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# define INT_MIN (-2147483648)
# define INT_MAX 2147483647
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

// Funciones auxiliares
// int					ft_is_valid_number(char *str);
// long				ft_atol(const char *str);
// int					ft_is_in_int_range(char *str);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
// int					ft_is_duplicate(t_node *stack, int value);
// void				ft_append_node(t_node **stack, int value);
// static int			ft_parse_args(int argc, char **argv, t_node **stack);
// End of preprocessor directives / guards:
#endif // FT_PUSH_SWAP_H