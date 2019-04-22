//
//  ArrayBasedPriorityQueue.hpp
//  Rolling Hermes
//
//  Created by Jack Zhao on 4/8/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#ifndef ArrayBasedPriorityQueue_hpp
#define ArrayBasedPriorityQueue_hpp

enum PRIORITY_QUEUE_ERRORS{PQ_EMPTY, PQ_FULL, PQ_BAD_SIZE};

template <class Data, class Priority>
struct element {
    Data data;
    Priority priority;
    element(Data d = Data(), Priority p = Priority()): data(d), priority(p){}
};

template <class Data, class Priority>
element<Data, Priority>* copyOther(element<Data, Priority>* other, unsigned int capacity);



template <class Data, class Priority>
class arrPriorityQueue {
private:
    element<Data, Priority>* autoInsert(element<Data, Priority>* head, Priority p, int size);
    
    element<Data, Priority>* head;
    unsigned int size;
    unsigned int capacity;
    
public:
    arrPriorityQueue(unsigned int _cap = 5);
    ~arrPriorityQueue();
    arrPriorityQueue(const arrPriorityQueue<Data, Priority>& other);
    arrPriorityQueue<Data, Priority>& operator= (const arrPriorityQueue<Data, Priority>& other);
    
    // Booleans
    
    bool full() const {return size == capacity;};
    // Function: full
    // Description: checks if the array is full.
    // Return type: boolean
    // Paramaters: none
    
    const bool empty() const {return size == 0;};
    // Function: empty
    // Description: checks if the array is empty.
    // Return type: boolean
    // Paramaters: none
    
    // Accessors
    unsigned int getSize() const {return size;};
    // Function: get array size
    // Description: accessor, returns the private member size
    // Return type: unsigned int
    // Paramaters: none
    
    unsigned int getCapacity() const {return capacity;}
    // Function: gets array capacity
    // Description: accessor, returns the private member capacity
    // Return type: unsigned int
    // Paramaters: none
    
    Data& peek() {return head -> data;}
    // Function: peek first data of the array
    // Description: accessor, return the private member head's data
    // Return type: Data
    // Paramaters: none
    element<Data, Priority>* at(const unsigned int i) {return (head + i);}
    
    Priority& peekPriority() const {return head -> priority;}
    // Function: peek first priority of the queue
    // Description: accessor, return the private member head's priority
    // Return type: integer
    // Paramaters: none
    
    void print() const;
    // Function: print the queue
    // Description: prints each element's Data and Priority in the array
    // Return type: void
    // Paramaters: none
    
    // Mutators
    void clear();
    // Function: clear the queue
    // Description: clears all elements in the queue
    // Return type: void
    // Paramaters: none
    
    void resize(unsigned int s);
    // Function: resize the array
    // Description: enlarges or shrinks the array capacity
    // Return type: void
    // Paramaters: unsigned int
    
    void enqueue(Data d, Priority p);
    // Function: enqueue
    // Description: adds an element with data and priority to the queue
    // Return type: void
    // Paramaters: Data, Priority
    
    Data deque();
    // Function: deque
    // Description: removes the first element in the queue
    // Return type: Data
    // Paramaters: None
    
    void insertBefore(element<Data, Priority>* beforeThis, const element<Data, Priority>& token);
    // Function: insert before
    // Description: insert element (token) in queue at a marked position (beforeThis)
    // Return type: void
    // Paramaters: element<Data, Priority>*, const element<Data, Priority>&
    
    arrPriorityQueue<Data,Priority>& operator>>(Data& d);
    // Function: overloaded insertion operator
    // Description: deque the array with Data
    // Return type: arrPriorityQueue<Data,Priority>&
    // Paramaters: Data&
    
    arrPriorityQueue<Data,Priority>& operator<<(const element<Data, Priority>& e);
    // Function: overloaded extraction operator
    // Description: enqueue the array with element
    // Return type: arrPriorityQueue<Data,Priority>&
    // Paramaters: element<Data, Priority>&
    
    
    // iostream
    template<typename D,typename P>
    friend
    std::ostream& operator<<(std::ostream &out, const arrPriorityQueue<D,P> &q);
    
    template<typename D,typename P>
    friend
    std::istream& operator>>(std::istream &in, arrPriorityQueue<D,P> &q);
//
};

template <class Data, class Priority>
arrPriorityQueue<Data, Priority>::arrPriorityQueue(unsigned int _cap): capacity(_cap) {
    head = new element<Data, Priority>[capacity]();
    size = 0;
}

// Destructor
template <class Data, class Priority>
arrPriorityQueue<Data, Priority>::~arrPriorityQueue() {
    clear();
}

