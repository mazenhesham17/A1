#include <iostream>
#include <list>
using namespace std ;

template <class T>
class DoubleList{
private:
    struct Node{
        T data ;
        Node * prev ;
        Node * next ;
        Node( const T _data = T() , Node * _prev = nullptr , Node * _next = nullptr ) : data(_data) , prev(_prev) , next(_next){}
    };
    Node *head , *tail ;
    int list_size ;
public:
    DoubleList(){
        initialize() ;
    }
    DoubleList( T &value , int size ){
        initialize() ;
        for (int i = 0; i < size; ++i) {
            insert(value,begin()) ;
        }
    }
    DoubleList<T>& operator = ( const DoubleList<T>& ob ){
        initialize() ;
        auto it = ob.begin() ;
        while ( it != ob.end() )
            push_back( *it ) ;
        return *this ;
    }
    ~DoubleList(){
        clear() ;
        delete head ;
        delete tail ;
    }
    void initialize(){
        list_size = 0 ;
        head = new Node ;
        tail = new Node ;
        head->next = tail ;
        tail->prev = head ;
    }
    int size(){
        return list_size ;
    }
    bool empty(){
        return list_size == 0 ;
    }
    class iterator{
    private:
        friend class DoubleList<T> ;
        Node *ptr ;
        iterator( Node *_ptr ) : ptr(_ptr) {}
    public:
        T& operator * (){
            return this->ptr->data ;
        }
        bool operator == ( const iterator &ob ){
            return ( this->ptr == ob.ptr ) ;
        }
        bool operator != ( const iterator &ob ){
            return ( this->ptr != ob.ptr ) ;
        }
        iterator operator++ (){
            // exception
            if (this->ptr->next == nullptr )
                throw "out of bounds" ;
            ptr = ptr->next ;
            return *this ;
        }
        iterator operator++ (int){
            // exception
            if (this->ptr->next == nullptr )
                throw "out of bounds" ;
            iterator temp = *this ;
            ptr = ptr->next ;
            return temp ;
        }
        iterator operator-- (){
            if (this->ptr->prev == nullptr)
                throw "out of bounds" ;
            ptr = ptr->prev ;
            return *this ;
        }
        iterator operator-- (int){
            if (this->ptr->prev == nullptr)
                throw "out of bounds" ;
            iterator temp = *this ;
            ptr = ptr->prev ;
            return temp ;
        }
        iterator operator + ( int n ){
            auto it = *this ;
            for (int i = 0; i < n; ++i) {
                try {
                    it++ ;
                }catch ( const char * msg ){
                    throw msg ;
                }
            }
            return it ;
        }
    };
    void insert( iterator position , const T &value  ){
        Node *cur = position.ptr ;
        Node *temp = new Node( value , cur , cur->next ) ;
        if ( cur->next != nullptr )
            cur->next->prev = temp ;
        cur->next = temp ;
        list_size++ ;
    }
    iterator erase( iterator position ){
        Node *cur = position.ptr ;
        iterator temp = cur->next ;
        if ( cur->prev != nullptr )
            cur->prev->next = cur->next ;
        cur->next->prev = cur->prev ;
        delete cur ;
        list_size-- ;
        if ( temp == end() )
            throw "out of bounds" ;
        return temp ;
    }
    void clear(){
        auto it = begin() ;
        while ( it != end() ){
            it = erase(it) ;
        }
    }
    void push_front( const T &value ){
        insert(begin(),value) ;
    }
    void push_back( const T &value ){
        insert(end(),value) ;
    }
    iterator begin() const {
        return iterator(head) ;
    }
    iterator begin() {
        return iterator(head) ;
    }
    iterator end() const {
        return iterator(tail) ;
    }
    iterator end() {
        return iterator(tail) ;
    }
};

int main(){
    DoubleList<int> list ;
    list.insert( list.begin() , 1 ) ;
    list.insert( list.begin() , 2 ) ;
    list.insert( list.begin() , 3 ) ;
    list.insert( list.begin()+1,4) ;
    list.insert( list.begin() , 5 ) ;
    auto it = list.begin() ;
    while ( it != list.end() ){
        cout << *it << '\n' ;
        it++ ;
    }
//    list<int> l ;
//    l.insert(l.begin(),1) ;
//    l.insert(l.begin(),2) ;
//    l.insert(l.begin(),3) ;
//    l.insert(next(l.begin(),1),4) ;
//    l.insert(l.begin(),5) ;
//    for ( auto &it : l ){
//        cout << it << '\n' ;
//    }
    return 0 ;
}