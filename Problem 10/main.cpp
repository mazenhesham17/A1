#include <iostream>
#include <list>

using namespace std;

template<class T>
class DoubleList {
private:
    struct Node {
        T data;
        Node *prev;
        Node *next;

        Node(const T _data = T(), Node *_prev = nullptr, Node *_next = nullptr) : data(_data), prev(_prev),
                                                                                  next(_next) {}
    };

    Node *head, *tail, *dummy;
    int list_size;
public:
    void initialize() {
        list_size = 0;
        head = nullptr;
        tail = nullptr;
        dummy = new Node;
        dummy->next = nullptr;
    }

    DoubleList() {
        initialize();
    }

    DoubleList(T &value, int size) {
        initialize();
        for (int i = 0; i < size; ++i) {
            insert(value, begin());
        }
    }

    DoubleList(const DoubleList<T> &ob) {
        initialize();
        auto it = ob.begin();
        while (it != ob.end()) {
            push_back(*it);
            it++;
        }
    }

    DoubleList<T> &operator=(const DoubleList<T> &ob) {
        initialize();
        auto it = ob.begin();
        while (it != ob.end()) {
            push_back(*it);
            it++;
        }
        return *this;
    }

    ~DoubleList() {
        clear();
        delete head;
        delete tail;
        delete dummy;
    }

    int size() {
        return list_size;
    }

    bool empty() {
        return head == nullptr;
    }

    class iterator {
    private:
        friend class DoubleList<T>;

        Node *ptr;

        iterator(Node *_ptr) : ptr(_ptr) {}

    public:
        T &operator*() {
            return this->ptr->data;
        }

        bool operator==(const iterator &ob) {
            return (this->ptr == ob.ptr);
        }

        bool operator!=(const iterator &ob) {
            return (this->ptr != ob.ptr);
        }

        iterator operator++() {
            // exception
            if (ptr->next == nullptr)
                throw "out of bounds";
            ptr = ptr->next;
            return *this;
        }

        iterator operator++(int) {
            // exception
            if (ptr->next == nullptr)
                throw "out of bounds";
            iterator temp = *this;
            ptr = ptr->next;
            return temp;
        }

        iterator operator--() {
            if (ptr->prev == nullptr)
                throw "out of bounds";
            ptr = ptr->prev;
            return *this;
        }

        iterator operator--(int) {
            if (ptr->prev == nullptr)
                throw "out of bounds";
            iterator temp = *this;
            ptr = ptr->prev;
            return temp;
        }

        iterator operator+(int n) {
            auto it = *this;
            for (int i = 0; i < n; ++i) {
                it++;
            }
            return it;
        }
    };

    void insert(iterator position, const T &value) {
        Node *cur = position.ptr;
        if (position == begin()) {
            push_front(value);
        } else if (position == end()) {
            push_back(value);
        } else {
            Node *temp = new Node(value, cur, cur->next);
            if (cur->next != nullptr)
                cur->next->prev = temp;
            cur->next = temp;
            list_size++;
        }
    }

    iterator erase(iterator position) {
        if (list_size == 0)
            throw "emptylist";
        Node *cur = position.ptr;
        if (position == end()) {
            throw "out of bounds";
        } else if (position == begin()) {
            pop_front();
            return begin();
        } else if (position == --end()) {
            pop_back();
            return --end();
        } else {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete cur;
            list_size--;
        }
        return position;
    }

    void pop_front() {
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        list_size--;
    }

    void pop_back() {
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
        } else {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = dummy;
            delete temp;
        }
        list_size--;
    }

    void clear() {
        auto it = begin();
        while (size()) {
            pop_front();
        }
    }

    void push_front(const T &value) {
        Node *temp = new Node(value);
        if (head == nullptr) {
            head = tail = temp;
            head->prev = nullptr;
            tail->next = dummy;
            dummy->prev = tail;
        } else {
            temp->next = head;
            temp->prev = nullptr;
            head->prev = temp;
            head = temp;
        }
        list_size++;
    }

    void push_back(const T &value) {
        Node *temp = new Node(value);
        if (tail == nullptr) {
            head = tail = temp;
            head->prev = nullptr;
            tail->next = dummy;
            dummy->prev = tail;
        } else {
            temp->next = nullptr;
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
            tail->next = dummy;
            dummy->prev = tail;
        }
        list_size++;
    }

    iterator begin() const {
        return iterator(head);
    }

    iterator begin() {
        return iterator(head);
    }

    iterator end() const {
        return iterator(dummy);
    }

    iterator end() {
        return iterator(dummy);
    }
};

int main() {
    DoubleList<int> list;
    if (list.empty()) {
        cout << "The list is empty.\n";
    }
    const int n = 15;
    for (int i = 0; i < n; ++i) {
        try {
            list.insert(list.begin(), 1);
        } catch (const char *msg) {
            cout << "There's something went wrong.\n";
            cout << "Error Message : " << msg << "\n\n";
        }
    }
    DoubleList<int> list2 = list;
    DoubleList<int>::iterator it = list.begin();
    while (it != list.end()) {
        cout << *it << ' ';
        it++;
    }
    cout << '\n';
    for (int i = 0; i < n; ++i) {
        try {
            list.insert(list.end(), 15);
        } catch (const char *msg) {
            cout << "There's something went wrong.\n";
            cout << "Error Message : " << msg << "\n\n";
        }
    }
    it = list.begin();
    while (it != list.end()) {
        cout << *it << ' ';
        it++;
    }
    cout << '\n';
    try {
        list.erase(list.begin());
    } catch (const char *msg) {
        cout << "There's something went wrong.\n";
        cout << "Error Message : " << msg << "\n\n";
    }
    try {
        list.erase(list.begin());
    } catch (const char *msg) {
        cout << "There's something went wrong.\n";
        cout << "Error Message : " << msg << "\n\n";
    }
    try {
        list.erase(list.begin());
    } catch (const char *msg) {
        cout << "There's something went wrong.\n";
        cout << "Error Message : " << msg << "\n\n";
    }
    try {
        list.erase(list.begin());
    } catch (const char *msg) {
        cout << "There's something went wrong.\n";
        cout << "Error Message : " << msg << "\n\n";
    }
    try {
        list.erase(--list.end());
    } catch (const char *msg) {
        cout << "There's something went wrong.\n";
        cout << "Error Message : " << msg << "\n\n";
    }
    try {
        list.erase(--list.end());
    } catch (const char *msg) {
        cout << "There's something went wrong.\n";
        cout << "Error Message : " << msg << "\n\n";
    }
    try {
        list.insert(list.begin() + 5, 25);
    } catch (const char *msg) {
        cout << "There's something went wrong.\n";
        cout << "Error Message : " << msg << "\n\n";
    }
    try {
        list.insert(list.begin() + 12, 30);
    } catch (const char *msg) {
        cout << "There's something went wrong.\n";
        cout << "Error Message : " << msg << "\n\n";
    }
    cout << list.size() << '\n';
    it = list.begin();
    while (it != list.end()) {
        cout << *it << ' ';
        it++;
    }
    cout << '\n';
    list.clear();
    cout << list2.size() << '\n';
    it = list2.begin();
    while (it != list2.end()) {
        cout << *it << ' ';
        it++;
    }
    cout << '\n';
    return 0;
}
