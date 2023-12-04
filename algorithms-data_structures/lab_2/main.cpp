#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void getFile(string filename, int file_size, int n1, int n2) {
    ofstream in(filename);
    srand(time(0));
    for (int i = 0; i < file_size; i++) {
        in << n1 + rand() % (n2 - n1 + 1) << " ";
    }
    in.close();
}
void getUFile(string filename, int file_size) {
    ofstream in(filename);
    int temp;
    for (int i = 0; i < file_size; i++) {
        temp = i + 1;
        in << temp << " ";
    }
    in.close();
}

void getUrFile(string filename, int file_size) {
    ofstream in(filename);
    int temp;
    for (int i = 0; i < file_size; i++) {
        temp = file_size - i;
        in << temp << " ";
    }
    in.close();

}
void readFile(string filename, int file_size) {
    ifstream in(filename);
    int temp;
    in >> temp;
    for (int i = 0; i < file_size; i++) {
        std::cout << temp << " ";
        in >> temp;
    }
    std::cout << "\n";
    in.close();
}


//C��������� ������ �������� 
void DirectSort(string filename, int file_size) {
    int count = 0;
    //����� ���� log2(size) ��� 
    for (int i = 1; i < file_size; i *= 2) {
        //����� ����� ��� �������
        int temp;
        ifstream in(filename);
        ofstream out1("buffer1.txt"), out2("buffer2.txt");
        in >> temp;
        while (!in.eof()) {
            for (int I = 0; I < i && !in.eof(); I++) {
                out1 << temp << " ";
                in >> temp;
            }
            for (int J = 0; J < i && !in.eof(); J++) {
                out2 << temp << " ";
                in >> temp;
            }
        }
        if (i == 1)
            out2 << temp << " ";
        in.close();
        out1.close();
        out2.close();
        //�������
        ifstream Input_file1("buffer1.txt"), Input_file2("buffer2.txt");
        ofstream outFile(filename);
        int a, b, I = 0, J = 0;
        Input_file1 >> a;
        Input_file2 >> b;
        while (!Input_file1.eof() && !Input_file2.eof()) {
            //������� ���� � ������ ���� ��������
            while (I < i && J < i && !Input_file1.eof() && !Input_file2.eof()) {
                //C������ ������ � ���� �� �������
                if (a < b) {
                    outFile << a << " ";
                    Input_file1 >> a;
                    I++;
                }
                else {
                    outFile << b << " ";
                    Input_file2 >> b;
                    J++;
                }
            }
            //������� ���������� ��������� � ����� �� ���� ������ 
            while (I < i && !Input_file1.eof()) {
                outFile << a << " ";
                Input_file1 >> a;
                I++;
            }
            while (J < i && !Input_file2.eof()) {
                outFile << b << " ";
                Input_file2 >> b;
                J++;
            }
            I = J = 0;
        }
        while (!Input_file1.eof()) {
            outFile << a << " ";
            Input_file1 >> a;
        }
        while (!Input_file2.eof()) {
            outFile << b << " ";
            Input_file2 >> b;
        }
        Input_file1.close();
        Input_file2.close();
        outFile.close();
        count++;
    }
    std::cout << "����� �������: " << count << "\n";
    remove("buffer1.txt");
    remove("buffer2.txt");
}

