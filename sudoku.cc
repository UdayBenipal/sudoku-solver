#include "sudoku.h"

bool Sudoku::Solve() {
	std::vector<int> empty_cell;
	for(int i = 0; i < 81; ++i) {
		if(!board[i]) empty_cell.emplace_back(i);
	}
	int i = 0;
	while(i < empty_cell.size()) {
		if(i < 0) return false;
		if(validate(empty_cell[i])) {
			i+=1;
		} else {
			i-=1;
		}
	}
	return true;
}


bool Sudoku::validate(int index) {
	bool row[10];
	bool col[10];
	bool box[10];
	for(int i = 1; i < 10; ++i) {
		row[i] = col[i] = box[i] = true;
	}

	int row_start = (index / 9) * 9;
	for(int i = 0; i < 9; ++i) {
		row[board[row_start+i]] = false;
	}

	int col_start = index % 9;
	for(int i = 0; i < 9; ++i) {
		col[board[col_start+(i*9)]] = false;
	}

	int box_start = ((index/27)*27)+((col_start/3)*3);
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			box[board[box_start+j]] = false;
		}
		box_start+=9;
	}

	for(int i = 1; i < 10; ++i) {
		if(row[i] && col[i] && box[i] &&
			board[index] < i) {
			board[index] = i;
			return true;
		}
	}
	board[index] = 0;
	return false;
}


std::ostream &operator<<(std::ostream &out, const Sudoku &s) {
	for(int i = 0; i < 81; ++i) {
		int col = i%9;

		if(i%27==0) out << " -----------------------" << std::endl;
		if(col%3==0) out << "| ";

		if(s.board[i] != 0) {
			out << s.board[i] << " ";
		} else {
			out << "  ";
		}

		if(col==8) out << "|" << std::endl;
	}
	out << " -----------------------" << std::endl;
	return out;
}

std::istream &operator>>(std::istream &in, Sudoku &s) {
	char c;
	int i = 0;
	while(in >> c) {
		if('1' <= c && c <= '9') {
			s.board[i] = c - '1' + 1;
		} else {
			s.board[i] = 0;
		}
		i+=1;
	}
	return in;
}
