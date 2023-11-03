#include <iostream>
using namespace std;
class nodestudent {
public:
  string studentname;
  int Birthday_date;
  int Birthday_month;
  int Birthday_year;
  nodestudent *next;
};
nodestudent *head = NULL;
class insert : public nodestudent {
public:
  void insert_at_empty_head() {
    if (head == NULL) {
      nodestudent *newstudent_beginning = new nodestudent;
      {
        cout << endl << "Enter the name of student" << endl;
        cin >> newstudent_beginning->studentname;
        cout << endl
             << "Enter the birth date(date of the  month) of student" << endl;
        cin >> newstudent_beginning->Birthday_date;
        cout << endl << "Enter the birth month of student" << endl;
        cin >> newstudent_beginning->Birthday_month;
        cout << endl << "Enter the birth year of student" << endl;
        cin >> newstudent_beginning->Birthday_year;
        next = NULL;
      }
      head = newstudent_beginning;
    } else {
      insert_at_tail();
    }
  }
  void insert_at_tail() {
    nodestudent *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    nodestudent *newstudent_tail = new nodestudent;
    {
      cout << endl << "Enter the name of student" << endl;
      cin >> newstudent_tail->studentname;
      cout << endl
           << "Enter the birth date(date of the  month) of student" << endl;
      cin >> newstudent_tail->Birthday_date;
      cout << endl << "Enter the birth month of student" << endl;
      cin >> newstudent_tail->Birthday_month;
      cout << endl << "Enter the birth year of student" << endl;
      cin >> newstudent_tail->Birthday_year;
      next = NULL;
    }
    temp->next = newstudent_tail;
  }
};
class del : public insert {
public:
  void del_node() {
    nodestudent *temp = head;
    nodestudent *pre_node = temp;
    string name_del;
    cout << endl
         << "Enter the name of student whose data you want to delete." << endl;
    cin >> name_del;
    if (head->studentname == name_del) {
      temp = head->next;
      delete (head);
      head = temp;
    }
    while (temp->next != NULL) {
      if (temp->studentname == name_del) {
        pre_node->next = temp->next;
        delete temp;
        break;
      }
      pre_node = temp;
      temp = temp->next;
    }
    if (temp->studentname == name_del) {
      delete temp;
    } 
  }
};
class display : public del {
public:
  int count = 1;
  void dis() {
    if (head == NULL) {
      cout << "NO DATA AVAILABLE";
    }
    nodestudent *temp = head;
    while (temp->next != NULL) {
      cout << endl << "Data of student no. " << count << endl;
      count++;
      cout << "Name: " << temp->studentname << endl;
      cout << "Birthday:"
           << " " << temp->Birthday_date << "/" << temp->Birthday_month << "/"
           << temp->Birthday_year << endl;

      temp = temp->next;
    }
    cout << endl << "Data of student no. " << count << endl;
    count++;
    cout << "Name: " << temp->studentname << endl;
    cout << "Birthday:"
         << " " << temp->Birthday_date << "/" << temp->Birthday_month << "/"
         << temp->Birthday_year << endl
         << endl
         << endl
         << endl;
  }
};

int main() {
  char Choice;
  display d;
  while (true) {
    cout << "1.Enter the data of a student." << endl;
    cout << "2.Display the list." << endl;
    cout << "3.Delete the data of the student." << endl;
    cout << "0.Exit" << endl;
    cin >> Choice;
    switch (Choice) {
      case '1':
        d.insert_at_empty_head();
        break;
      case '2':
        d.dis();
        break;
      case '3':
        d.del_node();
        break;
      default:
        cout << "Invalid choice " << endl;
        cout << "Enter the data again " << endl;
        break;
    }
    cout<<"---"<<endl;
  }
  return 0;
}