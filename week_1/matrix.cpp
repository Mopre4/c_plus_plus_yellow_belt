#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
using namespace std;

class Matrix {
public:
	Matrix() {
		row = 0;
		col = 0;
		matrix_elements.assign(0, { 0 });
	}
	Matrix(int num_rows, int num_cols) {
		Reset(num_rows, num_cols);
	}
	void Reset(int num_rows, int num_columns) {
		if (num_rows < 0) {
			throw out_of_range("num_rows must be >= 0");
		}
		if (num_columns < 0) {
			throw out_of_range("num_columns must be >= 0");
		}
		if (num_rows == 0 || num_columns == 0) {
			num_rows = num_columns = 0;
		}

		row = num_rows;
		col = num_columns;
		matrix_elements.assign(num_rows, vector<int>(num_columns));
	}

	int& At(int row, int column) {
		return matrix_elements.at(row).at(column);
	}

	int At(int row, int column) const {
		return matrix_elements.at(row).at(column);
	}
	int GetNumRows() const {return row;}
	int GetNumColumns() const { return col; }

	void Insert_value(int i, int j, int value) {
		matrix_elements[i][j] = value;
	}

	vector<vector<int>> GetMatrix() const {
		return matrix_elements;
	}
private:
	int row;
	int col;
	vector<vector<int>> matrix_elements;

};
istream& operator>>(istream& input, Matrix& matrix) {
	int row, col, value;
	input >> row >> col;
	matrix = Matrix(row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			input >> value;
			matrix.Insert_value(i, j, value);
		}
	}
	return input;
}
bool operator==(const Matrix& rhs, const Matrix& lhs) {
	if (rhs.GetNumColumns() != lhs.GetNumColumns()) {
		return false;
	}
	if (rhs.GetNumRows() != lhs.GetNumRows()) {
		return false;
	}
	for (int i = 0; i < rhs.GetNumRows(); i++) {
		for (int j = 0; j < rhs.GetNumColumns(); j++) {
			if (rhs.GetMatrix()[i][j] != lhs.GetMatrix()[i][j]) {
				return false;
			}
		}
	}
	return true;
}
Matrix operator+(const Matrix& rhs, const Matrix& lhs) {
	Matrix res(rhs.GetNumRows(), rhs.GetNumColumns());
	if (rhs.GetNumRows() != lhs.GetNumRows()) {
		throw invalid_argument("Mismatched number of rows");
	}

	if (rhs.GetNumColumns() != lhs.GetNumColumns()) {
		throw invalid_argument("Mismatched number of columns");
	}
	for (int i = 0; i < rhs.GetNumRows(); i++) {
		for (int j = 0; j < rhs.GetNumColumns(); j++) {
			res.Insert_value(i, j, rhs.GetMatrix()[i][j] + lhs.GetMatrix()[i][j]);
		}
	}
	return res;
}
ostream& operator<<(ostream& output, const Matrix& matrix) {
	output << matrix.GetNumRows() << " " << matrix.GetNumColumns() <<endl;
	for (auto i : matrix.GetMatrix()) {
		for (auto j : i) {
			output << j << " ";

		}
		output << endl;
	}
	return output;
}

int main() {
	Matrix one;
	Matrix two;

	cin >> one >> two;
	cout << one + two << endl;
	return 0;
}