//����������� ����������
void PolyphaseSort(string filename) {
    FILE* _s;
    fopen_s(&_s, filename.c_str(), "r");
    int cur, _prev, num = 1;
    fscanf_s(_s, "%d", &cur);
    while (!feof(_s)) {
        _prev = cur;
        fscanf_s(_s, "%d", &cur);
        if (cur < _prev)
            num++;
    }
    fclose(_s);
    int min = 0, max = 1, Fib = 1, deep = 0;
    //����������� ������� ��������� �� ���������
    while (Fib < num) {
        min = max;
        max = Fib;
        Fib = min + max;
        deep++;
    }
    //������������ ����� �����
    int maxS = (min + max) - num;

    FILE* s, * buf1, * buf2;
    fopen_s(&s, filename.c_str(), "r");
    fopen_s(&buf1, "buffer1.txt", "w");
    int elem, prev, sI = 0, merges;
    fscanf_s(s, "%d", &elem);
    while (sI != min) {
        prev = elem;
        fprintf_s(buf1, "%d ", elem);
        fscanf_s(s, "%d", &elem);
        if (elem < prev)
            sI++;
    }
    fclose(buf1);
    fopen_s(&buf2, "buffer2.txt", "w");
    while (!feof(s)) {
        fprintf_s(buf2, "%d ", elem);
        fscanf_s(s, "%d", &elem);
    }
    fprintf_s(buf2, "%d ", elem);
    fclose(s);
    for (int i = maxS; i > 0; i--) {
        fprintf_s(buf2, "%d ", 0);
        fprintf_s(buf2, "%d ", 1);
    }
    fclose(buf2);
    //������� ������ �������� ��������� ������
    const char* Buff[][3] = { {"buffer1.txt", "buffer2.txt", "buffer3.txt"},{"buffer2.txt", "buffer3.txt", "buffer1.txt"}, {"buffer3.txt", "buffer1.txt", "buffer2.txt"} };
    //��������� ���������� �������
    for (merges = 0; merges < deep; merges++) {
        FILE* in1, * in2, * out, * temp;
        fopen_s(&in1, Buff[merges % 3][0], "r"); fopen_s(&in2, Buff[merges % 3][1], "r"); fopen_s(&out, Buff[merges % 3][2], "w");
        int elem1, elem2, prev1, prev2;
        fscanf_s(in1, "%d", &elem1);
        fscanf_s(in2, "%d", &elem2);
        while (!feof(in1)) {
            //�������� ������ ����� �� ������������������
            bool flag1 = true, flag2 = true;
            while (flag1 && flag2) {
                if (elem1 < elem2) {
                    fprintf_s(out, "%d ", elem1);
                    prev1 = elem1;
                    fscanf_s(in1, "%d", &elem1);
                    if (elem1 < prev1 || feof(in1))
                        flag1 = false;
                }
                else {
                    fprintf_s(out, "%d ", elem2);
                    prev2 = elem2;
                    fscanf_s(in2, "%d", &elem2);
                    if (elem2 < prev2 || feof(in2))
                        flag2 = false;
                }
            }
            while (flag1 && !feof(in1)) {
                fprintf_s(out, "%d ", elem1);
                prev1 = elem1;
                fscanf_s(in1, "%d", &elem1);
                if (elem1 < prev1)
                    flag1 = false;
            }
            while (flag2 && !feof(in2)) {
                fprintf_s(out, "%d ", elem2);
                prev2 = elem2;
                fscanf_s(in2, "%d", &elem2);
                if (elem2 < prev2)
                    flag2 = false;
            }
        }
        fopen_s(&temp, "_buffer.txt", "w");
        while (!feof(in2)) {
            fprintf_s(temp, "%d ", elem2);
            fscanf_s(in2, "%d", &elem2);
        }
        fclose(in1); fclose(in2); fclose(out); fclose(temp);
        fopen_s(&temp, "_buffer.txt", "r");
        fopen_s(&in2, Buff[merges % 3][1], "w");
        while (fscanf_s(temp, "%d", &elem1) != EOF)
            fprintf_s(in2, "%d ", elem1);
        fclose(in2);
        fclose(temp);
        remove("_buffer.txt");
    }
    int null = maxS;
    int one = null;
    if ((merges - 1) % 3 == 0)
        fopen_s(&buf1, "buffer3.txt", "r");
    else if ((merges - 1) % 3 == 1)
        fopen_s(&buf1, "buffer1.txt", "r");
    else
        fopen_s(&buf1, "buffer2.txt", "r");
    fopen_s(&s, filename.c_str(), "w");
    //������ � ���� ������ � ��������� �� ����
    while (fscanf_s(buf1, "%d", &elem) != EOF) {
        if (elem == 0 && null > 0) {
            null--;
        }
        else if (elem == 1 && one > 0) {
            one--;
        }
        else
            fprintf_s(s, "%d ", elem);
    }
    fclose(buf1);fclose(s);
    //������ ��������� ������
    remove("buffer1.txt"); remove("buffer2.txt"); remove("buffer3.txt");
    std::cout << "����� �������: " << deep - 1 << "\n";
}


