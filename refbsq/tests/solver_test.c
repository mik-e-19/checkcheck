#include "solver.c"
#include "state.c"
#include "state2.c"

int main()
{
	int *board[6];
	int row1[9] = {1, 1, 1, 1, 0, 1, 1, 1, -1};
	int row2[9] = {1, 1, 0, 1, 1, 1, 1, 1, -1};
	int row3[9] = {1, 1, 1, 1, 0, 1, 1, 1, -1};
	int row4[9] = {1, 1, 1, 1, 1, 0, 1, 1, -1};
	int row5[9] = {1, 1, 1, 0, 1, 1, 1, 0, -1};
	board[0] = row1;
	board[1] = row2;
	board[2] = row3;
	board[3] = row4;
	board[4] = row5;
	board[5] = 0;

	char s[200] = "";
	int idx = 0;
	while (idx < 200 && read(0, &s[idx], 1) && s[idx] != '\n')
	{
		write(1, "xd\n", 3);
		idx++;
	}


	solve_board(board);
	print_board(board, "|-x");
}
