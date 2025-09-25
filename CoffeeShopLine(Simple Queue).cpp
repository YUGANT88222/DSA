#include <iostream>
using namespace std;
struct Node{
string name;
Node* next;
};
class queue{
private:
Node* front;
Node* rear;
public:
queue(){
front = nullptr;
rear = nullptr;
}
void enqueue(string customerName){
Node* temp = new Node();
temp->name = customerName;
temp->next = nullptr;
if (rear == nullptr) {
front=rear=temp;
}
else{
rear->next = temp;
rear = temp;
}
cout<<customerName<<" joined the line.\n";
}
void dequeue() {
if (front == nullptr) {
cout << "No customers in line.\n";
return;
}
Node* temp = front;
cout << front->name << "'s order is ready. They leave the line.\n";
front = front->next;
if (front == nullptr) {
rear = nullptr;
}
delete temp;
}
void display() {
if (front == nullptr) {

cout << "Line is empty.\n";
return;
}
cout << "Current Line: ";
Node* temp = front;
while (temp != nullptr) {
cout << temp->name;
if (temp->next != nullptr)
cout << " -> ";
temp = temp->next;
}
cout << "\n";
}
};
int main() {
int choice;
queue q;
string name;
cout << "--- Coffee Shop Queue Menu ---";
cout << "\n1. New Customer Arrival (Enqueue)";
cout << "\n2. Serve Customer (Dequeue)";
cout << "\n3. Show Queue";
cout << "\n4. Exit";
do {
cout << "\nEnter your choice: ";
cin >> choice;
switch (choice) {
case 1:
cout << "Enter customer name: ";
cin >> name;
q.enqueue(name);
break;
case 2:
q.dequeue();
break;
case 3:
q.display();
break;
case 4:
cout << "Exiting...\n";
break;
default:
cout << "Invalid choice. Please try again.\n";
break;

}
} while (choice != 4);
return 0;
}
