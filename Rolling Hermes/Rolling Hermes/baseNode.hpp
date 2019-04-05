//
//  baseNode.hpp
//  Rolling Hermes
//
//  Created by Jack Zhao on 4/4/19.
//  Copyright © 2019 Jack Zhao. All rights reserved.
//

#ifndef baseNode_hpp
#define baseNode_hpp

class baseNode {
private:
    void* data;
public:
    baseNode(void* d = nullptr);
    ~baseNode();
    baseNode(const baseNode& other);
    baseNode& operator= (const baseNode& other);
    
    virtual void copyContent(void* otherData) = 0;
    
    // Accessor
    const void* viewData()const {return data;}
    // Mutator
    void changeData(void* newData) {data = newData;}
};

baseNode::baseNode(void* d):data(d) {}

baseNode::~baseNode() {
    data = nullptr;
}

baseNode::baseNode(const baseNode& other) {
    copyContent(other.data);
}

baseNode& baseNode::operator= (const baseNode& other) {
    if (this == &other)
        return *this;
    copyContent(other.data);
    return *this;
}


#endif /* baseNode_hpp */
