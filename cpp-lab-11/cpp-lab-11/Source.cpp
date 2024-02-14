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
    cout << "¬ведите 10 чисел: ";
    for (int i = 0; i != 10; i++) {
        cin >> temp;
        myList.push_back(temp);
    }
    list<int>::iterator it = myList.begin();

    advance(it, 5);//продвинули итератор
    myList.insert(it, 0);// добавили элемента
    --it; 

    advance(it, -3);//продвинули итератор
    it = myList.erase(it); // удалили элемент

    advance(it, 5);
    myList.splice(it, add); // переносим элементы из одного списка в другой, вставл€ем элементы туда, где находитс€ итератор(второй список становитьс€ пустым)

    cout << "—писок: [ ";
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
    cout << "Ёлементы изначального вектора: [";
    for (vector<int>::const_iterator i = myVector.cbegin(); i != myVector.cend(); ++i) {
        cout << *i << " ";
    }
    cout << "]" << endl;

    // fill_n() присваивает count элементам из диапазона [first,first+count) значение value.

    fill_n(back_inserter(myVector), 3, 100);// добавл€ем в конец вектора три 100
    cout << "Ёлементы вектора после добавлени€ трЄх '100' в конец: [";
    for (vector<int>::const_iterator i = myVector.cbegin(); i != myVector.cend(); ++i) {
        cout << *i << " ";
    }
    cout << "]" << endl;
     
    /*fill_n(front_inserter(myVector), 5, 333);// добавл€ем в начало вектора п€ть 333
    cout << "Ёлементы списка после добавлени€ п€ти '333' в начало: [";
    for (vector<int>::const_iterator i = myVector.cbegin(); i != myVector.cend(); ++i) {
        cout << *i << " ";
    }
    cout << "]" << endl;*/
    vector<int>::iterator forvector = myVector.begin();

    advance(forvector, 10);

    fill_n(inserter(myVector, forvector), 2, 999);

    cout << "Ёлементы вектора после добавлени€ двух '999' перед дес€тым элементом: [";
    for (vector<int>::const_iterator i = myVector.cbegin(); i != myVector.cend(); ++i) {
        cout << *i << " ";
    }
    cout << "]" << endl;

    copy(myVector.begin(), myVector.end(), front_inserter(myList));
    cout << "Ёлементы списка после копировани€ из вектора с конца: [";
    for (list<int>::const_iterator i = myList.cbegin(); i != myList.cend(); ++i) {
        cout << *i << " ";
    }
    cout << "]" << endl;

    
    fill_n(front_inserter(myList), 5, 333);// добавл€ем в начало списка п€ть 333
    cout << "Ёлементы списка после добавлени€ п€ти '333' в начало: [";
    for (list<int>::const_iterator i = myList.cbegin(); i != myList.cend(); ++i) {
        cout << *i << " ";
    }
    cout << "]" << endl;
}

void Files() {
    // чтение из файла
    vector <string> myVector;
    ifstream file("/Users/јлина/Desktop/TextFile1.txt");
    copy(istream_iterator<string>(file), istream_iterator<string>(), back_inserter(myVector));
    file.close();
    cout << "ѕрочтенный из файла вектор: [";
    // copy создает потоковый итератор вывода, который записывает string в выходной поток данных cout, вызыва€ оператор << дл€ каждого элемента
    copy(myVector.begin(), myVector.end(), ostream_iterator<string>(cout, " "));
    cout << "]" << endl;

    //запись в файл
    vector <string> myVector2 = { "67", "345", "12", "-45", "0", "-7" };
    ofstream file2;
    file2.open("/Users/јлина/Desktop/TextFile2.txt");
    copy(myVector2.begin(), myVector2.end(), ostream_iterator<string>(file2, " "));
    file2.close();
    cout << endl;
}

void IteratorCompatibility() {
    vector <int> myVector = { 8, 8, 0, 0, 5, 5, 5, 3, 5, 3, 5 };
    deque<int> myDeck;
    copy(myVector.begin(), myVector.end(), back_inserter(myDeck));
    cout << "Ёлементы вектора: [ ";
    copy(myVector.begin(), myVector.end(), ostream_iterator<int>(cout, " "));
    cout << "]" << endl;
    cout << "Ёлементы дека: [ ";
    copy(myDeck.begin(), myDeck.end(), ostream_iterator<int>(cout, " "));
    cout << "]" << endl;
}

void ReverseIterator() {
    list<int> myList;
    int temp;
    cout << "¬ведите 10 чисел: ";
    for (int i = 0; i != 10; i++) {
        cin >> temp;
        myList.push_back(temp);
    }
    cout << "—писок в обратном пор€дке: [ ";
    for (list<int>::const_reverse_iterator i = myList.crbegin(); i != myList.crend(); ++i) {
        cout << *i << " ";
    }
   
    cout << "]" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << " онтейнерные алгоритмы" << endl;
    ContainerAlgorithms();
    cout << "»тераторы-адаптеры" << endl;
    AdapterIterators();
    cout << "‘айловый ввод-вывод с итераторами" << endl;
    Files();
    cout << "—овместимость итераторов" << endl;
    IteratorCompatibility();
    cout << "ќбратные итераторы" << endl;
    ReverseIterator();
    return 0;
}