#include <iostream>
using namespace std;

struct Topi{
  string merek, jenis, ukuran;

  Topi *next;
};

Topi *head, *tail, *newNode, *cur, *del;

void createCircularSingleLinkedList(string dataBaru[3]){

  head = new Topi();
  head->merek = dataBaru[0];
  head->jenis = dataBaru[1];
  head->ukuran = dataBaru[2];
  tail = head;
  tail->next = head;

}

void addFirst( string data[3] ){
  if( head == NULL ){
    cout << "Buat Linked List terlebih dahulu !" << endl;
  }else{
    newNode = new Topi();
    newNode->merek = data[0];
    newNode->jenis = data[1];
    newNode->ukuran = data[2];
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
  }
}

void addLast( string data[3] ){
  if( head == NULL ){
    cout << "Buat Linked List terlebih dahulu !" << endl;
  }else{
    newNode = new Topi();
    newNode->merek = data[0];
    newNode->jenis = data[1];
    newNode->ukuran = data[2];
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
  }
}

void addMiddle(string data[3], int posisi)
{
  if( head == NULL ){
    cout << "Buat Linked List terlebih dahulu !" << endl;
  }else{
    if( posisi == 1 ){
      cout << "Posisi satu bukan posisi tengah !" << endl;
    }else{
      newNode = new Topi();
      newNode->merek = data[0];
      newNode->jenis = data[1];
      newNode->ukuran = data[2];

      int nomor = 1;
      cur = head;
      while (nomor < posisi - 1)
      {
        cur = cur->next;
        nomor++;
      }
      newNode->next = cur->next;
      cur->next = newNode;
    }
  }
}

void removeFirst(){
  if( head == NULL ){
    cout << "Buat Linked List terlebi dahulu !" << endl;
  }else{
    del = head;
    head = head->next;
    tail->next = head;
    delete del;
  }
}

void removeLast()
{
  if( head == NULL ){
    cout << "Buat Linked List terlebih dahulu !" << endl;
  }else{
    del = tail;
    cur = head;
    while( cur->next != tail ){
      cur = cur->next;
    }
    tail = cur;
    tail->next = head;
    delete del;
  }
}

void removeMiddle(int posisi)
{
  if( head == NULL ){
    cout << "Buat Linked List terlebi dahulu !" << endl;
  }else{
    int nomor = 1;
    cur = head;
    while( nomor < posisi - 1 ){
      cur = cur->next;
      nomor++;
    }
    del = cur->next;
    cur->next = del->next;
    delete del;
  }
}


void printCircular()
{
  if( head == NULL ){
    cout << "Buat Linked List terlebi dahulu !" << endl;
  }else{
    cout << " List Topi " << endl;
    cout << "================================================================" << endl; 
    cout << "| MERK\t\t| JENIS\t\t\t| UKURAN\t\t|" << endl;
    cout << "================================================================" << endl; 
    cur = head;
    while (cur->next != head)
    {
      cout << "| " << cur->merek << "\t| " << cur->jenis << "\t\t| " << cur->ukuran << "\t\t\t|" << endl;
      cur = cur->next;
    }
    cout << "| " << cur->merek << "\t| " << cur->jenis << "\t\t| " << cur->ukuran << "\t\t\t|" << endl;
    cout << "_________________________________________________________________" << endl;
  }
}


int main(){
  string dataBaru[3] = {"Cheva Hat", "Fedora", "54"};
  createCircularSingleLinkedList(dataBaru);

  printCircular();

  string data[3] = {"Consina", "Komando", "54"};
  addFirst(data);

  printCircular();

  string data2[3] = {"Hurley", "Trucker", "54"};
  addLast(data2);

  printCircular();

  string data3[3] = {"Champion", "Sport", "54"};
  addMiddle(data3, 5);

  printCircular();

  removeMiddle(6);

  printCircular();

  removeFirst();

  printCircular();

  removeLast();

  printCircular();
}
