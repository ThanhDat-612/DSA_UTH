//#include <iostream>
//using namespace std;
//int Hash(int k, int M)
//{
//    if (M == 0)
//        return 0;  	
//    return (k % M);
//}
//void InitHash(int*& U, int M)
//{
//    int K[5] = { 1,2,4,6,9 };
//    int i, pos;
//
//    for (i = 0; i < M; i++)
//        U[i] = 0;
//    for (i = 0; i < 5; i++)
//    {
//        pos = Hash(K[i], M);
//        U[pos] = K[i];
//    }
//}
//int main()
//{
//    int M = 10;
//    int* U = new int[M];
//    int pos;
//
//    InitHash(U, M);
//
//    int x;
//    cout<<"Nhap khoa tim kiem: ";
//    cin >> x;
//
//    pos = Hash(x, M);  	
//    if (U[pos] == 0) {
//       cout<<"Khong tim thay khoa trong bang bam\n";
//    }
//    else {
//        cout<<"Gia tri phan tu can tim kiem:"<< pos<<"\n";
//    }
//
//    return 0;
//}
#include <iostream> 
#include <string> 
#include<vector>
#include<cstring>
using namespace std;
struct Word
{
    int key;
    char value[128];
};  
struct Student {
    string name;
    string email;
    string phone;
    string mssv;
    Student* next; 
};
int HashString(string s, int M) {
    int sum = 0;
    for (char c : s) sum += (int)c;
    return sum % M;
}
int Hash(int k, int M)
{
    if (M == 0)
        return 0;  	return (k % M);
}
void InitHash(Word*& U, int M,int n)
{
    int i, pos;

    for (i = 0; i < M; i++)
        U[i].key = 0;
    for (i = 0; i < n; i++)
    {
        int mssv;
        char ten[128];
        cout << "Nhap MSSV: ";
        cin >> mssv; cin.ignore();
        cout << "Nhap Ten: ";
        cin.getline(ten, 128);

        pos = Hash(mssv, M);
        U[pos].key = mssv;
    }
}  

void InsertChaining(Student* bucket[], string name, string email, string phone, string mssv, int M) {
    int pos = HashString(name, M);
    Student* newNode = new Student{ name, email, phone, mssv, nullptr };

    newNode->next = bucket[pos];
    bucket[pos] = newNode;
}
void cau1_2() {
    int M = 10;
    Student* bucket[10] = { nullptr };

    InsertChaining(bucket, "An", "an@gmail.com", "0123", "SV01", M);
    InsertChaining(bucket, "Binh", "binh@gmail.com", "0456", "SV02", M);

    string searchName;
    cout << "Nhap ten SV can tim: ";
    getline(cin, searchName);

    int pos = HashString(searchName, M);
    Student* temp = bucket[pos];
    bool found = false;

    while (temp != nullptr) {
        if (temp->name == searchName) {
            cout << "Tim thay! MSSV: " << temp->mssv << " | Email: " << temp->email << endl;
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (!found) cout << "Khong tim thay sinh vien." << endl;
}
void demo() {
    int M, n;
    cin >> M >> n;
    Word* U = new Word[M]; int pos;

    InitHash(U, M, n);
    int x;
    cout << ("Nhap MSSV tim kiem: "); cin >> x;
    pos = Hash(x, M); if (U[pos].key == 0) {
        cout << ("Khong tim thay SV nao trong bang bam\n");
    }
    else {
        cout << "Ten cua SV can tim kiem la: " << U[pos].value << endl;
    }
}
struct StudentNode {
    string name;
    string email;
    string phone;
    string mssv;
    bool isFull = false;

};
void cau3() {
    int M = 20;
    StudentNode hashTable[20];

    string name = "Nguyen Van A";
    int pos = HashString(name, M);

    hashTable[pos].name = name;
    hashTable[pos].mssv = "2021001";
    hashTable[pos].email = "a@gmail.com";
    hashTable[pos].isFull = true;

    string query;
    cout << "Nhap ten SV can tim: ";
    getline(cin, query);

    int h = HashString(query, M);
    if (hashTable[h].isFull && hashTable[h].name == query) {
        cout << "Tim thay! MSSV: " << hashTable[h].mssv << " - Email: " << hashTable[h].email << endl;
    }
    else {
        cout << "Khong tim thay thong tin!" << endl;
    }
}

void InsertQuadratic(vector<StudentNode>& table, int M, string name, string email, string phone, string mssv) {
    int h = HashString(name, M);

    for (int i = 0; i < M; i++) {
        // Công thức dò bậc 2: pos = (hash + i^2) % M
        int pos = (h + i * i) % M;

        if (!table[pos].isFull) {
            table[pos].name = name;
            table[pos].email = email;
            table[pos].phone = phone;
            table[pos].mssv = mssv;
            table[pos].isFull = true;
            return;
        }
    }
    cout << "Bang bam day, khong the them SV: " << name << endl;
}
void cau4() {
    int M = 11;
    vector<StudentNode> table(M);

 
    InsertQuadratic(table, M, "Messi", "leo@gmail.com", "0901", "SV10");
    InsertQuadratic(table, M, "Ronaldo", "cr7@gmail.com", "0907", "SV07");

   
    string searchName;
    cout << "Nhap ten SV can tim (Do bac 2): ";
    getline(cin, searchName);

    int h = HashString(searchName, M);
    bool found = false;
    for (int i = 0; i < M; i++) {
        int pos = (h + i * i) % M;
        if (!table[pos].isFull) break;
        if (table[pos].name == searchName) {
            cout << "--- Tim thay (Do bac 2) ---" << endl;
            cout << "MSSV: " << table[pos].mssv << "\nEmail: " << table[pos].email << "\nSDT: " << table[pos].phone << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Khong tim thay sinh vien!" << endl;
}
int Hash1(string s, int M) {
    int sum = 0;
    for (char c : s) sum += (int)c;
    return sum % M;
}
int Hash2(string s) {
    int sum = 0;
    for (char c : s) sum += (int)c;
    return 7 - (sum % 7);
}
void InsertDouble(vector<StudentNode>& table, int M, string name, string email, string phone, string mssv) {
    int h1 = Hash1(name, M);
    int h2 = Hash2(name);

    for (int i = 0; i < M; i++) {
        // Công thức băm kép: pos = (h1 + i * h2) % M
        int pos = (h1 + i * h2) % M;

        if (!table[pos].isFull) {
            table[pos].name = name;
            table[pos].email = email;
            table[pos].phone = phone;
            table[pos].mssv = mssv;
            table[pos].isFull = true;
            return;
        }
    }
    cout << "Bang bam day hoac xay ra vong lap!" << endl;
}
void cau5() {
    int M = 13;
    vector<StudentNode> table(M);

    InsertDouble(table, M, "Xavi", "xavi@barca.com", "0906", "SV06");
    InsertDouble(table, M, "Iniesta", "don@barca.com", "0908", "SV08");

    string searchName;
    cout << "Nhap ten SV can tim (Bam kep): ";
    getline(cin, searchName);

    int h1 = Hash1(searchName, M);
    int h2 = Hash2(searchName);
    bool found = false;

    for (int i = 0; i < M; i++) {
        int pos = (h1 + i * h2) % M;
        if (!table[pos].isFull) break;
        if (table[pos].name == searchName) {
            cout << "--- Tim thay (Bam kep) ---" << endl;
            cout << "MSSV: " << table[pos].mssv << "\nSDT: " << table[pos].phone << "\nEmail: " << table[pos].email << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Khong tim thay sinh vien!" << endl;
}
int main() {
    cau5();
    
}