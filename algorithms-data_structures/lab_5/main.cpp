#include <iostream>
#include <fstream>
#include "header.h"

using namespace std;
enum Menu
{
	insert_elem = 1,
	scan_from_file,
	delete_elem,
	search_elem,
	print_to_display,
	print_to_file,
	comparisons_collisions,
	exit_programm
};
int main()
{
	setlocale(LC_ALL, "Russian");
	HashTable p;
	size_t ans, collisions = 0, comparisons = 0;


	do
	{
		cout << "�������� ����� ����: " << endl
			<< insert_elem << " - �������� �������������" << endl
			<< scan_from_file << " - ��������� �� �����" << endl
			<< delete_elem << " - ������� �������������" << endl
			<< search_elem << " - ����� ��������������" << endl
			<< print_to_display << " - ����� � �������" << endl
			<< print_to_file << " - ����� � ����" << endl
			<< comparisons_collisions << " - ���������� ��������� � ��������" << endl
			<< exit_programm << " - ����� �� ���������" << endl;

		cin >> ans;

		switch (ans)
		{
		case insert_elem:
		{
			string key_insert;
			cout << "������� ������������� ��� �������: ";
			cin >> key_insert;
			while (p.search(key_insert, comparisons))
			{
				cout << "������������� ��� ���� � �������" << "\n������� ����� �������������: ";
				cin >> key_insert;
			}
			p.insert(key_insert, collisions);
			break;
		}
		case scan_from_file:
		{
			p.clear();
			string key_insert_file;
			ifstream fin("input.txt");
			if (!fin)
			{
				cout << "\n������������ �� �����" << "\033[31m" << " ���������\n" << "\033[0m" << endl;
				break;
			}
			while (getline(fin, key_insert_file))
			{
				if (p.search(key_insert_file, comparisons))
				{
					cout << "\n������������� " << " << " << "\033[34m" << key_insert_file << "\033[0m" << " >> " << " ��� ���� � �������" << "\n������� ��������...\n" << endl;
					continue;
				}
				p.insert(key_insert_file, collisions);
			}
			fin.close();
			cout << "\n������������ �� �����" << "\033[32m" << " ���������\n" << "\033[0m" << endl;
			break;
		}
		case delete_elem:
		{
			string key_delete;
			cout << "������� ������������� ��� ��������: ";
			cin >> key_delete;
			p.remove(key_delete);
			break;
		}
		case search_elem:
		{
			string key_search;
			cout << "������� ������������� ��� ������: ";
			cin >> key_search;
			bool search_hash = p.search(key_search, comparisons);

			if (search_hash)
			{
				cout << "\n�������������� ������\n" << endl;
			}
			else
			{
				cout << "\n������������� �� ������\n" << endl;
			}
			break;
		}
		case print_to_display:
		{
			cout << p;
			break;
		}
		case print_to_file:
		{
			ofstream fout("output.txt");
			if (!fout)
			{
				cout << "\n����� � ����" << "\033[31m" << " ��������\n" << "\033[0m" << endl;
			}
			p.print(fout);
			fout.close();
			cout << "\n����� � ����" << "\033[32m" <<  " ��������\n" << "\033[0m" << endl;
			break;
		}
		case comparisons_collisions:
		{
			cout << "\n���������� ��������: " << collisions << "\n���������� ���������: " << comparisons << "\n" << endl;
			break;
		}
		}
	} while (ans != exit_programm);
	p.~HashTable();
	return 0;
};