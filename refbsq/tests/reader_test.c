#include "parser.c"
#include "solver.c"
#include "state.c"
#include "state2.c"
#include "reader.c"

int main()
{
	char s[4] = "aaa";
	char *chrset = s;

	int **board = read_map(0, &chrset);
	solve_board(board);
	print_board(board, chrset);
}
