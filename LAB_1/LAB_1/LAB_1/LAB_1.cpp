#include"Array.h"
#include"Point.h"
#include"Cau3.h"
void cau1() {
    int n;
    cin >> n;
    Array a(n);
    a.input();
    a.print();
    cout << a.countElm();
}
void cau2() {

}
void cau3() {
    Cau3 S;
    cout << S.S_DeQuy(4)<<endl;
    cout << S.S_KhongDeQuy(4)<<endl;

    cout << S.sumDivideByK_DQ(12345, 2) << endl;
    cout << S.sumDivideByK_KDQ(12345, 2) << endl;

    vector<long long> rs = S.getFibInRange(10,100);
    for (long long i : rs) cout << i << " ";
    cout << endl;
}
void cau4() {
    /*Câu 4: Tính giá trị của các phần tử của mảng A sau khi thực hiện đoạn lệnh dưới đây :
    int A[] = { 6,13,34,19 };
    int* p = A;
    *p++;
    *p += 2;
    p += 2;
    *p += 2;*/

    int A[] = { 6,13,34,19 };
    int* p = A; // gia tri dau tien -> 6 A[0]
    *p++;     // = 6 sau do con tro sang A[1] -> 13
    *p += 2;  // con tro A[1] + 2 = 15
    p += 2;  // con tro nhay toi A[3] = 19
    *p += 2;  // con tro A[3] = 21;

    int* x = A;
    cout << x<<endl;
    cout << *x++ << endl;
    *x += 2;
    cout << x << endl;
    x += 2;
    cout << x << endl;
    *x += 2;
    cout << x << endl;

}
int main()
{
    cau1();
    cau2();
    cau3();
    cau4();
    cout << "Hello World!\n";
}

