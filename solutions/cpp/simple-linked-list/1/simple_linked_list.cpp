#include "simple_linked_list.h"
#include <stdexcept>
namespace simple_linked_list {

    std::size_t List::size() const {
        return current_size; 
    }
    
    void List::push(int entry) {
        auto element = new List::Element(entry);
        element->next = head; 
        head = element;
        ++current_size;
    }

    int List::pop() {
        auto element = head->next;
        auto val = head->data;
        delete head;
        head = element;
        --current_size;
        return val;
    }

    void List::reverse() {
        Element* previous(0);
        Element* current(0);
        Element* next(0);
        current = head;
        while (current != nullptr) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }

    List::~List() {
        auto element = head;
        while (element != nullptr && element->next != nullptr){
            element = nullptr;
        }
    }

}  // namespace simple_linked_list
