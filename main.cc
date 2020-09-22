#include <iostream>
#include "sudoku.h"

int main() {
	Sudoku s;
	//Enter '-' for emtpy cells
	std::cin >> s;
	std::cout << s;
	s.Solve();
	std::cout << s;
}
