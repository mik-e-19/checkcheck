/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solved.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloh <mloh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 00:03:03 by mloh              #+#    #+#             */
/*   Updated: 2021/03/08 00:03:09 by mloh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// (need to polish)
int max(highest, dpb) {
    (highest < dpb) ? return(matrixnum) : return(total);
}

// ver.1 (need to polish)
int min(a, b, c) {
    if (a < b && a < c)
        return a
    else if (b < c && b < a)
        return b
    else if (c < a && c < b)
        return c
}

// ver.2 (need to polish)
int min(a, b, c) {
    int arr[] = {a, b, c};
    int mn = arr[0];
    int i;

    i = 0;
    while (i < 3) {
        if (arr[i] < mn)
            mn = arr[i];
    }
    return mn;
}

// largest (int) = 0 and end_pt (int) = 0 go to struct 
struct solve(int** matrix, int** dup, s_size size, emptySymbol)
{   
    struct s;
    int row;
    int col;

    row = -1;
    while (s.end_pt++ < 2) 
    {
        while (++row < size.len) 
        {
            col = -1;
            while (++col < size.width) 
            {
                if (matrix[row][col] == emptySymbol) 
                {
                    dup[row][col] == 1;
                    if (row > 0 && col > 0)
                        dup[row][col] += min(dup[row-1][col], dup[row][col-1], dup[row-1][col-1]);
                    s.largest = max(s.largest, dup[row][col]);
                ((s.end_pt > 0) && (dup[row][col] == s.largest)) ? return (s.row, s.col, s.largest);
                }
            }
        }
    }
}