int main(void) {
    system("chcp 1251");
    int f = 1;
    int in;
    while (f) {
        cout << "1) C��������� ������ �����, ��������������� ��������� �������\n";
        cout << "2) ����� ���������� �������������� ������\n";
        cout << "0) ����� \n";
        cin >> in;
        switch (in) {
        case 1: {
            int n;
            cout << "������� ����� �����: ";
            cin >> n;
            cout << "������� �������� ��������� �� n1 �� n2 (n1_n2):";
            int n1, n2;
            cin >> n1 >> n2;
            getFile("numbers.txt", n, n1, n2);
            int inp;
            cout << "1) ���������� ������ �������� Merge Sort\n"
                << "2) ����������� ���������� Polyphase Merge Sort\n";
            cin >> inp;
            int t_1 = clock();
            switch (inp) {
            case 1: {
                DirectSort("numbers.txt", n);
                break;
            }
            case 2: {
                PolyphaseSort("numbers.txt");
                break;
            }
            }
            int t_2 = clock();
            int ans = t_2 - t_1;
            cout << n << " �� ������������� �� " << ans << "ms\n";
            readFile("numbers.txt", n);
            break;
        }

        case 2: {
            int size;
            int in2, in3;
            int a1, b1, l;
            cout << "1) ���������� ���������� ����������\n"
                << "2) ���������� �������������� ����������\n"
                << "3) ���������� ��������������������� ����������\n";
            cin >> in2;
            cout << "������� �������� ���� (�� _ �� _) � ��� ����� ������:\n";
            cin >> a1 >> b1 >> l;
            int N = (b1 - a1) / l + 1;
            for (int i = 0; i < N - 1; i++) {
                size = ((i)*l) + a1;
                switch (in2) {
                case 1: {
                    getFile("numbers" + to_string(i + 1) + ".txt", size, 1, 10000000);
                    break;
                }
                case 2: {
                    getUFile("numbers" + to_string(i + 1) + ".txt", size);
                    break;
                }
                case 3: {
                    getUrFile("numbers" + to_string(i + 1) + ".txt", size);
                    break;
                }
                }
            }
            cout << "����� ��������� " << N - 1 << " ��������.\n";

            cout << "1) ���������� ������ �������� Merge Sort\n"
                << "2) ����������� ���������� Polyphase Merge Sort\n";
            cin >> in2;
            ofstream fout("results.txt");
            int t1 = clock();
            switch (in2) {
            case 1: {
                for (int i = 0; i < N - 1; i++) {
                    size = ((i)*l) + a1;
                    int t_1 = clock();
                    DirectSort("numbers" + to_string(i + 1) + ".txt", size);
                    int t_2 = clock();
                    int ans = t_2 - t_1;
                    cout << size << " �� ������������� �� " << ans << "ms\n";
                    fout << size << " " << ans << "\n";
                }
                break;
            }
            case 2: {
                for (int i = 0; i < N - 1; i++) {
                    size = ((i)*l) + a1;
                    int t_1 = clock();
                    PolyphaseSort("numbers" + to_string(i + 1) + ".txt");
                    int t_2 = clock();
                    int ans = t_2 - t_1;
                    cout << size << " �� ������������� �� " << ans << "ms\n";
                    fout << size << " " << ans << "\n";
                }
                break;
            }
            }
            int t2 = clock();
            int answ = (t2 - t1);
            fout.close();
            cout << "����� �����: " << answ << "ms\n";
            cout << "�������� ����� ����������? 1/0\n";
            int clear;
            cin >> clear;
            if (clear) {
                for (int i = 0; i < N - 1; i++) {
                    remove(("numbers" + to_string(i + 1) + ".txt").c_str());
                }
            }
            break;
        }
        case 0: {
            f = 0;
            break;
        }
        }
    }
}

