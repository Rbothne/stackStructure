    template<class ItemType>
    LinkedStack<ItemType>::LinkedStack(){
        top=nullptr;
    }
    template<class ItemType>
    bool LinkedStack<ItemType>::isEmpty() const{
        return top==nullptr;
    }
    template<class ItemType>
    bool LinkedStack<ItemType>::push(const ItemType& newEntry){
        Node<ItemType>* temp; 
        temp = new Node<ItemType>();
        temp->setItem(newEntry);
        temp->setNext(top);
        top = temp;
        return true;
    }
    template<class ItemType>
    bool LinkedStack<ItemType>::pop(){
        Node<ItemType>* temp; 
        if (top ==nullptr){
            cout << "this is an empty stack" << endl;
            return false;
        }
        else{
            temp = top;
            top = top->getNext();
            temp->setNext(nullptr);
            free(temp);
            return true;
        }
    }
    template<class ItemType>
    ItemType LinkedStack<ItemType>::peek() const{
        if(!isEmpty()){
            return top->getItem();
        }
        else return 0;
    }
    template<class ItemType>
    LinkedStack<ItemType>::~LinkedStack(){}