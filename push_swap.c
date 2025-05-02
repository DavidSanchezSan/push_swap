#include "push_swap.h"


/* 2 Elementos = Comprobar si están ordenados -> Si no, hacer un sa.

3 Elementos = Comprobar si están ordenados -> Si no, ordenarlos tras una serie de chequeos (sa, ra, rra).

4–5 Elementos: Empujar el elemento más pequeño a b, ordenar los restantes usando la lógica de 3 elementos y después hacer pa devolviéndolos. */

static int count_words(const char *str, char delimiter)
{
    int count = 0;
    int in_word = 0;

    while (*str)
    {
        if (*str != delimiter && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (*str == delimiter)
        {
            in_word = 0;
        }
        str++;
    }
    return count;
}

static char *get_word(const char *str, char delimiter)
{
    int len = 0;
    while (str[len] && str[len] != delimiter)
        len++;

    char *word = (char *)malloc(len + 1);
    if (!word)
        return NULL;

    for (int i = 0; i < len; i++)
        word[i] = str[i];

    word[len] = '\0';
    return word;
}

char **ft_split(const char *str, char delimiter)
{
    if (!str)
        return NULL;

    int words = count_words(str, delimiter);
    char **result = (char **)malloc(sizeof(char *) * (words + 1));
    if (!result)
        return NULL;

    int i = 0;
    while (*str)
    {
        if (*str != delimiter)
        {
            char *word = get_word(str, delimiter);
            if (!word)
            {
                // Liberamos la memoria si hay un error al obtener una palabra
                for (int j = 0; j < i; j++)
                    free(result[j]);
                free(result);
                return NULL;
            }
            result[i++] = word;
            str += strlen(word); // Avanzamos el puntero `str` al final de la palabra
        }
        else
        {
            str++;
        }
    }

    result[i] = NULL; // El último puntero debe ser NULL
    return result;
}

int ft_is_valid_number(char *str)
{
    int i;

    i = 0;
    if (!str || str[0] == '\0') // Cadena vacía
        return (0);
    // Opcionalmente puede empezar con '+' o '-'
    if (str[0] == '-' || str[0] == '+')
        i++;
    // Debe haber al menos un dígito después del signo
    if (str[i] == '\0')
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')  // Si no es dígito
            return (0);
        i++;
    }
    return (1);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

    result = 0;
    sign = 1;
    i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int ft_is_in_int_range(char *str)
{
	long num;
    
    num = ft_atol(str);
	return (num >= INT_MIN && num <= INT_MAX);
}

void ft_free_split(char **tokens)
{
    int i;
    
    i = 0;
    if (!tokens)
        return;
    while (tokens[i] != NULL)
    {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}

int ft_is_duplicate(t_node *stack, int value)
{
    while (stack != NULL)
    {
        if (stack->value == value)
            return (1);
        stack = stack->next;
    }
    return (0);
}

void ft_append_node(t_node **stack, int value)
{
    t_node *new_node;
    t_node *last;
    // Crear el nuevo nodo
    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return;  // Si no se puede asignar memoria, no hace nada
    new_node->value = value;
    new_node->next = NULL;
    // Si la lista está vacía, el nuevo nodo es el primero
    if (*stack == NULL)
    {
        *stack = new_node;
        return;
    }
    // Si la lista no está vacía, encontrar el último nodo
    last = *stack;
    while (last->next != NULL)
        last = last->next;
    // Añadir el nuevo nodo al final
    last->next = new_node;
}

static int ft_parse_args(int argc, char **argv, t_node **stack)
{
    char *token;
    int i;
    long num;

    i = 1;
    while (i < argc)
    {
        // En este caso no necesitas ft_split, ya que argv[i] ya es el número
        token = argv[i];
        
        if (!ft_is_valid_number(token) || !ft_is_in_int_range(token))
            return 0; // Si el número no es válido, devuelve error

        num = ft_atol(token);
        if (ft_is_duplicate(*stack, (int)num))
            return 0; // Si es un número duplicado, devuelve error
        
        ft_append_node(stack, (int)num);
        i++;
    }
    return 1;
}
/*----------------------------------------------------------------------------------------------------------*/

// Función para imprimir el stack
void print_stack(t_node *stack)
{
    t_node *temp = stack;
    while (temp)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

// Función principal
int main(int argc, char **argv)
{
    t_node *stack_a = NULL;

    if (argc < 2)
    {
        printf("Error\n");
        return 1;
    }

    // Parsear los argumentos y llenar el stack
    if (!ft_parse_args(argc, argv, &stack_a))
    {
        write(2, "Error\n", 6);
        // Aquí podemos liberar el stack si es necesario
        t_node *temp;
        while (stack_a)
        {
            temp = stack_a;
            stack_a = stack_a->next;
            free(temp);
        }
        return 1;
    }

    // Imprimir el stack para ver si todo fue insertado correctamente
    printf("Stack A: ");
    print_stack(stack_a);

    // Liberar memoria del stack (al final del programa)
    t_node *temp;
    while (stack_a)
    {
        temp = stack_a;
        stack_a = stack_a->next;
        free(temp);
    }

    return 0;
}
/*
int main(int argc, char **argv)
{
    t_node *stack_a;
    
    stack_a = NULL;
    if (argc < 2)
        return (0);
    // Parsear argumentos al stack a
    if (!ft_parse_args(argc, argv, &stack_a))
    {
        write(2, "Error\n", 6);
        free_stack(stack_a);
        return 1;
    }
    // Validar elementos del stack
    // Normalizar valores si es necesario
    // Llamar a push_swap / implementar algoritmo de ordenación
    free_stack(stack_a);
    return (0);
}
*/