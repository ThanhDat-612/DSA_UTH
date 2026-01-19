#include <iostream>
#include<fstream>
#include"Dictionary.h"
void loadDataFromFile(Dictionary& dict, string fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Khong the mo file " << fileName << "!" << endl;
        return;
    }

    string line;
    int count = 0;
    while (getline(file, line)) {
        size_t pos = line.find(':');
        if (pos != string::npos) {
            string word = line.substr(0, pos);
            string mean = line.substr(pos + 1);
            dict.add(word, mean); // Sử dụng hàm add có sẵn của Dictionary
            count++;
        }
    }
    file.close();
    cout << "Da nap thanh cong " << count << " tu vao tu dien." << endl;
}
int main()
{
    Dictionary dict;
    loadDataFromFile(dict, "data.txt");
    int choice;
    string w, d;
    while (true) {
        cout << "\n--- TU DIEN ANH - VIET (AVL TREE) ---\n";
        cout << "1. Add Word\n";
        cout << "2. Update Word\n";
        cout << "3. Delete Word\n";
        cout << "4. Liet ke tat ca (A-Z)\n";
        cout << "5. Lookup Word\n";
        cout << "6. Thoat\n";
        cout << "Chon thao tac: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Nhap tu tieng Anh: "; getline(std::cin, w);
            cout << "Nhap nghia tieng Viet: "; getline(std::cin, d);
            dict.add(w, d);
            break;
        case 2: 
            cout << "Nhap tu tieng Anh: "; getline(std::cin, w);
            cout << "Nhap nghia tieng Viet: "; getline(std::cin, d);
            dict.update(w, d);
        case 3:
            //
        case 5:
            cout << "Nhap tu can tra: "; getline(std::cin, w);
            dict.lookup(w);
            break;
        case 4:
            cout << "Danh sach tu dien:\n";
            dict.TravelLNR(); 
            break;
        case 6:
            return 0;
        }
    }
    return 0;
}

