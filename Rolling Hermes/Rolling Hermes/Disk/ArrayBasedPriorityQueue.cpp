//
//  ArrayBasedPriorityQueue.cpp
//  Rolling Hermes
//
//  Created by Winnie Jeng on 4/15/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.



//#include "ArrayBasedPriorityQueue.hpp"
//
//template <class Data, class Priority>
//arrPriorityQueue<Data, Priority>::arrPriorityQueue(unsigned int _cap): capacity(_cap) {
//    head = new element<Data, Priority>[capacity]();
//    size = 0;
//}
//
//// Destructor
//template <class Data, class Priority>
//arrPriorityQueue<Data, Priority>::~arrPriorityQueue() {
//    clear();
//}
//
//template <class Data, class Priority>
//arrPriorityQueue<Data, Priority>::arrPriorityQueue(const arrPriorityQueue<Data, Priority>& other) {
//    clear();
//    capacity = other.capacity;
//    size = other.size;
//    head = copyOther(other.head, capacity);
//}
//
//template <class Data, class Priority>
//arrPriorityQueue<Data, Priority>& arrPriorityQueue<Data, Priority>::operator= (const arrPriorityQueue<Data, Priority>& other) {
//    if (this == &other)
//        return *this;
//    clear();
//    capacity = other.capacity;
//    size = other.size;
//    head = copyOther(other.head, capacity);
//    return *this;
//}
//
//template <class Data, class Priority>
//void arrPriorityQueue<Data, Priority>::print()const {
//    for (int i = 0; i < size; ++ i)
//        std::cout << "(" << head[i].data << "," << head[i].priority << ") ";
//    std::cout << std::endl;
//}
//
//
//template <class Data, class Priority>
//void arrPriorityQueue<Data, Priority>::clear() {
//    delete [] head;
//    head = nullptr;
//    size = 0;
//    capacity = 5;
//}
//
//template <class Data, class Priority>
//void arrPriorityQueue<Data, Priority>::resize(unsigned int s) {
//    if (s < 2)
//        throw PQ_BAD_SIZE;
//    capacity = s;
//    element<Data, Priority>* temp = copyOther(head, capacity);
//    delete [] head;
//    head = temp;
//}
//
//template <class Data, class Priority>
//void arrPriorityQueue<Data, Priority>::enqueue(Data d, Priority p) {
//    if (full())
//        throw PQ_FULL;
//    element<Data, Priority> e = element<Data, Priority>(d, p);
//    element<Data, Priority>* place = autoInsert(head, p, size++);
//    std::cout << place - head  << " with size: "<< size << "\n";
//    insertBefore(place, e);
//}
//
////
//template <class Data, class Priority>
//Data& arrPriorityQueue<Data, Priority>::deque() {
//    if (empty())
//        throw PQ_EMPTY;
//    //    size--;
//    element<Data, Priority>* walker = head;
//    element<Data, Priority>* end = head + size;
//    Data temp = head -> data;
//
//    while (walker < end) {
//        *walker = *(walker + 1);
//        walker ++;
//    }
//    size--;
//
//    return temp;
//}
//
//template <class Data, class Priority>
//void arrPriorityQueue<Data, Priority>::insertBefore(element<Data, Priority>* beforeThis, const element<Data, Priority>& token) {
//    element<Data, Priority>* walker = head + size + 1;
//    while (walker != beforeThis) {
//        *walker = *(walker - 1);
//        walker --;
//    }
//    *walker = token;
//}
//
//// Rursive function,
//// it can look for the correct position to insert the element.
//template <class Data, class Priority>
//element<Data, Priority>* arrPriorityQueue<Data, Priority>::autoInsert(element<Data, Priority>* head, Priority p, int size) {
//    if (size == 0)
//        return head;
//    if (size == 1)
//        return ((head -> priority) >= p)? (head+1):(head);
//
//    if ((head + size/2) -> priority > p)
//        head = autoInsert(head + size/2 + 1, p, size/2);
//    else if ((head + size/2) -> priority < p)
//        head = autoInsert(head, p, size/2);
//    else {
//        while ((head + size/2) -> priority == p) head ++;
//        return head + size/2;
//    }
//    return head;
//}
//
//template <class Data, class Priority>
//arrPriorityQueue<Data,Priority>& arrPriorityQueue<Data, Priority>::operator>>(Data &d) {
//    d = deque();
//    return *this;
//}
//
//template <class Data, class Priority>
//arrPriorityQueue<Data,Priority>& arrPriorityQueue<Data, Priority>::operator<<(const element<Data, Priority>& e) {
//    enqueue(e.data, e.priority);
//    return *this;
//}
//
//
//template<typename D,typename P>
//std::ostream& operator<<(std::ostream &out, const arrPriorityQueue<D,P> &q) {
//    if (&std::cout != &out)
//        out << "Capacity: " << q.getCapacity() << std::endl;
//
//}
//
//template<typename D,typename P>
//std::istream& operator>>(std::istream &in, arrPriorityQueue<D,P> &q) {
//    std::string junk;
//    q.clear();
//    element<D, P> temp;
//
//    if(&std::cin == &in)
//        in>>junk>>q.capacity;
//
//    else {
//        std::cout<<"Queue capacity: ";
//        in>>q.myCapacity;
//    }
//    while (in >> temp) {    // iostream to an element type need to be updated.
//        q << temp;
//    }
//}
//
//
//// Function
//
//template <class Data, class Priority>
//element<Data, Priority>* copyOther(element<Data, Priority>* other, unsigned int capacity) {
//
//    element<Data, Priority>* temp = new element<Data, Priority>[capacity]();
//    element<Data, Priority>* walker = temp;
//    for (int i = 0; i < capacity; ++ i) {
//        *walker = *other;
//        walker ++;
//        other ++;
//    }
//    return temp;
//}
//
//
