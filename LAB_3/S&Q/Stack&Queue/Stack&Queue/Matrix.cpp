#include "Matrix.h"

Matrix::Matrix(int r, int c) {
	rows = r;
	cols = c;
	data = new int* [rows];
	for (int i = 0; i < rows; i++) {
		data[i] = new int[cols];
	}
}
Matrix::~Matrix() {
}

void Matrix::setElement(int r, int c, int value) {
	if (r >= 0 && r < rows && c >= 0 && c < cols) {
		data[r][c] = value;
	}
}
int Matrix::getElement(int r, int c) {
	return data[r][c];
}
bool Matrix::isValid(Point p) {
	int x = p.getX();
	int y = p.getY();
	if (x >= 0 && x < rows && y >= 0 && y < cols) {
		return (data[x][y] == 1);
	}
	return false;

}
void Matrix::printMatrix() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << data[j][i] << " ";
		}
		cout << endl;
	}
}
void Matrix::generateRandom(float obstacleDensity) {
	srand(time(0));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			float r = (float) rand() / RAND_MAX;
			if (r < obstacleDensity) {
				data[i][j] = 0;
			}
			else {
				data[i][j] = 1;
			}
		}
	}
}