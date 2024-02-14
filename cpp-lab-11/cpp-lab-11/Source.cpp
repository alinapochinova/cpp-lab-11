#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <fstream>
#include <deque>
using namespace std;

void ContainerAlgorithms() {
    list<int> myList;
    list <int> add = { 6, 5, 4, 3, 2, 1, 123 };
    int temp;
    cout << "������� 10 �����: ";
    for (int i = 0; i != 10; i++) {
        cin >> temp;
        myList.push_back(temp);
    }
    list<int>::iterator it = myList.begin();

    advance(it, 5);//���������� ��������
    myList.insert(it, 0);// �������� ��������
    --it; 

    advance(it, -3);//���������� ��������
    it = myList.erase(it); // ������� �������

    advance(it, 5);
    myList.splice(it, add); // ��������� �������� �� ������ ������ � ������, ��������� �������� ����, ��� ��������� ��������(������ ������ ����������� ������)

    cout << "������: [ ";
    for (list<int>::const_iterator i = myList.cbegin(); i != myList.cend(); ++i) {
        cout << *i << " ";
    }
    cout << "]" << endl;
}

void AdapterIterators() {
    vector <int> myVector;
    list<int> myList;
    for (int i = 1; i <= 10; i++) {
        myVector.push_back(i);
    }
    cout << "�������� ������������ �������: [";
    for (vector<int>::const_iterator i = myVector.cbegin(); i != myVector.cend(); ++i) {
        cout << *i << " ";
    }
    cout << "]" << endl;

    // fill_n() ����������� count ��������� �� ��������� [first,first+count) �������� value.

    fill_n(back_inserter(myVector), 3, 100);// ��������� � ����� ������� ��� 100
    cout << "�������� ������� ����� ���������� ��� '100' � �����: [";
    for (vector<int>::const_iterator i = myVector.cbegin(); i != myVector.cend(); ++i) {
        cout << *i << " ";
    }
    cout << "]" << endl;
     
    /*fill_n(front_inserter(myVector), 5, 333);// ��������� � ������ ������� ���� 333
    cout << "�������� ������ ����� ���������� ���� '333' � ������: [";
    for (vector<int>::const_iterator i = myVector.cbegin(); i != myVector.cend(); ++i) {
        cout << *i << " ";
    }
    cout << "]" << endl;*/
    vector<int>::iterator forvector = myVector.begin();

    advance(forvector, 10);

    fill_n(inserter(myVector, forvector), 2, 999);

    cout << "�������� ������� ����� ���������� ���� '999' ����� ������� ���������: [";
    for (vector<int>::const_iterator i = myVector.cbegin(); i != myVector.cend(); ++i) {
        cout << *i << " ";
    }
    cout << "]" << endl;

    copy(myVector.begin(), myVector.end(), front_inserter(myList));
    cout << "�������� ������ ����� ����������� �� ������� � �����: [";
    for (list<int>::const_iterator i = myList.cbegin(); i != myList.cend(); ++i) {
        cout << *i << " ";
    }
    cout << "]" << endl;

    
    fill_n(front_inserter(myList), 5, 333);// ��������� � ������ ������ ���� 333
    cout << "�������� ������ ����� ���������� ���� '333' � ������: [";
    for (list<int>::const_iterator i = myList.cbegin(); i != myList.cend(); ++i) {
        cout << *i << " ";
    }
    cout << "]" << endl;
}

void Files() {
    // ������ �� �����
    vector <string> myVector;
    ifstream file("/Users/�����/Desktop/TextFile1.txt");
    copy(istream_iterator<string>(file), istream_iterator<string>(), back_inserter(myVector));
    file.close();
    cout << "���������� �� ����� ������: [";
    // copy ������� ��������� �������� ������, ������� ���������� string � �������� ����� ������ cout, ������� �������� << ��� ������� ��������
    copy(myVector.begin(), myVector.end(), ostream_iterator<string>(cout, " "));
    cout << "]" << endl;

    //������ � ����
    vector <string> myVector2 = { "67", "345", "12", "-45", "0", "-7" };
    ofstream file2;
    file2.open("/Users/�����/Desktop/TextFile2.txt");
    copy(myVector2.begin(), myVector2.end(), ostream_iterator<string>(file2, " "));
    file2.close();
    cout << endl;
}

void IteratorCompatibility() {
    vector <int> myVector = { 8, 8, 0, 0, 5, 5, 5, 3, 5, 3, 5 };
    deque<int> myDeck;
    copy(myVector.begin(), myVector.end(), back_inserter(myDeck));
    cout << "�������� �������: [ ";
    copy(myVector.begin(), myVector.end(), ostream_iterator<int>(cout, " "));
    cout << "]" << endl;
    cout << "�������� ����: [ ";
    copy(myDeck.begin(), myDeck.end(), ostream_iterator<int>(cout, " "));
    cout << "]" << endl;
}

void ReverseIterator() {
    list<int> myList;
    int temp;
    cout << "������� 10 �����: ";
    for (int i = 0; i != 10; i++) {
        cin >> temp;
        myList.push_back(temp);
    }
    cout << "������ � �������� �������: [ ";
    for (list<int>::const_reverse_iterator i = myList.crbegin(); i != myList.crend(); ++i) {
        cout << *i << " ";
    }
   
    cout << "]" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "������������ ���������" << endl;
    ContainerAlgorithms();
    cout << "���������-��������" << endl;
    AdapterIterators();
    cout << "�������� ����-����� � �����������" << endl;
    Files();
    cout << "������������� ����������" << endl;
    IteratorCompatibility();
    cout << "�������� ���������" << endl;
    ReverseIterator();
    return 0;
}