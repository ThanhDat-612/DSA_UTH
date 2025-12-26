#include"Element.h"

element::element(int c,int s) {
	coSo = c;
	soMu = s;
	pointer = nullptr;

}
element::element() {
	coSo = 0;
	soMu = 0;
	pointer = nullptr;
}
element* element::getPointer() {
	return this->pointer;
}

void element::setPointer(element* val) {
	pointer = val;
}
void element::setCoSo(int val) {
	coSo = val;
}