/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   may_the_fourth_be_with_you.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afindo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:08:48 by afindo            #+#    #+#             */
/*   Updated: 2021/10/10 22:50:01 by afindo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

const int n = 6;

void print_matrix()         //da fare
{

}

void free_matrix()          //da fare
{

}



int **alloc_matrix()
{
    int    **mat;
    int i;
	int j;

    mat = (int **)malloc(n * sizeof(int *));
    i = -1;
    while (++i < n) {
        mat[i] = (int *)malloc(n * sizeof(int));
		j = 0;
		while (j < n)
			mat[i][j++] = 0;
	}
    return (mat);
}

char *array(char *s) {
    int i;
    int j;
    char *str = (char*)malloc(sizeof(char) * 16);

    i = 0;
    j = 0;
    while (i < 16) 
    {
        str[i++] = s[j];
        j += 2;
    }
    str[i] = '\0';
    return(str);
}

void input_line(int **mat, char *s)
{
    int row;
    int col;
    int i;
    int j;

    row = 0;
    j = 0;
    while (row < n)
    {
        col = 0;
        i = 0;
        while (col < n)
        {
            if ((row == 0 && col == 0) || (row == n -1 && col == 0) ||
                    (col == n - 1 && row == 0) || (row == n -1 && col == n - 1))
            {
                mat[row][col] = 0;
                col++;
                continue ;
            }
            int x = i % 4;
            char y = s[i%4];
            if (row == 0)
                mat[row][col] = s[i++ % 4] - 48;
            else if (row == n - 1)
                mat[row][col] = s[i++ % 4 + 4] - 48;
            else if (col == 0)
                mat[row][col] = s[j % 4 + 8] - 48;
            else if (col == n - 1)
                mat[row][col] = s[j++ % 4 + 12] - 48;
            col++;
        }
    row++;
    }
}

int check_input()           //da fare
{

}



void one_to_four(int **mat, int index, int i, int direction)    //dir = 0 ord. crescente
{                                                               //dir = 1 ord. decrescente
    int up;
    int down;
    int left;
    int right;

    if (i == n - 1)
        return ;
    up = mat[0][(index % 4) + 1];
    down = mat[5][(index % 4) + 1];
    left = mat[(index % 4) + 1][0];
    right = mat[(index % 4) + 1][5];
    if ((up == 1 && down == 4) || (up == 4 && down == 1))         // aggiungi per colonne
        if(direction == 0)
            mat[i][(index % 4) + 1] = i;
        else
            mat[i][(index % 4) + 1] = n - i - 1;
    else if ((left == 1 && right == 4) || (left == 4 && right == 1))       // aggiungi per righe
        if (direction == 0)
            mat[(index % 4) + 1][i] = i;
        else
            mat[(index % 4) + 1][i] = n - i - 1;
    one_to_four(mat, index, i + 1, direction);
}

void put_three(int **mat, int index, int direction)
{
    int up;
    int down;
    int left;
    int right;

    up = mat[0][(index % 4) + 1];
    down = mat[5][(index % 4) + 1];
    left = mat[(index % 4) + 1][0];
    right = mat[(index % 4) + 1][5];
    if ((up == 1 && down == 2) || (up == 2 && down == 1))
    {
        if (direction == 0)
            mat[1][(index % 4) + 1] = 3;
        else
            mat[4][(index % 4) + 1] = 3;
    }
    else if ((left == 1 && right == 2) || (left == 2 && right == 1))
    {
        if (direction == 0)
            mat[(index % 4) + 1][1] = 3;
        else
            mat[(index % 4) + 1][4] = 3;
    }
}

void find_one(int **mat, int index)
{
	int up;
	int down;
	int right;
	int left;

	if (index == n - 2)
		return ;
	up = mat[0][(index % 4) + 1];			//per colonne	riga + 1
	down = mat[5][(index % 4) + 1];	        //per colonne	riga - 1
	left = mat[(index % 4) + 1][0];			//per righe 	colonna + 1
	right = mat[(index % 4) + 1][5];	    //per righe		colonna - 1
	if (up == 1)
        mat[1][(index % 4) + 1] = 4;
    if (down == 1)
        mat[4][(index % 4) + 1] = 4;
    if (left == 1)
        mat[(index % 4) + 1][1] = 4;
    if (right == 1)
        mat[(index % 4) + 1][4] = 4;
    if ((up == 1 && down == 4) || (up == 4 && down == 1))           //completo la riga da 1 a 4
        one_to_four(mat, index, 1, up == 1);
    if ((left == 1 && right == 4) || (left == 4 && right == 1))     //completo la riga da 1 a 4
        one_to_four(mat, index, 1, left == 1);
    if ((up == 1 && down == 2) || (up == 2 && down == 1))
        put_three(mat, index, up == 1);
    if ((left == 1 && right == 2) || (left == 2 && right == 1))
        put_three(mat, index, left == 1);
    find_one(mat, index + 1);
}




int find_value(int *a, int val)
{
    if (*a == '\0')
        return (0);
    if (*a == val)
        return (1);
    return (find_value(a + 1, val));
}

int *make_col_array(int **mat,int i, int j)
{
    int a[4];
    int k = 0;

    k = 0;
    while (j < 5)
        a[k++] = mat[i][j++];
    return a;
}

void fill_row(int *a, int pos)
{
    int i;

    i = 1;
    while (i < 5)
    {
        if (find_value(a,i) == 1)
            i++;
        else
        {
            a[pos] = i;
            break ;
        }
    }
}

int check_row()
{

}

void fill_col()
{

}

int check_col()
{

}

int solve_matrix(int **mat)
{
    int i;
    int j;

    i = 1;
    while (i < 5)
    {
        j = 1;
        while (j < 5)
        {
            
        }
    }
}



int main (void)
{
    char *str = "3 4 1 2 2 1 2 2 2 2 1 2 2 1 4 3";
    int **mat = alloc_matrix(n);
    input_line(mat, array(str));

    printf("%s\n\n", str);
    find_one(mat, 0);

    /*if (solve_matrix() == 1)
        print_matrix();
    else
        write(1, "Error\n", 6);*/

	for (int i = 1; i < n - 1; i++) {
       for (int j = 1; j < n - 1; j++) {
            printf("  %d  ", mat[i][j]);
         }
        printf("\n\n");
    }
    return (0);
}
