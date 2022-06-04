#include <iostream>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

int Matrix::countmatr = 0;

// копирование
Matrix::Matrix(const Matrix& m) {
    count++;
    num = countmatr;
    dim = m.dim;
    b = m.b;
    cout << "Constructed matrix with number: " << num << endl;
}
// конструктор
Matrix::Matrix(int d) {
    countmatr++;
    num = countmatr;
    dim = d;

    b = new double *[dim];
    for (int i = 0; i < dim; i++) {
        b[i] = new double[dim];
    }

    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            b[i][j] = 0;

    cout << endl << "Constructor matr(int) made new matrix #" << number << endl << endl;
}
// контруктор массива
Matrix::Matrix(int d,double **x) {
    countmatr++;
    num = countmatr;
    dim = d;

    if(dim < 0){
        cout << "Ops...Insert number that is bigger than 0" << endl;
        exit;
    }

    b = new double *[dim];
    for (int i = 0; i < dim; i++)
        b[i] = new double[dim];

    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            b[i][j] = x[i][j];

    cout << endl << "Constructor matr(int, double**) made new matrix #" << number << endl << endl;
}

// деструктор
Matrix::~Matrix(){
    cout << "Destructor of matrix #"<< number << endl;
    delete[] b;

// сумма матриц
Matrix Matrix::operator+(const Matrix &m)
{
    cout << "Summing matrix #" << num << " with matrix #" << m.num << endl;
    Matrix tmp(dim);
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            tmp.b[i][j] = b[i][j] + m.b[i][j];
    return tmp;

// вычитание матриц
Matrix Matrix::operator+(const Matrix &m) {
    cout << "Subtracting matrix #" << num << " with matrix #" << m.num << endl;
    Matrix tmp(dim);
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            tmp.b[i][j] = b[i][j] - m.b[i][j];
    return tmp;
}

// унарный минус
Matrix Matrix::operator-() {
    cout << "Make matrix# negativity" << num << endl;
    for (int i = 0; i < this->dim; i++)
        for (int j = 0; j < this->dim; j++)
            b[i][j] = -b[i][j];
    return *this;
}

// присваивание
Matrix & Matrix::operator=(Matrix &m) {
    cout << "Assign matrix #" << num << " with matrix #" << m.num << endl;
    delete[] b;
    this->dim = m.dim;
    b = new double[dim];
    for (int i = 0; i < this->dim; i++)
        for (int j = 0; j < this->dim; j++)
            this->b[i][j] = m.b[i][j];
    return *this;
}

// умножение двух матриц
Matrix Matrix::operator*(const Matrix &m){
    if (m.dim != dim) {
        cout << "Ops...matrices have different dimensions" << endl;
        exit(0);
    } else {
        cout << "Multiplying matrix #" << dim << " with matrix #" << m.dim << endl;
        double result = 0;
        for (int i = 0; i < dim; i++)
            for (int j = 0; j < dim; j++){
            result += b[i][j] * m.b[i][j];
        }
        return result;
    }
}

// произведение матрицы на число
Matrix Matrix&::operator*(double c){
        if (m.dim != dim) {
            cout << "Ops...matrices have different dimensions" << endl;
            exit(0);
        } else
            cout << "Multiplying matrix #" << dim << " with number" << m.dim << endl;
        double result = 0;
        cin >> "Input number: " >> c >> endl;
        for (int i = 0; i < dim; i++)
            for (int j = 0; j < dim; j++) {
                result += b[i][j] * c;
            }
        return result;
    }
}
// произведение матрицы на вектор
Matrix Vector::operator*(const Vector& v){
    cout << "Multiplying matrix #" << "with vector #" << endl;
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++) {
            result += b[i][j] * vect2.v[i];
        }
    return result;
}
//вывод
void Matrix::print() const {
    cout << "Matrix #" << number << endl;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

