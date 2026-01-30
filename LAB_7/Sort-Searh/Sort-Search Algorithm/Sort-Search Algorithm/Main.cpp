#include <iostream>
#include<fstream>
#include<vector>
#include<time.h>
#include<chrono>
using namespace std::chrono;
using namespace std;
#define MAX 100000
void Swap(int& a, int& b) {
    if (&a == &b) return;
    int temp = a;
    a = b;
    b = temp;
}
void QuickSwap(int& a, int& b, long long& countAssignment) {
    int temp = a;
    a = b;
    b = temp;
    countAssignment += 3;
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
void QuickSort_1(int a[], int left, int right) {
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
    while (i <= j) {
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
    QuickSort_1(a, left, j);
    // Gọi đệ quy để sắp xếp phân đoạn bên phải (các phần tử lớn hơn hoặc bằng chốt)
    QuickSort_1(a, i, right);
}
void QuickSort_2(int a[], int left, int right, long long& countCompare, long long& countAssignment) {
    // 1 phép so sánh điều kiện dừng
    countCompare++;
    if (left >= right) return;
    int i, j, x;
    // Các phép gán khởi tạo
    x = a[(left + right) / 2];
    i = left;
    j = right;
    countAssignment += 3;

    // Vòng lặp phân hoạch
    while (++countCompare && i <= j) {
        // Đếm so sánh trong while a[i] < x
        while (++countCompare && a[i] < x) {
            i++;
            countAssignment++; // i thay đổi
        }

        // Đếm so sánh trong while a[j] > x
        while (++countCompare && a[j] > x) {
            j--;
            countAssignment++; // j thay đổi
        }

        countCompare++; // Cho lệnh if (i <= j)
        if (i <= j) {
            QuickSwap(a[i], a[j], countAssignment);
            i++;
            j--;
            countAssignment += 2;
        }
    }
    // Đệ quy
    countCompare++; // Cho lệnh if (left < j)
    if (left < j) QuickSort_2(a, left, j, countCompare, countAssignment);

    countCompare++; // Cho lệnh if (i < right)
    if (i < right) QuickSort_2(a, i, right, countCompare, countAssignment);
}

int b[MAX], c[MAX], nb, nc; // Ghi chú: 2 mảng này dùng để làm gì? 
                            // tao ra 2 mang phu de merge la b va c
                            // b co nb phan tu, c co nc phan tu
void Distribute(int  a[], int N, int& nb, int& nc, int k) {
    int i, pa, pb, pc; //Ghi chú: các biến này có ý nghĩa gì? 
                        // i: bien dem
                        // pa: vi tri hien tai trong mang a
                        // pb: vi tri hien tai trong mang b
                        // pc: vi tri hien tai trong mang c
    pa = pb = pc = 0;   	while (pa < N) {
        for (i = 0; (pa < N) && (i < k); i++, pa++, pb++) { //Ghi chú: vòng lặp này có ý nghĩa gì?  
                                                            // sao chep k phan tu lien tuc tu a sang b
            b[pb] = a[pa]; 
        }
        for (i = 0; (pa < N) && (i < k); i++, pa++, pc++) { //Ghi chú: vòng lặp này có ý nghĩa gì?  	 
                                                            // sao chep k phan tu lien tuc tu a sang c
            c[pc] = a[pa]; 
        }
    }
    nb = pb; nc = pc;
}
void MergeSubarr(int a[], int nb, int nc, int& pa, int& pb, int& pc, int k) {
    int rb, rc;  	rb = min(nb, pb + k); 	         rc = min(nc, pb + k);

    while ((pb < rb) && (pc < rc)) {
        if (b[pb] < c[pc])
            a[pa++] = b[pb++];
        else  a[pa++] = c[pc++];
    }

    while (pb < rb) {
        a[pa++] = b[pb++];
    }

    while (pc < rc) {
        a[pa++] = c[pc++];
    }
}
void Merge(int a[], int nb, int nc, int k) {
    int pa, pb, pc;  	pa = pb = pc = 0;

    while ((pb < nb) && (pc < nc)) {
        MergeSubarr(a, nb, nc, pa, pb, pc, k);
    }

    while (pb < nb) {
        a[pa++] = b[pb++]; //Ghi chú: câu lệnh này có ý nghĩa gì? 
                            // gan phan tu mang b sang mang a sau do tang position len 1
    }

    while (pc < nc) {
        a[pa++] = c[pc++]; //Ghi chú: câu lệnh này có ý nghĩa gì? 
                            // gan phan tu mang c sang mang a sau do tang position len 1
    }
}
void MergeSort(int a[], int N, bool isAscending) {
    int k = 1;

    while (k < N) {
        // Bước 1: phân phối mảng a vào b và c theo block k
        Distribute(a, N, nb, nc, k);

        // Bước 2: trộn b và c trở lại a theo block k
        Merge(a, nb, nc, k);

        // Tăng kích thước block
        k *= 2;
    }

    // Nếu cần sắp xếp giảm dần
    if (!isAscending) {
        for (int i = 0; i < N / 2; i++) {
            int temp = a[i];
            a[i] = a[N - 1 - i];
            a[N - 1 - i] = temp;
        }
    }
}

void InsertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        // Dịch các phần tử lớn hơn key sang phải
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        // Chèn key vào vị trí đúng
        a[j + 1] = key;
    }
}

