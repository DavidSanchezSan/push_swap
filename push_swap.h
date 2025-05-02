

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
#define INT_MIN (-2147483648)
#define INT_MAX 2147483647
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

// Funciones auxiliares (las que ya tienes)
int ft_is_valid_number(char *str);
long ft_atol(const char *str);
int ft_is_in_int_range(char *str);
void ft_free_split(char **tokens);
int ft_is_duplicate(t_node *stack, int value);
void ft_append_node(t_node **stack, int value);
static int ft_parse_args(int argc, char **argv, t_node **stack);
// End of preprocessor directives / guards:
#endif // FT_PUSH_SWAP_H