template <class Data, class Priority>
arrPriorityQueue<Data, Priority>::arrPriorityQueue(const arrPriorityQueue<Data, Priority>& other) {
    clear();
    capacity = other.capacity;
    size = other.size;
    head = copyOther(other.head, capacity);
}

template <class Data, class Priority>
arrPriorityQueue<Data, Priority>& arrPriorityQueue<Data, Priority>::operator= (const arrPriorityQueue<Data, Priority>& other) {
    if (this == &other)
        return *this;
    clear();
    capacity = other.capacity;
    size = other.size;
    head = copyOther(other.head, capacity);
    return *this;
}

template <class Data, class Priority>
void arrPriorityQueue<Data, Priority>::print()const {
    for (int i = 0; i < size; ++ i)
        std::cout << "(" << head[i].data << "," << head[i].priority << ") ";
    std::cout << std::endl;
}


template <class Data, class Priority>
void arrPriorityQueue<Data, Priority>::clear() {
//    if (head != nullptr)
//        delete [] head;
    head = nullptr;
    size = 0;
    capacity = 5;
}

template <class Data, class Priority>
void arrPriorityQueue<Data, Priority>::resize(unsigned int s) {
    if (s < 2)
        throw PQ_BAD_SIZE;
    capacity = s;
    element<Data, Priority>* temp = copyOther(head, capacity);
    delete [] head;
    head = temp;
}

template <class Data, class Priority>
void arrPriorityQueue<Data, Priority>::enqueue(Data d, Priority p) {
    if (full())
        throw PQ_FULL;
    element<Data, Priority> e = element<Data, Priority>(d, p);
    element<Data, Priority>* place = autoInsert(head, p, size++);
    //    std::cout << " p is " << p  << "  data is " << *d <<"\n";
//    std::cout << "place down at " << place - head  << " with size: "<< size << "\n";
    insertBefore(place, e);
}

//
template <class Data, class Priority>
Data arrPriorityQueue<Data, Priority>::deque() {
    if (empty())
        throw PQ_EMPTY;
//    size--;
    element<Data, Priority>* walker = head;
    element<Data, Priority>* end = head + size;
    Data temp = head -> data;
    while (walker < end) {
        *walker = *(walker + 1);
        walker ++;
    }
    size--;
    
    return temp;
}

template <class Data, class Priority>
void arrPriorityQueue<Data, Priority>::insertBefore(element<Data, Priority>* beforeThis, const element<Data, Priority>& token) {
    element<Data, Priority>* walker = head + size + 1;
    while (walker != beforeThis) {
        *walker = *(walker - 1);
        walker --;
    }
    *walker = token;
}

// Rursive function,
// it can look for the correct position to insert the element.
template <class Data, class Priority>
element<Data, Priority>* arrPriorityQueue<Data, Priority>::autoInsert(element<Data, Priority>* head, Priority p, int size) {
    if (size == 0)
        return head;
    if (size == 1)
        return ((head -> priority) >= p)? (head+1):(head);
    
    if ((head + size/2) -> priority > p)
        head = autoInsert(head + size/2 + 1, p, size/2);
    else if ((head + size/2) -> priority < p)
        head = autoInsert(head, p, size/2);
    else {
        while ((head + size/2) -> priority == p) head ++;
        return head + size/2;
    }
    return head;
}

template <class Data, class Priority>
arrPriorityQueue<Data,Priority>& arrPriorityQueue<Data, Priority>::operator>>(Data &d) {
    d = deque();
    return *this;
}

template <class Data, class Priority>
arrPriorityQueue<Data,Priority>& arrPriorityQueue<Data, Priority>::operator<<(const element<Data, Priority>& e) {
    enqueue(e.data, e.priority);
    return *this;
}


template<typename D,typename P>
std::ostream& operator<<(std::ostream &out, const arrPriorityQueue<D,P> &q) {
    if (&std::cout != &out)
        out << "Capacity: " << q.getCapacity() << std::endl;
    
}

template<typename D,typename P>
std::istream& operator>>(std::istream &in, arrPriorityQueue<D,P> &q) {
    std::string junk;
    q.clear();
    element<D, P> temp;
    
    if(&std::cin == &in)
        in>>junk>>q.capacity;
    
    else {
        std::cout<<"Queue capacity: ";
        in>>q.myCapacity;
    }
    while (in >> temp) {    // iostream to an element type need to be updated.
        q << temp;
    }
}


// Function

template <class Data, class Priority>
element<Data, Priority>* copyOther(element<Data, Priority>* other, unsigned int capacity) {
    
    element<Data, Priority>* temp = new element<Data, Priority>[capacity]();
    element<Data, Priority>* walker = temp;
    for (int i = 0; i < capacity; ++ i) {
        *walker = *other;
        walker ++;
        other ++;
    }
    return temp;
}



#endif /* ArrayBasedPriorityQueue_hpp */
