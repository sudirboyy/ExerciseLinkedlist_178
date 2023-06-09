#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList { //Change initial current with your first name. muhammad
							// Change initial previous with your last name. sudirman
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** sudirman, Node** muhammad);
	bool listEmpty();
	bool delNode();
	void traverse();
};
void CircularLinkedList::addNode() { //write your answer here
	int number;
	string nama;
	Node* nodeBaru = new Node(); // 1

	cout << "\nEntar the roll number : ";
	cin >> number;
	cout << "\nEnter the name : ";
	cin >> nama;
	Node* newNode = new Node();             //Step 1
	newNode->rollNumber = number;                   //Step 2
	newNode->rollNumber = nama;

}

bool CircularLinkedList::search(int rollno, Node** sudirman, Node** muhammad) {
	*sudirman = LAST->next;
	*muhammad = LAST->next;
	while (*muhammad != LAST) {
		if (rollno == (*muhammad)->rollNumber) {
			return true;
		}
		*sudirman = *muhammad;
		*muhammad = (*muhammad)->next;
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
bool CircularLinkedList::delNode() { //write your answer here
	Node* sudirman, * muhammad;
	sudirman = muhammad = NULL;
	if (search(rollNo, &sudirman, &muhammad) == false)
	{
		return false;
	}
	if (muhammad->next != NULL)
	{
		muhammad->next->prev = sudirman;        
	}
	if (sudirman != NULL)
	{
		sudirman->next = muhammad->next;         
	}
	else
		LAST = muhammad->next;

	delete muhammad;                             
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
			cout << "\nEnter your choice (1-4): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				obj.delNode();
				break;
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
	return 0;
}