int binarySearch(int a[], int key, int left, int right) {
    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left; // vị trí chèn
}

void BinaryInsertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];

        // Tìm vị trí chèn bằng binary search
        int pos = binarySearch(a, key, 0, i - 1);

        // Dịch các phần tử sang phải
        for (int j = i; j > pos; j--) {
            a[j] = a[j - 1];
        }

        // Chèn key
        a[pos] = key;
    }
}
void InterchangeSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                Swap(a[i], a[j]);
            }
        }
    }
}
void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                Swap(a[j], a[j + 1]);
            }
        }
    }
}

void ShakerSort(int a[], int n) {
    int left = 0;
    int right = n - 1;
    bool swapped = true;

    while (left < right&& swapped) {
        swapped = false;

        // Quét từ trái sang phải
        for (int i = left; i < right; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        right--;

        // Quét từ phải sang trái
        for (int i = right; i > left; i--) {
            if (a[i] < a[i - 1]) {
                Swap(a[i], a[i - 1]);
                swapped = true;
            }
        }
        left++;
    }
}
void ShellSort(int a[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j = i;

            while (j >= gap && a[j - gap] > temp) {
                a[j] = a[j - gap];
                j -= gap;
            }

            a[j] = temp;
        }
    }
}

int getMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}
void countingSort(int a[], int n, int exp) {
    vector<int> output(n);
    int count[10] = { 0 };

    // Đếm số lần xuất hiện của chữ số
    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    // Tính vị trí
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Xây dựng mảng output (đi từ phải sang trái → ổn định)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (a[i] / exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }

    // Copy lại mảng a
    for (int i = 0; i < n; i++)
        a[i] = output[i];
}
void RadixSort(int a[], int n) {
    int max = getMax(a, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(a, n, exp);
    }
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
    int* arr1 = new int[N];
    int* arr2 = new int[N];
    for (int i = 0; i < N; i++) {
        arr1[i] = a[i];
        arr2[i] = a[i];
    }

    auto start1 = high_resolution_clock::now();

    RadixSort(arr1, N); 

    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end1 - start1);



    cout << "Day sau khi sap xep: ";
    for (int i = 0; i < N; i++) {
        cout << arr1[i]<<" ";
    }
    cout << endl;
    cout << "Time: " << duration1.count() << " ms\n";

    //auto start2 = high_resolution_clock::now();

    //QuickSort_1(arr2, 0, N); // pivot o cuoi

    //auto end2 = high_resolution_clock::now();
    //auto duration2 = duration_cast<milliseconds>(end2 - start2);



    /*cout << "Day sau khi sap xep: ";
    for (int i = 0; i < N; i++) {
        cout << arr2[i] << " ";
    }*/
    /*cout << endl;
    cout << "Time: " << duration1.count() << " ms\n";
    cout << "Time: " << duration2.count() << " ms\n";
    if (duration1 < duration2) cout << "pivot dau nhanh hon" << endl;
    else if (duration1 == duration2) cout << "2 pivot bang nhau \n";
    else cout << "pivot giua nhanh hon\n";*/
}


