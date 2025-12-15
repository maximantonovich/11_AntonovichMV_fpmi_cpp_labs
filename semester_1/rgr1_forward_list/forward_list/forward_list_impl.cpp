#include "forward_list_impl.h"
ForwardList::ForwardList() {
}

ForwardList::ForwardList(const ForwardList& rhs) {
    if (rhs.head != nullptr) {
        head = new Node(rhs.head->value_);
        Node* current = head;
        Node* rhs_current = rhs.head->next_;

        while (rhs_current != nullptr) {
            current->next_ = new Node(rhs_current->value_);
            current = current->next_;
            rhs_current = rhs_current->next_;
        }
    }
}

ForwardList::ForwardList(size_t count, int32_t value) {

    for (size_t i = 0; i < count; i++) {
        PushFront(value);
    }
}

ForwardList::ForwardList(std::initializer_list<int32_t> init) {
    head = nullptr;
    for (std::initializer_list<int32_t>::iterator i = init.end(); i != init.begin();) {
        i--;
        PushFront(*i);
    }
}

void ForwardList::PushFront(int32_t value) {
    Node* new_el = new Node(value);
    new_el->next_ = head;
    head = new_el;
}

ForwardList& ForwardList::operator=(const ForwardList& rhs) {
    if (this == &rhs) {
        return *this;
    }
    ForwardList temp(rhs);
    std::swap(head, temp.head);
    return *this;
}

ForwardList::~ForwardList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next_;
        delete temp;
    }
}
