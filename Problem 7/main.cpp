#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

void BiasedSort( vector<string>&v ){
    int n = v.size() ;
    for (int i = 0; i < n; ++i) {
        int mn = i ;
        for (int j = i + 1 ; j < n; ++j) {
            if ( v[j] == "Untitled" ){
                mn = j ;
                break;
            }else if ( v[j] < v[mn] ){
                mn = j ;
            }
        }
        swap(v[i],v[mn]) ;
    }
}

int main(){
    int n ; cin >> n ;
    vector<string> v(n) ;
    for (int i = 0; i < n; ++i) {
        cin >> v[i] ;
    }
    BiasedSort(v) ;
    for (int i = 0; i < n; ++i) {
        cout << v[i] << '\n' ;
    }

    return 0 ;
}