#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;


class Sorter {
public:
    virtual void Sort( vector<int>&v , int l , int r ) = 0 ;
};

class selectionSorter : public Sorter{
public:
    void Sort( vector<int>&v , int l , int n ) {
        n++ ;
        for (int i = 0; i < n; ++i) {
            int id = i;
            for (int j = i + 1; j < n; ++j) {
                if (v[j] < v[id])
                    id = j;
            }
            swap(v[id], v[i]);
        }
    }
};

class quickSorter : public Sorter {
private:
    void medianofThree( vector<int> &v, int l, int r ){
        int mid = l + (r - l) / 2;
        if (v[r] < v[l])
            swap(v[l], v[r]);
        if (v[mid] < v[l])
            swap(v[mid], v[l]);
        if (v[r] < v[mid])
            swap(v[mid], v[r]);
        swap(v[mid],v[r]) ;
    }
    int quickPart(vector<int> &v, int l, int r) {
        medianofThree(v,l,r) ;
        int pivot = v[r] , i = l - 1 ;
        for (int j = l; j < r; ++j) {
            if ( v[j] < pivot ){
                i++ ;
                swap(v[i],v[j]) ;
            }
        }
        swap(v[i+1],v[r]) ;
        return (i+1) ;
    }
public:
    void Sort( vector<int> &v, int l, int r ) {
        if (l >= r) return;
        int mid = quickPart(v, l, r);
        Sort(v, l, mid - 1);
        Sort(v, mid + 1, r);
    }
};


class Testbed {
public:
    vector<int> generateRandomList(int min, int max, int size) {
        vector<int> random(size);
        srand(time(0));
        for (int i = 0; i < size; ++i) {
            random[i] = min + rand() % (max - min + 1);
        }
        return random;
    }

    vector<int> generateOrderedList(int min, int max, int size) {
        vector<int> random = generateRandomList(min, max, size);
        sort(random.begin(), random.end());
        return random;
    }

    vector<int> generateReverseOrderedList(int min, int max, int size) {
        vector<int> random = generateOrderedList(min, max, size);
        reverse(random.begin(),random.end()) ;
        return random;
    }

    double runOnce( Sorter *sorter , vector<int>&data , int size  ) {
        auto start = chrono::steady_clock::now();
        sorter->Sort(data,0,size-1) ;
        auto end = chrono::steady_clock::now();
        double diff = chrono::duration<double, milli>(end - start).count();
        return diff;
    }

    double runAverage( Sorter *sorter , bool type , int min , int max, int size, int sets_num ){
        double total_time = 0 ;
        for (int i = 0; i < sets_num; ++i) {
            vector<int> random ;
            if ( type == 0 ){
                random = generateOrderedList(min,max,size) ;
            }else{
                random = generateReverseOrderedList(min,max,size) ;
            }
            auto start = chrono::steady_clock::now();
            sorter->Sort(random,0,size-1) ;
            auto end = chrono::steady_clock::now();
            total_time += chrono::duration<double, milli>(end - start).count();
        }
        return total_time/sets_num ;
    }
};

int main() {
    Testbed t1;
    vector<int> v = t1.generateReverseOrderedList(2, 10, 10) ;
    Sorter *sorter ;
    sorter = new quickSorter ;
    cout << t1.runAverage(sorter,1,1,1000,10000,10) << " ms.\n" ;
    return 0;
}