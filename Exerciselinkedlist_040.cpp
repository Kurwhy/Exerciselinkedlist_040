#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode(Node** last, int nilai);
	bool search(int rollno, Node** wahyu, Node** firmansyah);
	bool listEmpty();
	bool delNode(int rollNo);
	void traverse();
};

void CircularLinkedList::addNode(Node** last, int nilai) {
	Node* newNode = new Node;
	newNode->rollNumber = nilai;
	newNode->next = newNode;

	void addNode(Node * *last, int nilai) {
		if (*last == nullptr) {
			listEmpty(last, nilai);
			return;
		}

		Node* newNode = new Node;
		newNode->rollNumber = nilai;
		newNode->next = (*last)->next;
		(*last)->next = newNode;
	}

	void addNode(Node * *last, int data) {
		if (*last == nullptr) {
			listEmpty(last, data);
			return;
		}

		Node* newNode = new Node;
		newNode-> = nilai;
		newNode->next = (*last)->next;
		(*last)->next = newNode;
		*last = newNode;
}

bool CircularLinkedList::search(int rollno, Node** wahyu, Node** firmansyah) {
	*wahyu = LAST->next;
	*firmansyah = LAST->next;
	while (*wahyu != LAST) {
		if (rollno == (*wahyu)->rollNumber) {
			return true;
		}
		*firmansyah = *wahyu;
		*wahyu = (*wahyu)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode(int rollNo) {
	Node* firmansyah, * wahyu;
	firmansyah = wahyu = NULL;
	if (search(rollNo, &firmansyah, &wahyu) == false)
		return false;
	if (wahyu->next != NULL)
		wahyu->next = firmansyah;
	if (firmansyah != NULL)
		firmansyah->next = wahyu->next;
	else
		LAST = wahyu->next;
	delete wahyu;
	return true;

}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
			}
			case '2': {
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;}