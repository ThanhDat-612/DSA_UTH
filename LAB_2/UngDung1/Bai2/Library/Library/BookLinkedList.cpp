#include "BookLinkedList.h"


BookLinkedList::BookLinkedList() {
	head = nullptr;
	tail = nullptr;
}
void BookLinkedList::insertTail(Book* b) {
	if (this->head == nullptr) {
		this->head = this->tail = b;
		return;
	}
	else {
        this->tail->setPointer(b);
        this->tail = b;

	}
}

void BookLinkedList::inputList() {
    int n;
    cout << "Number of books: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        Book* b = new Book;

        cout << "\nBook Name: ";
        string s;
        getline(cin, s);
        b->setBookName(s);

        cout << "Number of Authors: ";
        int k;
        cin >> k;
        cin.ignore();
        b->setNumAu(k);

        for (int j = 0; j < k; j++) {
            cout << "Author[" << j + 1 << "]: ";
            getline(cin, s);
            b->setAuthor(j, s);
        }

        cout << "Publisher: ";
        getline(cin, s);
        b->setPublisher(s);

        cout << "Published in: ";
        int y;
        cin >> y;
        cin.ignore();
        b->setYear(y);

        insertTail(b);
    }
}
int BookLinkedList::countByAuthor(string author) {
    int count = 0;
    Book* p = this->head;

    while (p != nullptr) {
        for (int i = 0; i < p->getNumAu(); i++) {
            if (p->getAuthor(i) == author) {
                count++;
                break;
            }
        }
        p = p->getPointer();
    }
    return count;
}

void BookLinkedList::searchByYear(int y, string a) {
    Book* p = this->head;
    bool found = false;
    int index = 1;
    while (p != nullptr) {

        if (p->getYear() == y && p->getPublisher() == a) {
            cout << index << " - " << p->getBookName() << endl;
            found = true;
        }
        p = p->getPointer();
        index++;
    }
    if (!found) cout << "Empty" << endl;
}