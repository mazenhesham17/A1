#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
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
        // medianofThree(v,l,r) ;
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

    double runAverage( Sorter *sorter , int type , int min , int max, int size, int sets_num ){
        double total_time = 0 ;
        for (int i = 0; i < sets_num; ++i) {
            vector<int> random ;
            if ( type == 0 ){
                random = generateOrderedList(min,max,size) ;
            }else if ( type == 1 ){
                random = generateReverseOrderedList(min,max,size) ;
            }else{
                random = generateRandomList(min,max,size) ;
            }
            auto start = chrono::steady_clock::now();
            sorter->Sort(random,0,size-1) ;
            auto end = chrono::steady_clock::now();
            total_time += chrono::duration<double, milli>(end - start).count();
        }
        return total_time/sets_num ;
    }

    vector<pair<int,double>> runExperiment ( Sorter *sorter , int type , int min , int max, int min_val , int max_val , int sets_num , int step ){
        vector<pair<int,double>> records ;
        for (int i = min_val ; i <= max_val ; i += step ) {
            records.push_back({i, runAverage(sorter,type,min,max,i,sets_num)}) ;
        }
        return records ;
    }
};

int main() {
    Testbed testbed ;
    Sorter *sorter ;
    sorter = new selectionSorter ;
    auto records = testbed.runExperiment(sorter,2,10,10000000,1000,10000,15,1000) ;
    cout << "Complexity Analysis for Selection Sort\n" ;
    cout << "Input Size  Execution time\n" ;
    for ( auto &it : records ){
        cout << setw(10) << it.first << "  " << fixed << setprecision(4) << it.second << " ms.\n" ;
    }
    return 0;
}