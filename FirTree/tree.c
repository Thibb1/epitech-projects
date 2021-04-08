/*
** EPITECH PROJECT, 2020
** fir_tree
** File description:
** prints a tree given the input number
*/

void my_putchar(char c);

void tree_top_print_layer(int tree_width, int layer_width)
{
    int i = 0;

    while (i < tree_width - layer_width / 2) {
        my_putchar(' ');
        i++;
    }
    for (i = 0; i < layer_width; i++)
        my_putchar('*');
    my_putchar('\n');
}

void tree_top_loop(int tree_height, int tree_width)
{
    int i = 0;
    int iteration = 0;
    int layer_width = 1;

    while (i < tree_height) {
        tree_top_print_layer(tree_width, layer_width);
        layer_width = layer_width + 2;
        iteration++;
        if (iteration == i + 4) {
            i++;
            layer_width = layer_width - (i + 2) - i % 2;
            iteration = 0;
        }
    }
}

void tree_bot_loop(int bot_width, int tree_width)
{
    int i = 0;
    int b;
    int bot_height = bot_width;

    bot_width = bot_width + 1 - bot_width % 2;
    while (i < bot_height) {
        for (b = 0; b < tree_width - bot_width / 2; b++)
            my_putchar(' ');
        for (b = 0; b < bot_width; b++)
            my_putchar('|');
        my_putchar('\n');
        i++;
    }
}

void tree(int tree_height)
{
    int i = 1;
    int branch_width = 2;
    int tree_width = 0;

    if (tree_height <= 0)
        return;
    while (i < tree_height + 1) {
        branch_width = i % 2 + branch_width;
        tree_width = tree_width + branch_width;
        i++;
    }
    tree_top_loop(tree_height, tree_width);
    tree_bot_loop(tree_height, tree_width);
}
