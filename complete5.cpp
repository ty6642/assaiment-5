//Name: modather sydeq
 
 

#include <iostream>
/*iostream stands for standard input-output stream this header file
 *  contains definitions to objects like cin, cout, cerr etc ...*/
using namespace std;
struct Node {
	int data;
	struct Node *next;
};
struct Node* top = NULL;
void push(int val) {
	struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
	newnode->data = val;
	newnode->next = top;
	top = newnode;
}
/*A node is a struct with at least a data field and a reference to a node
 *of the same type*/
struct node {
	int info;
	struct node *next;
	}*start;
	class list {
//we do the class and add public member to all functions available
		public:
			node* create_node(int);
			void insert_begin();
			void insert_pos();
			void insert_last(); 
			void delete_pos();
			void search();
			void displayo();
			list() {
				start = NULL;
			}
	};
//these are pointers made from node and it's for doing various functions
//like add and delete and search and so on
node *list::create_node(int value)
		{
		struct node *temp;
		temp = new(struct node);
		if (temp == NULL){
			cout<<"\nError"<<endl;
			exit(1);
		}
		else {
			temp->info = value;
			temp->next = NULL;     
			return temp;
		}
		}
//this function is for linked list and it is to add
void list::insert_begin()
		{
			int value;
			cout<<"\nEnter the value to be add: ";
			cin>>value;
			struct node *temp, *p;
			temp = create_node(value);
			if (start == NULL) {
				start = temp;
				start->next = NULL;
			}
			else
			{
				p = start;
				start = temp;
				start->next = p;
			}
			cout<<"\nElement Inserted at beginning"<<endl;
		}
//this is to add last
void list::insert_last()
		{
			int value;
			cout<<"\nEnter the value to be inserted: ";
			cin>>value;
			struct node *temp, *s;
			temp = create_node(value);
			s = start;
			while (s->next != NULL)
			{
				s = s->next;
			}
			temp->next = NULL;
			s->next = temp;
			cout << "\nElement Inserted at end" << endl;  
		}
//this is to add middle of something
void list::insert_pos()
		{
			int value, pos, counter = 0; 
			cout << "\nEnter the value to be inserted: ";
			cin >> value;
			struct node *temp, *s, *ptr;
			temp = create_node(value);
			cout << "\nEnter the postion: ";
			cin >> pos;
			int i;
			s = start;
			while (s != NULL)
			{
				s = s->next;
				counter++;
			}
			if (pos == 1) {
				if (start == NULL) {
					start = temp;
					start->next = NULL;
				}
				else {
					ptr = start;
					start = temp;
					start->next = ptr;
				}
			}
			else if (pos > 1  && pos <= counter) {
				s = start;
				for (i = 1; i < pos; i++) {
					ptr = s;
					s = s->next;
				}
				ptr->next = temp;
				temp->next = s;
			}
			else {
				cout<<"\nPositon not found"<<endl;
			}
		}
void list::delete_pos() {
			int pos, i, counter = 0;
			if (start == NULL) {
				cout<<"\nList is empty"<<endl;
				return;
			}
			cout<<"\nEnter the position: ";
			cin>>pos;
			struct node *s, *ptr;
			s = start;
			if (pos == 1) {
				start = s->next;
			}
			else {
				while (s != NULL) {
					s = s->next;
					counter++;  
				}
				if (pos > 0 && pos <= counter) {
					s = start;
					for (i = 1;i < pos;i++) {
						ptr = s;
						s = s->next;
					}
					ptr->next = s->next;
				}
				else {
					cout<<"\nPosition not found"<<endl;
				}
				free(s);
				cout<<"\nElement deleted"<<endl;
			}
		}
