//
// Created by daniel on 25/08/23.
//

#ifndef INTERVIEWPREP_LINKEDLIST_H
#define INTERVIEWPREP_LINKEDLIST_H

#include <initializer_list>
#include <vector>

namespace itp{

    template <typename data_type>
    struct Node{
        data_type data;
        Node<data_type>* next;

        explicit Node(data_type data_)
            : data {data_}, next {nullptr}
        {

        }

    };

    template <typename data_type>
    class LinkedList;

    template <typename data_type>
    void mergeSortedLists(
            LinkedList<data_type>& list1,
            LinkedList<data_type>& list2);



    template <typename data_type>
    class LinkedList {
    private:
        Node<data_type>* m_head {nullptr};
        Node<data_type>* m_tail {nullptr};
        std::size_t m_length {0};

    public:

        LinkedList() = default;

        LinkedList(std::initializer_list<data_type> listData) {
            for (auto data: listData){
                pushBack(data);
            }
        }

        [[nodiscard]] std::size_t getLength() const { return m_length; }

        std::vector<data_type> toVector() {
            std::vector<data_type> result(getLength());
            Node<data_type>* current {m_head};

            std::size_t index {0};
            while (current != nullptr){
                result[index] = current->data;
                current = current->next;
                ++index;
            }
            return result;
        }

        void pushBack(data_type data){
            // Add a node to the end of the list
            if (m_head == nullptr){
                m_head = new Node<data_type> {data};
                m_tail = m_head;
            } else {
                m_tail->next = new Node<data_type> {data};
                m_tail = m_tail->next; // new node becomes the tail
            }
            ++m_length;
        }

        void concatenate(LinkedList<data_type>& other){
            // Append a new list at the end of this list
            // other will point to the new concatenated list
            m_tail->next = other.m_head;
            m_tail = other.m_tail;
            other.m_head = m_head;

            m_length += other.m_length;
            other.m_length = m_length;
        }

        friend void mergeSortedLists<data_type>(
                LinkedList<data_type>& list1,
                LinkedList<data_type>& list2);

    };

    template <typename data_type>
    Node<data_type>* findIntersection(Node<data_type>* head1,
                                      Node<data_type>* head2){
        Node<data_type>* prev;
        while (head1 != nullptr && head1->data <= head2->data){
            prev = head1;
            head1 = head1->next;
        }
        prev->next = head2;
        return head1;
    }

    template <typename data_type>
    void mergeSortedLists(
            LinkedList<data_type>& list1,
            LinkedList<data_type>& list2) {
        // Merge two sorted lists. The resulting list is sorted too
        // list1 and list2 will point to the new list

        // Edge case: all elements are smaller in one list. Concatenate in O(1) time
        if (list1.m_tail->data <= list2.m_head->data){
            list1.concatenate(list2);
            return;
        }
        if (list2.m_tail->data < list1.m_head->data){
            list2.concatenate(list1);
            return;
        }

        Node<data_type>* head1 {list1.m_head};
        Node<data_type>* head2 {list2.m_head};

        while (head1 != nullptr && head2 != nullptr) {
            if (head1->data <= head2->data){
                head1 = findIntersection(head1, head2);
            }
            else
                head2 = findIntersection(head2, head1);
        }

        // Update head, tail and size
        if (list1.m_head->data <= list2.m_head->data)
            list2.m_head = list1.m_head;
        else
            list1.m_head = list2.m_head;

        if (list1.m_tail->data > list2.m_tail->data)
            list2.m_tail = list1.m_tail;
        else
            list1.m_tail = list2.m_tail;

        list1.m_length += list2.m_length;
        list2.m_length = list1.m_length;
    }

}



#endif //INTERVIEWPREP_LINKEDLIST_H
