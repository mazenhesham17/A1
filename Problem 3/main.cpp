# include <iostream>

using namespace std ;

template <class T >
class Matrix{
    private:
    T **mat ;
    int row ;
    int col ;
    public:
    Matrix( int _row = 0 , int _col = 0 ){
        row = _row , col = _col ;
        mat = new T*[row] ;
        for ( int i = 0 ; i < row ; i++ ){
            mat[i] = new T[col] ;
        }
    }
    Matrix( const Matrix<T> &ob ){
        row = ob.row , col = ob.col ;
        mat = new T*[row] ;
        for ( int i = 0 ; i < row ; i++ ){
            mat[i] = new T[col] ;
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                mat[i][j] = ob.mat[i][j] ;
            }
        }
    }
    friend ostream& operator<< ( ostream& os , const Matrix<T> &ob ){
        for ( int i = 0 ; i < ob.row ; i++ ){
            for ( int j = 0 ; j < ob.col ; j++ ){
                os << ob.mat[i][j] << ' ' ; 
            }
            os << '\n' ;
        }
        return os ;
    }
    friend istream& operator>> ( istream& is , Matrix<T> &ob ){
        for ( int i = 0 ; i < ob.row ; i++ ){
            for ( int j = 0 ; j < ob.col ; j++ ){
                is >> ob.mat[i][j] ;
            }
        }
        return is ;
    }
    Matrix<T> operator + ( const Matrix<T>& ob ){
        if ( ob.row == row && ob.col == col ){
            Matrix<T> temp(row,col) ;
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    temp.mat[i][j] = mat[i][j] + ob.mat[i][j] ;
                }
            }
            return temp ;
        }
    }
    Matrix<T> operator - ( const Matrix<T>& ob ){
        if ( ob.row == row && ob.col == col ){
            Matrix<T> temp(row,col) ;
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    temp.mat[i][j] = mat[i][j] - ob.mat[i][j] ;
                }
            }
            return temp ;
        }
    }
    Matrix<T> operator * ( const Matrix<T>& ob ){
        if ( col == ob.row ){
            Matrix<T> temp(row,ob.col) ;
            int n = row , m = ob.col ;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    temp.mat[i][j] = 0 ;
                    for (int k = 0; k < col; ++k) {
                        temp.mat[i][j] += mat[i][k]*ob.mat[k][j] ;
                    }
                }
            }
            return temp ;
        }
    }
    ~Matrix(){
        for ( int i = 0 ; i < row ; i++ ){
            delete [] mat[i] ;
        }
        delete [] mat ;
    }
};

int main(){
    Matrix<int> mat1(3,2) , mat2(2,3) ;
    cin >> mat1 >> mat2 ;
    cout << mat1 * mat2 << '\n' ;
    return 0 ;
}

/*
1 2 3
4 5 6
1 2
3 4
5 6
 * */