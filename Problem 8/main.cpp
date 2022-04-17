#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std ;


template <class T>
void insertionSort( vector<T>&v ){
    int n = v.size() ;
    for (int i = 1; i < n; ++i) {
        T temp = v[i] ;
        int j ;
        for ( j = i ; j > 0 && temp < v[j-1] ; j-- ){
            v[j] = v[j-1] ;
        }
        v[j] = temp ;
    }
}


template <class T>
void binaryInsertionSort( vector<T>&v ){
    int n = v.size() ;
    for (int i = 0; i < n; ++i) {
        T temp = v[i] ;
        int l = -1 , r = i ;
        // TTTTFFF
        while ( r - l != 1 ){
            int mid = l + (r-l)/2 ;
            if ( v[mid] > temp ){
                r = mid ;
            }else{
                l = mid ;
            }
        }
        int j ;
        for ( j = i ; j > r ; j-- ){
            v[j] = v[j-1] ;
        }
        v[j] = temp ;
    }
}

template<class T>
double execution_time ( vector<T> &v , void (*func)( vector<T>& ) ){

    auto start = chrono::steady_clock::now();
    func(v) ;
    auto end = chrono::steady_clock::now();

    double diff = chrono::duration<double,milli> ( end - start ).count() ;
    return diff ;
}



int main(){
    srand(time(0)) ;
    int n = 100000 ;
    vector<int> v(n) , m ;
    generate(v.begin(),v.end(),rand) ;
    m = v ;
    cout << "Execution Time for basic insertion sort : " << execution_time(v,&insertionSort) << " ms.\n" ;
    cout << "Execution Time for binary insertion sort : " << execution_time(m,&binaryInsertionSort) << " ms.\n" ;
    return 0 ;
}