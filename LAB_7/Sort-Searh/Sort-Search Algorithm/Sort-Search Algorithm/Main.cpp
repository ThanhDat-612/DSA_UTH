#include <iostream>
#include<fstream>
#include<vector>
using namespace std;

void Swap(int& a, int& b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void SelectionSort(int a[], int N, bool isAscending) { //Ghi chú: tại sao không sử dụng kí hiệu & trong hàm này? 
                                       // Mang duoc tao mac dinh duoc truyen duoi dang con tro nen khong can &
    int min; //chỉ số phần tử nhỏ nhất trong dãy hiện hành 
    for (int i = 0; i < N - 1; i++) { //Ghi chu: vòng lặp này dùng để làm gì? 
                                       // duyet tu dau den cuoi mang
        min = i; 

        for (int j = i + 1; j < N; j++) { //Ghi chu: vòng lặp này dùng để làm gì? 
                                        // tim phan tu nho nhat trong doan con lai cua mang ( tu i+1 tro di)
            if (isAscending) {
                if (a[j] < a[min]) {
                    min = j; //Ghi chu: thao tác này dùng để làm gì? 
                    // cap nhat lai gia tri min
                }
            }
            else {
                if (a[j] > a[min]) {
                    min = j; //Ghi chu: thao tác này dùng để làm gì? 
                            // cap nhat lai gia tri min
                }
            }
            
        }

        if (min != i) {
            Swap(a[min], a[i]); //Ghi chu: thao tác này dùng để làm gì? 
                                // doi cho 2 phan tu de min ve dung vi tri
        }
    }
}

void Shift(int a[], int left, int right) {
    int  x, curr, joint;
    curr = left; joint = 2 * curr + 1; // a	:  Phần tử liên đới joint
    x = a[curr];

    while (joint <= right) {

        // Mục đích: Tìm nút con có giá trị LỚN NHẤT giữa con trái và con phải.
        if (joint < right) { // Ghi chú: điều kiện này có ý nghĩa gì? 
                            // // Nếu 'joint < right' nghĩa là nút cha có ĐỦ 2 con (trái và phải)
            if (a[joint] < a[joint + 1]) {   // Nếu con trái nhỏ hơn con phải
                joint = joint + 1;           // Chọn con phải (vì ta đang xây dựng Max Heap)
            }
        }
        if (a[joint] < x) {  // Nếu con lớn nhất vẫn nhỏ hơn cha
            break;  // Thỏa quan hệ liên đới  
        }

        a[curr] = a[joint];   // Đưa giá trị con lớn nhất lên vị trí cha              
        curr = joint;   // Xét khả năng hiệu chỉnh lan truyền                 
        joint = 2*curr+1; //Tiếp tục tính toán chỉ số con trái của vị trí mới
        // Quá trình này lặp lại để "đẩy" giá trị x xuống cho đến khi đúng vị trí (hiệu chỉnh lan truyền)
    }

    a[curr] = x; // Đặt giá trị x vào vị trí trống cuối cùng đã tìm được
}
void CreateHeap(int a[], int N) {
    // Chỉ số của phần tử cuối cùng là N - 1
    // Nút nội bộ (có con) cuối cùng nằm ở vị trí (N/2 - 1)
    int left = (N / 2) - 1;
    // Chạy từ nút nội bộ cuối cùng về đến gốc (vị trí 0)
    while (left >= 0) {
        // Vun đống tại vị trí 'left'
        // 'right' luôn là chỉ số cuối cùng của mảng (N - 1)
        Shift(a, left, N - 1);

        // Di chuyển sang nút bên trái tiếp theo trong mảng
        left--;
    }
}
void ReverseArray(int a[], int N) {
    int start = 0;
    int end = N - 1;
    while (start < end) {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}
void HeapSort(int a[], int N,bool isAscending) {
    // Bước 1: Xây dựng Max Heap ban đầu
    // Biến mảng lộn xộn thành cấu trúc đống mà phần tử lớn nhất ở a[0]
    CreateHeap(a, N);

    // Bước 2: Sắp xếp
    // right là chỉ số cuối cùng của phần còn lại trong đống
    int right = N - 1;

    while (right > 0) {
        // Đổi chỗ phần tử lớn nhất (ở gốc a[0]) với phần tử cuối cùng (a[right])
        int temp = a[0];
        a[0] = a[right];
        a[right] = temp;

        // Sau khi đổi chỗ, phần tử lớn nhất đã nằm đúng vị trí cuối mảng.
        // Ta giảm phạm vi đống đi 1 để "khóa" phần tử đó lại.
        right--;

        // Vun lại đống tại gốc để tìm phần tử lớn nhất tiếp theo
        // Lưu ý: left luôn là 0 vì ta luôn cần chỉnh lại từ gốc
        Shift(a, 0, right);
    }
    if (!isAscending) {
        ReverseArray(a, N);
    }
}
void QuickSort(int a[], int left, int right) {
    int i, j, x;
    // ĐIỀU KIỆN DỪNG: Nếu phân đoạn chỉ có 1 phần tử hoặc rỗng thì không cần sắp xếp
    if (left >= right) {
        return;
    }

    // BƯỚC 1: CHỌN CHỐT (PIVOT)
    x = a[(left + right) / 2]; // chọn phần tử giữa làm giá trị mốc         
    i = left; // i chạy từ đầu phân đoạn
    j = right; // j chạy từ cuối phân đoạn

    // BƯỚC 2: PHÂN HOẠCH (PARTITION)
    // Mục tiêu: Đưa các số nhỏ hơn x về bên trái, các số lớn hơn x về bên phải
    while (i < j) {
        // Tìm phần tử bên trái nhưng lại lớn hơn hoặc bằng chốt (sai vị trí)
        while (a[i] < x) {
            i++;
        }
        // Tìm phần tử bên phải nhưng lại nhỏ hơn hoặc bằng chốt (sai vị trí)
        while (a[j] > x) {
            j--;
        }
        // Nếu tìm thấy một cặp phần tử nằm sai vị trí so với chốt thì đổi chỗ chúng
        if (i <= j) {
            Swap(a[i], a[j]);
            i++;                   
            j--;
        }
    }
    // BƯỚC 3: ĐỆ QUY
    // Sau vòng lặp trên, mảng được chia làm 2 phần: [left...j] và [i...right]

    // Gọi đệ quy để sắp xếp phân đoạn bên trái (các phần tử nhỏ hơn hoặc bằng chốt)
    QuickSort(a, left, j);
    // Gọi đệ quy để sắp xếp phân đoạn bên phải (các phần tử lớn hơn hoặc bằng chốt)
    QuickSort(a, i, right);
}

int main()
{
    ifstream inputFile("data.txt");
    if (!inputFile.is_open()) {
        cout << "Khong the mo file data.txt!" << endl;
        return 1;
    }
    vector<int> a;
    int temp;

    // Đọc cho đến khi không còn số nào trong file
    while (inputFile >> temp) {
        a.push_back(temp); // Thêm số vừa đọc vào cuối mảng
    }

    inputFile.close();

    cout << "Da doc " << a.size() << " phan tu tu file." << endl;
    int N = a.size();
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        arr[i] = a[i];
    }
    HeapSort(arr,N,1);

    cout << "Day sau khi sap xep: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i]<<" ";
    }
}

