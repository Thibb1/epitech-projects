/*
** EPITECH PROJECT, 2020
** count valid queen
** File description:
** counts valid queen placement
*/

static int array[200][200];

int my_solve(int col, int n, int sol);

int queentest(int row, int col, int n);

int testrowclear(int testrow, int testcol);

int testupdiag(int testrow, int testcol, int n);

int my_solve(int col, int n, int sol)
{
    if (col >= n) {
        sol++;
        return (sol);
    }
    for (int testrow = 0; testrow < n; testrow++) {
        if (queentest(testrow, col, n)) {
            array[testrow][col] = 1;
            sol = my_solve(col + 1, n, sol);
            array[testrow][col] = 0;
        }
    }
    return (sol);
}

int queentest(int r, int c, int n)
{
    int d = testrowclear(r, c) + testupdiag(r, c, n);

    if (d == 2)
        return (1);
    return (0);
}

int testrowclear(int testrow, int testcol)
{
    int row = testrow;
    int col = testcol;
    for (; row >= 0 && col >= 0; row--, col--)
        if (array[row][col])
            return (0);
    for (col = 0; col < testcol; col++)
        if (array[testrow][col])
            return (0);
    return (1);
}

int testupdiag(int testrow, int testcol, int n)
{
    int row = testrow;
    int col = testcol;

    while (col >= 0 && row < n) {
        if (array[row][col])
            return (0);
        row++;
        col--;
    }
    return (1);
}

int  count_valid_queens_placements(int n)
{
    int row = 0;
    int col = 0;
    int sol = 0;

    if (n < 1)
        return (0);
    for (; row < n; row++)
        for (col = 0; col < n; col++)
            array[row][col] = 0;
    return (my_solve(0, n, sol));
}
