#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 100;  

void displayNum(const int num[], int count) {
    for (int i = 0; i < count; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
}

int main() {
    int num[MAX];    
    int count = 0;               

    string filename;
    cout << "���� �̸��� �Է��ϼ���: ";
    cin >> filename;

    ifstream input(filename);

    while (count < MAX && input >> num[count]) {
        count++;
    }

    cout << "���� ��: ";
    displayNum(num, count);

    for (int i = 0; i < count - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (num[j] < num[minIndex]) {
                minIndex = j;
            }
        }
        int temp = num[i];
        num[i] = num[minIndex];
        num[minIndex] = temp;
    }

    cout << "���� ��: ";
    displayNum(num, count);

    ofstream output(filename);

    for (int i = 0; i < count; i++) {
        output << num[i] << " ";
    }

    output.close();

    cout << "������ �����Ͽ� ���Ͽ� �����Ͽ����ϴ�.." << endl;

    return 0;
}