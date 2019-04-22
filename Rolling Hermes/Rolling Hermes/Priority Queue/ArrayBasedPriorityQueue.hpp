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
    // Function: Auto insert
    // Description: This function uses binary search to find the correct position
    //                where the new data should be inserted. Recursively called.
    // Returns the pointer where should be inserted before.
    
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
<<<<<<< HEAD
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
=======
    
    
    unsigned int getCapacity() const {return capacity;}
    // Function: get capacity
    // Description: Accessor
    // Return type: Unsigned int
    
    
    Data& peek() {return head -> data;}
    // Function: Peek
    // Description: Look at the first item's data without popping it.
    // Return type: Data
    
>>>>>>> 49a6de37d29fa9e2ce0572a260ef63eac41a3f05
    element<Data, Priority>* at(const unsigned int i) {return (head + i);}
    // Function: at
    // Description: Look at the i'th item's data without popping it. (works like [])
    // Return type: element<Data, Priority>*
    
<<<<<<< HEAD
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
=======
    Priority& peekPriority()const {return head -> priority;}
    // Function: peek
    // Description: Look at the first item's priority
    // Return type: Priority
    
    void print() const;
    // Function: print
    // Description: Print out every item in the queue. (item requires their own ostream operation)
    
    // Mutators
    void clear();
    // Function: clear
    // Description: clear the entire queue.
    
    void resize(unsigned int s);
    // Function: resize
    // Description: copy the entire queue into a new queue with new size s.
    // Return type: void
    // Paramaters: unsigned int s
    
    void enqueue(Data d, Priority p);
    // Function: enqueue
    // Description: same as push, push the item in the queue at it's right position
    // Paramaters: Data d and Priority p.
    
    Data deque();
    // Function: deque
    // Description: same as pop(), delete the first item and return its Data
    // Return type: Data
    
    void insertBefore(element<Data, Priority>* beforeThis, const element<Data, Priority>& token);
    // Function: insertBefore
    // Description: Insert the item before given pointer.
    // Paramaters: element<Data, Priority>* key pointer and a element<Data, Priority>& token.
    
>>>>>>> 49a6de37d29fa9e2ce0572a260ef63eac41a3f05
    
    // Insertion and extraction operator.
    // Not tested, not being used in this project.
    arrPriorityQueue<Data,Priority>& operator>>(Data &d);

    arrPriorityQueue<Data,Priority>& operator<<(const element<Data, Priority>& e);
<<<<<<< HEAD
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
=======

>>>>>>> 49a6de37d29fa9e2ce0572a260ef63eac41a3f05
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
    // Return the head if the queue is empty
    if (size == 0)
        return head;
    // When there's only one item in the queue
    //  compare the priority, if p is lower or same, put in the back.
    if (size == 1)
        return ((head -> priority) >= p)? (head+1):(head);
    
    // When the middle value is bigger, move p to right (smaller half of the array)
    if ((head + size/2) -> priority > p)
        head = autoInsert(head + size/2 + 1, p, size/2);
    
    // When the middle value is smaller, move p to left (larger half of the array)
    else if ((head + size/2) -> priority < p)
        head = autoInsert(head, p, size/2);
    // The middle value is the same as p
    else {
        // incr head until the item in the array is not equal to p
        //  So that p can be placed at the back of items with the same priority
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
