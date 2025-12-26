#include "DaThuc.h"
#include<math.h>
DaThuc::DaThuc() {
	head = nullptr;
}
DaThuc::~DaThuc() {
	element* p = head;
	while (p != nullptr) {
		element* temp = p;
		p = p->getPointer();
		delete temp;
	}
	head = tail = nullptr;
}
void DaThuc::insertTail(element* e) {
	if (this->head == nullptr) {
		this->head = this->tail = e;
	}
	else {
		this->tail->setPointer(e);
		this->tail = e;
	}
}

void DaThuc::insertFirst(element* e) {
	if (this->head == nullptr) {
		this->head = this->tail = e;
	}
	else {
		e->setPointer(this->head);
		this->head = e;
	}
}


void DaThuc::print() {
	if (this->head == nullptr) {
		cout << "0" << endl;
		return;
	}
	element* p = this->head;
	bool first = true;
	while (p != nullptr) {
		int cs = p->getCoSo();
		int sm = p->getSoMu();

		if (!first && cs > 0) cout << " + ";
		if (cs < 0) cout << " - ";

		cout << abs(cs);
		if (sm > 0) {
			cout << "x";
			if (sm > 1) cout << "^" << sm;
		}

		first = false;
		p = p->getPointer();
	}
	cout << endl;
}

double DaThuc::result(double x) {
	double kq = 0;
	element* p = this->head;
	while (p != nullptr) {
		kq += p->getCoSo() * pow(x, p->getSoMu());
		p = p->getPointer();
	}
	return kq;
}

DaThuc DaThuc::operator+(const DaThuc& p) {
	DaThuc result;
	element* p1 = this->head;
	element* p2 = p.head;
	while (p1 != nullptr && p2 != nullptr) {
		if (p1->getSoMu() == p2->getSoMu()) {
			int coSoR = p1->getCoSo() + p2->getCoSo();
			if (coSoR != 0) result.insertTail(new element(coSoR, p1->getSoMu()));

			p1 = p1->getPointer();
			p2 = p2->getPointer();
		}
		else if (p1->getSoMu() > p2->getSoMu()) {
			result.insertTail(new element(p1->getCoSo(), p1->getSoMu()));
			p1 = p1->getPointer();
		}
		else {
			result.insertTail(new element(p2->getCoSo(), p2->getSoMu()));
			p2 = p2->getPointer();
		}
	}
	while (p1 != nullptr) {
		result.insertTail(new element(p1->getCoSo(), p1->getSoMu()));
		p1 = p1->getPointer();
	}

	while (p2 != nullptr) {
		result.insertTail(new element(p2->getCoSo(), p2->getSoMu()));
		p2 = p2->getPointer();
	}
	return result;
}

void DaThuc::insertElement(element* e) {
	if (e->getCoSo() == 0) return;
	if (this->head == nullptr || e->getSoMu() > this->head->getSoMu()){
		e->setPointer(this->head);
		this->head = e;
		if (tail == nullptr) tail = e;
		return;
	}

	element* p = this->head;
	element* prev = nullptr;
	while (p!=nullptr && p->getSoMu()> e->getSoMu()) {
		prev = p;
		p = p->getPointer();
	}
	if (p != nullptr && p->getSoMu() == e->getSoMu()) {
		p->setCoSo(p->getCoSo()+e->getCoSo());
		delete e;

		if (p->getCoSo() == 0) {
			if (p ==this->head) {
				this->head = p->getPointer();
			}
			else {
				prev->setPointer(p->getPointer());
			}
			delete p;
		}
		return;
	}
	prev->setPointer(e);
	e->setPointer(p);
	if (p == nullptr) tail = e;
}

DaThuc DaThuc::operator*(const DaThuc& other) {
	DaThuc result;
	element* p=this->head;
	while (p != nullptr) {
		element* q = other.head;
		while (q != nullptr) {
			int cs = p->getCoSo() * q->getCoSo();
			int sm = p->getSoMu() + q->getSoMu();
			element* e = new element(cs, sm);
			result.insertElement(e);
			q = q->getPointer();

		}
		p = p->getPointer();
	}
	return result;
}