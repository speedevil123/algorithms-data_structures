#include <iostream>
#include <fstream>
#include "header.h"
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

enum menu
{

	ex_1 = 1,
	ex_2,
	exit_program
};

enum sort_type
{
	QuickSort = 1,
	InsertSort
};

enum type_elem_mas
{
	random_numbers = 1,
	ordered_numbers,
	unordered_numbers
};

int main()
{
	system("chcp 1251");
	arraychik<double> p;
	arraychik<double>* pp;

	int ans;

	do
	{
		cout << "�������� ����� ����: " << endl
			<< ex_1 << " - ������ �������" << endl
			<< ex_2 << " - ������ �������" << endl
			<< exit_program << " - ��������� ���������" << endl;
		cin >> ans;

		switch (ans)
		{
		case ex_1:
		{
			int start, end, size, ans;
			cout << "������� ������ �������: ";
			cin >> size;

			cout << "������� �������� ������� ���/����: ";
			cin >> start >> end;

			p.fill_random(size, start, end);

			ofstream fout("initial_mas_ex_1.txt");
			p.print(fout);
			fout.close();

			cout << "�������� ����� ���������� " << endl
				<< QuickSort << " - ������� ���������� ( QuickSort )" << endl
				<< InsertSort << " - ���������� ������� ��������� ( InsertSort )" << endl;

			cin >> ans;

			switch (ans)
			{
			case QuickSort:
			{
				p.quickSort();
				ofstream fout("sorted_mas_ex_1.txt");
				p.print(fout);
				fout.close();
				break;
			}

			case InsertSort:
				{
				p.insertSort();
				ofstream fout("sorted_mas_ex_1.txt");
				p.print(fout);
				fout.close();
				break;
			}
			} 
			break;
		}

		case ex_2:
		{
			int mass_amount, start, end, ans_2;

			cout << "������� ���������� ��������: ";
			cin >> mass_amount;

			pp = new arraychik<double>[mass_amount];

			cout << "�������� ����� ���������� ��������: " << endl
				<< random_numbers << " - ��������� ��������" << endl
				<< ordered_numbers << " - ������������� ������������������" << endl
				<< unordered_numbers << " - ��������������� ������������������" << endl;

			cin >> ans_2;

			switch (ans_2)
			{

			case random_numbers:
			{
				int ans_3, step, sum_step = 0;
				cout << "������� ��� ��������� �������� �������: " << endl;
				cin >> step;

				for (int i = 0; i < mass_amount; i++)
				{
					sum_step += step;

					cout << "������� �������� ������� ���/����: ";
					cin >> start >> end;

					pp[i].fill_random(sum_step, start, end);
				}
				
				cout << "�������� ����� ����������: " << endl
					<< QuickSort << " - ������� ���������� ( QuickSort )" << endl
					<< InsertSort<< " - ���������� ������� ����������� ( InsertSort )" << endl;
				cin >> ans_3;

				switch (ans_3)
				{
				case QuickSort:
				{
					ofstream fout("time_count.txt");

					for (int i = 0; i < mass_amount; i++)
					{
						auto begin = std::chrono::steady_clock::now();
						pp[i].quickSort();
						auto end = std::chrono::steady_clock::now();
						auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
						fout << "���������� ���������: " << pp[i].get_size() << " ������������: " << elapsed_ms.count() << " ms\n";
					}

					fout.close();
					break;
				}

				case InsertSort:
				{
					ofstream fout("time_count.txt");

					for (int i = 0; i < mass_amount; i++)
					{
						auto begin = std::chrono::steady_clock::now();
						pp[i].insertSort();
						auto end = std::chrono::steady_clock::now();
						auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
						fout << "���������� ���������: "<< pp[i].get_size() << " ������������: " << elapsed_ms.count() << " ms\n";
					}

					fout.close();
					break;
				}
				}
				break;
			}

			case ordered_numbers:
			{
				int ans_3;
				int step, sum_step = 0;
				/*������� ����������� � ����� �������� ������ �� ����*/

				cout << "������� ��� ��������� �������� �������: " << endl;
				cin >> step;

				for (int i = 0; i < mass_amount; i++)
				{
					cout << "������� �������� ������������� �������� ���/����: " << endl;
					cin >> start >> end;

					sum_step += step;
					pp[i].fill_ordered(sum_step, start);
				}
				cout << "�������� ����� ����������: " << endl
					<< QuickSort << " - ������� ���������� ( QuickSort )" << endl
					<< InsertSort << " - ���������� ������� ����������� ( InsertSort )" << endl;
				cin >> ans_3;

				switch (ans_3)
				{
				case QuickSort:
				{
					ofstream fout("time_count.txt");

					for (int i = 0; i < mass_amount; i++)
					{
						auto begin = std::chrono::steady_clock::now();
						pp[i].quickSort();
						auto end = std::chrono::steady_clock::now();
						auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
						fout << "���������� ���������: " << pp[i].get_size() << " ������������: " << elapsed_ms.count() << " ms\n";
					}

					fout.close();
					break;
				}

				case InsertSort:
				{
					ofstream fout("time_count.txt");

					for (int i = 0; i < mass_amount; i++)
					{
						auto begin = std::chrono::steady_clock::now();
						pp[i].insertSort();
						auto end = std::chrono::steady_clock::now();
						auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
						fout << "���������� ���������: " << pp[i].get_size() << " ������������: " << elapsed_ms.count() << " ms\n";
					}

					fout.close();
					break;
				}
				}
				break;
			}

			case unordered_numbers:
			{
				int ans_3, step, sum_step = 0;

				cout << "������� ��� ��������� �������� �������: " << endl;
				cin >> step;

				
				for (int i = 0; i < mass_amount; i++)
				{
					cout << "������� �������� ��������������� �������� ���/����: " << endl;
					cin >> start >> end;

					sum_step += step;
					pp[i].fill_unordered(sum_step, end);
				}
				cout << "�������� ����� ����������: " << endl
					<< QuickSort << " - ������� ���������� ( QuickSort )" << endl
					<< InsertSort << " - ���������� ������� ����������� ( InsertSort )" << endl;
				cin >> ans_3;

				switch (ans_3)
				{
				case QuickSort:
				{
					ofstream fout("time_count.txt");

					for (int i = 0; i < mass_amount; i++)
					{
						auto begin = std::chrono::steady_clock::now();
						pp[i].quickSort();
						auto end = std::chrono::steady_clock::now();
						auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
						fout << "���������� ���������: " << pp[i].get_size() << " ������������: " << elapsed_ms.count() << " ms\n";
					}

					fout.close();
					break;
				}

				case InsertSort:
				{
					ofstream fout("time_count.txt");

					for (int i = 0; i < mass_amount; i++)
					{
						auto begin = std::chrono::steady_clock::now();
						pp[i].insertSort();
						auto end = std::chrono::steady_clock::now();
						auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
						fout << "���������� ���������: " << pp[i].get_size() << " ������������: " << elapsed_ms.count() << " ms\n";
					}

					fout.close();
					break;
				}
				}
				break;
			}
			}
			break;
		}
		}
	} while (ans != exit_program);
	return 0;
}
