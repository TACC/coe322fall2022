/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** link.cxx : linked list using shared smart pointers
 ****
 **** incomplete solution, for as far as discussed in class
 ****
 ****************************************************************/

#include <cmath>

#include <iostream>
using std::cin;
using std::cout;

#include <memory>
using std::make_shared;
using std::shared_ptr;

#include <vector>
using std::vector;

#include <cassert>

class Node {
private:
  int datavalue{0},datacount{0};
  shared_ptr<Node> next{nullptr};
public:
  Node() {}
  Node(int value)
    : datavalue(value),datacount(1) {};
  Node(int value,shared_ptr<Node> next)
    : datavalue(value),datacount(1),next(next) {};
  int value() {
    return datavalue; };
  auto nextnode() {
    return next; };
  int count() {
    return datacount; };
  int listlength() {
    if (!has_next()) return 1;
    else return 1+next->listlength();
  };
  bool contains_value( int v ) {
    if ( datavalue==v ) 
      return true;
    else if (next==nullptr) 
      return false;
    else
      return next->contains_value(v);
  };
  bool has_next() {
    return next!=nullptr; };
  void insert(int value) {
    if (datavalue==value) {
      datacount++;
    } else if (datavalue<value) {
      cout << "THIS CAN NOT HAPPEN\n"; throw;
    } else if (next==nullptr) {
      next = ....
    } else if ( false /* in the middle */ ) {
    } else {
      cout << "WE SEEM TO HAVE MISSED A CASE\n"; throw;
    }
  };
  void print() {
    cout << datavalue << ":" << datacount;
    if (has_next()) {
      cout << ", "; next->print();
    }
  };
};

class List {
private:
  shared_ptr<Node> head{nullptr};
public:
  List() {};
  auto headnode() { return head; };
  void insert(int value) { 
    if (head==nullptr ) {
      //cout << "list is empty\n";
      head = make_shared<Node>(value);
    } else if (value<head->value()) {
      auto newnode = make_shared<Node>(value,head);
      head = newnode;
    } else {
      head->insert(value);
    }
  };
  bool contains_value(int v) {
    if (head==nullptr) {
      return false;
    } else {
      return head->contains_value(v);
    }
  };
  int length() {
    int count = 0;
    auto current_node = head;
    while (current_node!=nullptr) {
      current_node = current_node->nextnode(); count += 1;
    }
    return count;
  };
  int length_iterative() {
    int count = 0;
    auto current_node = head;
    while (current_node!=nullptr) {
      current_node = current_node->nextnode(); count += 1;
    }
    return count;
  };
  int friendlength() {
    if (head==nullptr) return 0;
    else return head->listlength();
  };
  void print() {
    cout << "List:";
    if (head!=nullptr)
      cout << " => "; head->print();
    cout << '\n';
  };
};

int main() {

  List mylist;
  cout << "Empty list has length: "
       << mylist.length() << '\n';
  cout << '\n';

  mylist.insert(3);
  cout << "After inserting 3 the length is: "
       << mylist.length() << '\n';
  mylist.print();

  if (mylist.contains_value(3))
    cout << "Indeed: contains 3" << '\n';
  else
    cout << "Hm. Should contain 3" << '\n';
  if (mylist.contains_value(4))
    cout << "Hm. Should not contain 4" << '\n';
  else
    cout << "Indeed: does not contain 4" << '\n';
  cout << '\n';

  mylist.insert(3);
  cout << "Inserting the same item gives length: "
       << mylist.length() << '\n';
  if (mylist.contains_value(3)) {
    cout << "Indeed: contains 3" << '\n';
    auto headnode = mylist.headnode();
    cout << "head node has value " << headnode->value()
         << " and count " << headnode->count() << '\n';
  } else
    cout << "Hm. Should contain 3" << '\n';
  cout << '\n';
  mylist.print();
  
  mylist.insert(2);
  cout << "Inserting 2 goes at the head;\nnow the length is: "
       << mylist.length() << '\n';
  if (mylist.contains_value(2))
    cout << "Indeed: contains 2" << '\n';
  else
    cout << "Hm. Should contain 2" << '\n';
  if (mylist.contains_value(3))
    cout << "Indeed: contains 3" << '\n';
  else
    cout << "Hm. Should contain 3" << '\n';
  cout << '\n';
  mylist.print();

#if 0
  
  mylist.insert(6);
  cout << "Inserting 6 goes at the tail;\nnow the length is: "
       << mylist.length()
       << '\n';
  if (mylist.contains_value(6))
    cout << "Indeed: contains 6" << '\n';
  else
    cout << "Hm. Should contain 6" << '\n';
  if (mylist.contains_value(3))
    cout << "Indeed: contains 3" << '\n';
  else
    cout << "Hm. Should contain 3" << '\n';
  cout << '\n';

  mylist.insert(4);
  cout << "Inserting 4 goes in the middle;\nnow the length is: "
       << mylist.length()
       << '\n';
  if (mylist.contains_value(4))
    cout << "Indeed: contains 4" << '\n';
  else
    cout << "Hm. Should contain 4" << '\n';
  if (mylist.contains_value(3))
    cout << "Indeed: contains 3" << '\n';
  else
    cout << "Hm. Should contain 3" << '\n';
  cout << '\n';

  cout << "List has length: " << mylist.friendlength() << '\n';
  cout << '\n';

  {
    cout << "Another check.\n";
    List mylist;
    for ( auto i : { 15,23,11,75,11,65,3} ) {
      cout << "insert: " << i << '\n';
      mylist.insert(i);
    }
    mylist.print();
  }
#endif
  
  return 0;
}


