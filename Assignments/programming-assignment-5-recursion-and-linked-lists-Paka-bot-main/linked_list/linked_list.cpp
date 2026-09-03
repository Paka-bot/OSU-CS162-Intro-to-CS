#include "linked_list.hpp"

#include <iostream>

node* linked_list::merge(node* a, node* b, bool ascending) {
	if (!a) return b;
	if (!b) return a;

	if ((ascending && a->val <= b->val) || (!ascending && a->val >= b->val)) {
		a->next = merge(a->next, b, ascending);
		return a;
	} else {
		b->next = merge(a, b->next, ascending);
		return b;
	}
}

node* linked_list::merge_sort_ascending(node* head) {
    if (!head || !head->next) {
        return head;
    }

    node* slow = head;
    node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    node* second_half = slow->next;
    slow->next = nullptr;

    node* left = merge_sort_ascending(head);
    node* right = merge_sort_ascending(second_half);

    return merge(left, right, true);
}

node* linked_list::merge_sort_descending(node* head) {
    if (!head || !head->next) {
        return head;
    }

    node* slow = head;
    node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    node* second_half = slow->next;
    slow->next = nullptr;

    node* left = merge_sort_descending(head);
    node* right = merge_sort_descending(second_half);

    return merge(left, right, false);
}

linked_list::linked_list(const linked_list& other) {
	// TODO Complete this function (feel free to give it a member initializer
	// list)

	node* current = other.head;
	while (current) {
		push_back(current->val);
		current = current->next;
	}
}

void linked_list::operator=(const linked_list& other) {
	// TODO Complete this function

	if (this == &other) return;
	clear();
	node* current = other.head;
	while (current) {
		push_back(current->val);
		current = current->next;
	}
}

linked_list::~linked_list() {
	// TODO Complete this function.

	clear();
}

int linked_list::get_length() {
	// TODO Complete this function.
	// TODO Remove the below return statement. It's a placeholder just to
	// get the starter code to compile and run.

	return length;
}

void linked_list::print() {
	// TODO Complete this function.

	node* current = head;
	while (current) {
		std::cout << current->val << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

void linked_list::clear() {
	// TODO Complete this function.

	while (head) {
		pop_front();
	}
}

void linked_list::push_front(int value) {
	// TODO Complete this function.

	node* new_node = new node{value, head};
	head = new_node;
	++length;
}

void linked_list::push_back(int value) {
	// TODO Complete this function.

	node* new_node = new node{value, nullptr};
	if (!head) {
		head = new_node;
	} else {
		node* current = head;
		while (current->next) {
			current = current->next;
		}
		current->next = new_node;
	}
	++length;
}

void linked_list::insert(int value, int index) {
	// TODO Complete this function.

	if (index < 0 || index > length) return;
	if (index == 0) {
		push_front(value);
	} else if (index == length) {
		push_back(value);
	} else {
		node* current = head;
		for (int i = 0; i < index - 1; ++i) {
			current = current->next;
		}
		node* new_node = new node{value, current->next};
		current->next = new_node;
		++length;
	}
}

void linked_list::pop_front() {
	// TODO Complete this function.

	if(!head) return;
	node* temp = head;
	head = head->next;
	delete temp;
	--length;
}

void linked_list::pop_back() {
	// TODO Complete this function.

	if (!head) return;
	if (!head->next) {
		delete head;
		head = nullptr;
	} else {
		node* current = head;
		while (current->next->next) {
			current = current->next;
		}
		delete current->next;
		current->next = nullptr;
	}
	--length;
}

void linked_list::remove(int index) {
	// TODO Complete this function.

	if (index < 0 || index >= length) return;
	if (index == 0) {
		pop_front();
	} else {
		node* current = head;
		for (int i = 0; i < index - 1; ++i) {
			current = current->next;
		}
		node* temp = current->next;
		current->next = current->next->next;
		delete temp;
		--length;
	}
}

void linked_list::sort_ascending() {
	// TODO Complete this function.

	head = merge_sort_ascending(head);
}

void linked_list::sort_descending() {
	// TODO Complete this function.

	head = merge_sort_descending(head);
}