//this is to search
void list::search() {
	int value, pos = 0;
	bool flag = false;
	if (start == NULL) {
		cout<<"\nList is empty"<<endl;
		return;
	}
	cout<<"\nEnter the value: ";
	cin>>value;
	struct node *s;
	s = start;
	while (s != NULL) {
		pos++;
		if (s->info == value) {
			flag = true;
			cout<<"\nElement"<<value<<"is found at position "<<pos<<endl;
		}
		s = s->next;
	}
	if (!flag)
	cout<<"\nElement"<<value<<"not found"<<endl;
}
void list::displayo() {
	struct node *temp;
	if (start == NULL) {
		cout<<"\nThe list is empty"<<endl;
		return;
	}
	temp = start;
		cout << "\nElements: " << endl;
		while (temp != NULL) {
			cout << temp->info << "  >>>  ";
			temp = temp->next;
		}
	cout<<"nothing"<<endl;
}
void pop() {
	if (top == NULL){
		cout << "\nStack underflow" << endl;
	}
	else {
		cout << "\nThe popped element: " << top->data << endl;
		top = top->next;
	}
}
void display() {
	struct Node* ptr;
	if(top == NULL)
	cout << "\nStack is empty";
	else {
		ptr = top;
		cout << "Stack elements: ";
		while (ptr != NULL) {
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
	}
	cout << endl;
}
int queue[50], n = 50, front = - 1, rear = - 1;
void Insert() {
	int val;
	if (rear == n - 1)
	cout << "\nQueu overflow" << endl;
	else {
		if (front == - 1)
		front = 0;
		cout << "\nInsert the element: ";
		cin >> val;
		rear++;
		queue[rear] = val;
	}
}
void Delete() {
	if (front == - 1 || front > rear) {
		cout << "\nQueue underflow" << endl;
		return ;
	} else {
		cout << "\nElement deleted from queue is: " << queue[front] << endl;
		front++;;
	}
}
void Display() {
	if (front == - 1)
	cout << "\nQueue is empty" << endl;
	else {
	cout << "\nQueue elements are: ";
	for (int i = front; i <= rear; i++)
	cout << queue[i]<<" ";
		cout << endl;
}
}
int A;
//this is the main program here and it requires return integer to successfully complete
int main(){
	cout<<"use 1 and 2 and 3"<<endl;
	cout << "\n\nWhat do you want: ";
	cin>>A;
	if (A == 1){
/*if statement allows you to control if a program could enter a section
 *of code or not based on whether a given condition is true or false*/
		int ch;
		cout << "1) add to Queue" << endl;
		cout << "2) delete from Queue" << endl;
		cout << "3) Display all the elements of Queue" << endl;
		cout << "4) Exit" << endl;
		do {
/*run code continuosly until it is breaked*/
			cout << "\nEnter your choice : ";
			cin >> ch;
			switch (ch) {
/*switch for options when press keys*/
				case 1: Insert();
					break;
				case 2: Delete();
					break;
				case 3: Display();
					break;
				case 4:
					exit(1);
// termninating case and program
				default:
					cout<<"\nInvalid choice"<<endl;
					break;
			}
	} while(ch!=4);
	}
	else if (A == 2){
		int ch, val;
		cout << "(1) Push in Stack" << endl;
		cout << "(2) Pop from Stack" << endl;
		cout << "(3) Display Stack" << endl;
		cout << "(4) Exit" << endl;
/*this is for listing the options*/
		do {
			cout << "\n\nEnter your choice: ";
			cin >> ch;
			switch(ch) {
				case 1: {
					cout << "\nEnter a value to be pushed: ";
					cin >> val;
					push(val);
					break;
				}
				case 2: {
					pop();
					break;
				}
				case 3: {
					display();
					break;
				}
				case 4: {
					exit(1);
				}
				default: {
					cout << "\nInvalid Choice" << endl;
					break;
				}
			}
		} while(ch!=4);
	}
	else if (A == 3) {
		int choice;
		list sl;
			start = NULL;
			while (1)
//infinite loop until we meet condition
			{
				cout<<"1- add at beginning"<<endl;
				cout<<"2- add at last"<<endl;
				cout<<"3- add at position"<<endl;
				cout<<"4- Delete"<<endl;
				cout<<"5- Search"<<endl;
				cout<<"6- Display"<<endl;
				cout<<"7- Exit"<<endl;
				cout<<"\nEnter your choice: ";
//this is for listing the options and ask what you want
				cin >> choice;
				switch(choice){
/*switch for options when press keys*/
				case 1:
					sl.insert_begin();
					cout<<endl;
					break;
				case 2:
					sl.insert_last();
					cout<<endl;
					break;
				case 3:
					sl.insert_pos();
					cout<<endl;
					break;
				case 4:
					sl.delete_pos();
					break;
				case 5:
					sl.search();
					cout<<endl;
					break;
				case 6:
					sl.displayo();
					cout<<endl;
					break;
				case 7:
					exit(1);
				default:
					cout<<"\nWrong"<<endl;
					break;
				}
			}
	}
	else if (A == 4) {
		return 0;
//exit program when enter 4
	}
	else {
		cout << "\nWrong\n" << endl;
		exit(1);
//exit when press anything else
	}
	return 0;
//returning value to the main and 0 is success to state that the
//program is working fine
}
