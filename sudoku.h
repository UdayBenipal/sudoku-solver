#ifndef SUDOKU_H
#define SUDOKU_H
#include <iostream>
#include <vector>

class Sudoku {
	int board[81];
	bool validate(int index);
public:
	bool Solve();
	friend std::ostream &operator<<(std::ostream &out, const Sudoku &s);
	friend std::istream &operator>>(std::istream &in, Sudoku &s);
};

#endif
