// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"DaThuc.h"

int main()
{
    DaThuc A;
    DaThuc B;
    int x = 3;
    int n = 4;
    int a = 3;
    int b = 5;
    for (int i = 0;i <= n;i++) {
        element* e = new element(a, n-i);
        element* u = new element(b, n - i);
        A.insertTail(e);
        B.insertTail(u);
    }
    cout << "A = ";
    A.print();
    cout << "B = ";
    B.print();
    DaThuc C =A+B;
    cout << "C = ";
    C.print();
    cout <<"C = "<< C.result(x)<<" voi x = "<<x<<endl;
    DaThuc D = A * B;
    cout << "D = ";
    D.print();
    cout << "D = " << D.result(x) << " voi x = " << x << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
