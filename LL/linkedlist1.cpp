#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        
        // Constructor
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

// Insert at the head of the list
void insertatHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

// Insert at the tail of the list
void insertatTail(Node* &tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

// Insert at a specific position in the list
void InsertAtPosition(Node* &tail, Node* &head, int position, int data) {
    // Insert at the head if position is 1
    if (position == 1) {
        insertatHead(head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    // Traverse to the node before the insertion position
    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    // If inserting at the end, update the tail
    if (temp->next == NULL) {
        insertatTail(tail, data);
    } else {
        Node* NodeToInsert = new Node(data);
        NodeToInsert->next = temp->next;
        temp->next = NodeToInsert;
    }
}

void deleteHeadNode(int position , Node* &head , Node* &tail){
	if (position == 1){
		Node* temp = head;
		head = head -> next;
		temp -> next = NULL;
		delete temp;
		
		if (head == NULL){
			tail = NULL;
		}
	}
	else{
	Node* curr = head;
	Node* prev = NULL;
	
	int cnt = 1;
	while(cnt < position){
		prev = curr;
		curr = curr -> next;
		cnt++;
	}
	
	if(curr -> next == NULL){
		tail = prev;
	}
	
	prev -> next = curr -> next;
	curr -> next = NULL;
	delete curr;
}
}

void searchNode(Node* &head , int data ){
	Node* curr = head;
	while(curr != NULL){
		if(curr -> data == data){
		cout<<"Element "<<data<<" found "<<endl;
		return;
	}
		curr = curr -> next;
	}
	cout<<"Element"<<data<<" not found "<<endl;
}

// Print the linked list
void printLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a new node
    Node* node1 = new Node(10);	

    // Initialize head and tail to the first node
    Node* head = node1;
    Node* tail = node1;

    // Print initial list
    printLL(head);

    // Insert at tail and print the list
    insertatTail(tail, 20);
    printLL(head);

    insertatTail(tail, 21);
    printLL(head);

    // Insert at position 3 and print the list
    InsertAtPosition(tail, head, 4, 22);
    printLL(head);

    // Display the head and tail values
    cout << "Head is " << head->data << endl;
    cout << "Tail is " << tail->data << endl;
    
//    deleteHeadNode(4, head , tail);
//    printLL(head);
//    
//    cout << "Head is " << head->data << endl;
//    cout << "Tail is " << tail->data << endl;
    
    searchNode(head, 20 );

    return 0;
}

