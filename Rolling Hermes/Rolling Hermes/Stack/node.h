#ifndef NODE_H
#define NODE_H


class node
{
    public:
        node();
        node(void *ptr); //A void pointer is a pointer
                         //that can point to anything
                         //BUT you cannot de-reference it!!
        virtual ~node() = 0;
        node(const node &other);
        node& operator=(const node&other);

        void* access() const;
        virtual void modifyData(void *d) = 0;
        // An & on a return type will allow this function to be on
                         //EITHER the lhs or rhs of an assignment statement!!!
        node* getNext();
        void setNext(node *ptr);

    protected:
        virtual void makeCopy(const node &other) = 0;
        void*& edit();
    
    private:
        void *dataPtr;
        node *next;

        void copy(const node &other);


};

#endif // NODE_H
