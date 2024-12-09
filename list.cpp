#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
struct node{
    int data;
    node* next = nullptr;
};
void init(size_t n, int value, node*& head ){ // допилить
head = new node;
node* current;
head -> data = value;
current = head;
for(int i = 1; i < n; i++){
    node* p = new node;
    p->data = value;
    current->next = p;
    current = current->next;
}
current->next = head;
}
void print_list(node*& head){
    if (head == nullptr){
        cout << "there is no list \n";
        return;
    }
    node* p = head;
    do{
        cout<< p->data<<" ";
        p = p->next;
    }while(p != head);
}

void add(int value, node*& head){ // допилить
if (head == nullptr){
    init(1,value, head);
} else if(value <=  head->data){
    node* p = new node;
    node* current = head;
    p->data = value;
    p->next = head;
    while(current->next != head ){
        current = current->next;
    }
    current->next = p;
    head = p;
} else {
    node* current = head;
    while(value > current->next->data and current->next != head){
        current = current->next;
    }
    if (current->next == head){
        node*p = new node;
        p -> data = value;
        p->next = head;
        current ->next = p;
        return;
    }
    node* p =new node;
    p->next = current->next;
    current->next = p;
    p->data = value;
}
}
bool srch(int value, node*& head){
    if (head == nullptr){
     //   cout<<"There is no elements in list\n";
        return false;
    }
    node* current = head;
    bool fl = false; // флаг для проверки наличия значения
    int i = 1;
    do {
        if(current->data == value){
            fl = true;
        }
        current = current->next;
        i++;
    }while(current != head);
    if(fl == false){
        return false;
    } else {
        return true;
    }
}
void del(int value, node*& head){
    bool fl = srch(value, head);
    if (fl == false){
        cout << "There is no such value \n";
    } else if (head ->next == head){
        delete head;
        head = nullptr;
     } else {
        node* current = head;
        node* p = head->next; // указатель на следующий элемент
        while(srch(value, head)){
            while(p->data != value){
                current = p;
                p = p->next;
            }
            p = p->next;
            node* h = current->next;
            if (h == head){
                delete h;
                head = p;
                current->next = head;
            } else {
                delete h;
                current->next = p;
            }
                if (head ->next == head and head ->data == value){
            delete head;
            head = nullptr;
        }
        }
    }

}
vector<int> toVector(node *& head){
    vector<int> v;
    if (head == nullptr){
        cout << "There is no list \n";
        return v;
    }
    node* current = head;
    do{
        v.push_back(current->data);
        current = current->next;
    }while (current != head);
    return v;
}
void toList(vector<int> v, node *& head){
    for (int c:v){
        add(c,head);
    }
}
void clear(node *&head){
    node* current = head;
    node* p = current->next;
    while (current->next != head){
        current = current->next;
    }
    node* end = current;
    current = head;
    while (p != end){
        delete current;
        current = p;
        p= p->next;
    }
    delete end;
    head = nullptr;
}
// bool operator<(const node& a, const node& b) {
//     return a.data < b.data;
// }
int main(){
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    node* h1 = nullptr;
    node* h2 = nullptr;
    node* h3 = nullptr;
    init(4,1, h1);
    //add(1, h1);
    add(6, h1);
    //add(8, h1);
    //add(2, h1);
    //add(1, h1);
    //del(6, h1);
    del(5, h1);
    //add(4, h1);
    //add(7, h1);
    init(1,1, h2);
    //del(1, h2);
   // add(5, h2);
    add(6, h2);
   // add(4, h2);
   // add(2, h2);
   // add(90, h2);
   cout << endl;
    v1 = toVector(h1);
    v2 = toVector(h2);
    cout << "Vector1 " << endl;
    for (auto c :v1 ){
        cout << c << " ";
    }
    cout << endl;
    cout << "Vector2 "<< endl;
    for (auto c :v2 ){
        cout << c<< " ";
    }
    cout << endl;
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
    //  for (auto c :v3 ){
    //     cout << c<< " ";
    // }
    toList(v3, h3);
    clear(h1);
    //print_list(h1);
    cout << "List3 ";
    print_list(h3);
    clear(h2);
    clear(h3);
}