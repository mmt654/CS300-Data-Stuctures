//============================================================================
// Name        : Project 2 .cpp
// Author      : Taylor Murphy
// Version     : 1.0
//============================================================================

#include <algorithm>
#include <climits>
#include <iostream>
#include <string> 
#include <fstream>

using namespace std;


const  int DEFAULT_SIZE = 179;

struct courseInfo {
    string course1; 
    string course2;
    string req;
};


class Table {

private:
    struct Node {
        courseInfo info;
        unsigned int key;
        Node *next;

        Node() {
            key = UINT_MAX;
            next = nullptr;
        }

        Node(courseInfo aInfo) : Node() {
            info = aInfo;
        }

        Node(courseInfo aInfo, unsigned int aKey) : Node(aInfo) {
            key = aKey;
        }
    };


    unsigned int tableSize = DEFAULT_SIZE;


public:
  	Table();
    Table(unsigned int size);
    virtual ~Table();
    void PrintAll();
};

Table::Table() {
    nodes.resize(setSize);
}

Table::Table(unsigned int size) {
    this->setSize = size;
    
	nodes.resize(setSize);
}

courseInfo Table::Search(string courseInfo) {
    courseInfo info;
 
    Node* node = &(nodes.at(key));

	if (node != nullptr && node->key != UINT_MAX
			
			&& node->bid.bidId.compare(courseInfo) == 0) {
		
		return node->info;
	}

	if (node == nullptr || node->key == UINT_MAX) {
		
		return info;
	}

	while (node != nullptr) {
		
		if (node->key != UINT_MAX && node->info.courseInfo.compare(courseInfo) == 0) {
			
			return node->info;
		
		}
		
		node = node->nextNodePtr;
		
	}

    return info;
}

int main() {

    Table* courseTable;

    courseInfo info;
    courseTable = new Table();
    
    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Data Structure" << endl;
        cout << "  2. Print Course List" << endl;
        cout << "  3. Print Course" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:

            loadBids("courseFile", Table);

            break;

        case 2:
            Table->PrintAll();
            break;

        case 3:
			cout << Course << endl;
            break;
    }

    cout << "Thank you for using the course planner." << endl;

    return 0;
}
