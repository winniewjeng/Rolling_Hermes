////
////  Node.hpp
////  Rolling Hermes
////
////  Created by Jack Zhao on 4/4/19.
////  Copyright © 2019 Jack Zhao. All rights reserved.
////
//
//#ifndef Node_hpp
//#define Node_hpp
//
//#include "baseNode.hpp"
//
//template <class T>
//class node: public baseNode {
//private:
//    node* next;
//public:
//    node(node* n = nullptr, const T* data = T());
//    ~node();
//    node(const node& other);
//    node& operator =(const node& other);
//
//    void deleteNode();
//    void copyContent(void* otherData);
//    void deleteData();
//};
//
//template <class T>
//node<T>::node(node<T>* n, const T* data):next(n), baseNode(data) {}
//
//template <class T>
//node<T>::~node() {
//    deleteNode();
//}
//
//template <class T>
//node<T>::node(const node& other) {
//    next = other.next;
//    copyContent(other.viewData());
//}
//
//template <class T>
//node<T>& node<T>::operator =(const node& other) {
//    if (this == &other)
//        return *this;
//    next = other.next;
//    copyContent(other.viewData());
//    return *this;
//}
//
//template <class T>
//void node<T>::deleteNode() {
//    if (next)
//        delete next;
//    if (viewData())
//        deleteData();
//
//    next = nullptr;
//    changeData(nullptr);
//}
//
//template <class T>
//void node<T>::copyContent(void* otherData) {
//    T* temp = new T(*(static_cast<T*>(otherData)));
//    changeData(temp);
//}
//
//template <class T>
//void node<T>::deleteData() {
//    delete static_cast<T*>(viewData());
//}
//
//#endif /* Node_hpp */
