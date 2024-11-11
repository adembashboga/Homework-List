#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class ForwardList {
private:
    Node* head;
public:
    ForwardList() : head(nullptr) {}
    ForwardList(const ForwardList& other) 
    {
        if (!other.head) 
        {
            head = nullptr;
            return;
        }
        head = new Node(other.head->data);
        Node* currentOriginal = other.head->next;
        Node* currentCopy = head;

        while (currentOriginal) 
        {
            currentCopy->next = new Node(currentOriginal->data);
            currentCopy = currentCopy->next;
            currentOriginal = currentOriginal->next;
        }
    }

    void append(int val) 
    {
        if (!head) 
        {
            head = new Node(val);
            return;
        }

        Node* temp = head;
        while (temp->next) 
        {
            temp = temp->next;
        }
        temp->next = new Node(val);
    }

    void printList() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }
    ~ForwardList() 
    {
        Node* current = head;
        while (current) 
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    ForwardList list;
    list.append(1);
    list.append(2);
    list.append(3);
    std::cout << "Оригинальнный список - ";
    list.printList();
    ForwardList copiedList = list;
    std::cout << "Скопированный список - ";
    copiedList.printList();
}