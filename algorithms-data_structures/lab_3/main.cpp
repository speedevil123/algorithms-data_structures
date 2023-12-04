#include <iostream>
#include "List1.h"

using namespace std;

enum Menu
{
	scan_from_keyboard,
	build_polojitelny_array,
	print_to_display_1arr,
	print_to_display_2arrs,
	insert_proizv_index,
	delete_proizv_index,
	find_index_po_znach,
	find_elem_po_index,
	exit_program
};
int main()
{
	system("chcp 1251");
	int ans;
	List1<int> L1;
	List1<int> L2;

	do
	{
		cout << "�������� ����� ����: " << endl
			<< scan_from_keyboard << " - ��������� ������" << endl
			<< build_polojitelny_array << " - ������� ����� �� ������, ����������� ������������� �����" << endl
			<< print_to_display_1arr << " - ������� �� ����� ������ ������" << endl
			<< print_to_display_2arrs << " - ������� �� ����� ��� ������" << endl
			<< insert_proizv_index << " - �������� ������� � ������������ �������" << endl
			<< delete_proizv_index << " - ������� ������� �� ������������ �������" << endl
			<< find_index_po_znach << " - ����� ������ �������� �� ��������" << endl
			<< find_elem_po_index << " - ����� ������� �� ��� ������������ ( ������� )" << endl;

		cin >> ans;

		switch (ans)
		{
		case scan_from_keyboard:
		{
			L1.Clear();
			int size, value;
			cout << "\n������� ���������� ���������: ";
			cin >> size;

			for (int i = 0; i < size; i++)
			{
				cout << "������� " << i + 1 << " �������: ";
				cin >> value;
				L1.Insert_end(value);
			}
			break;
		}
		case build_polojitelny_array:
		{
			L2.Clear();
			for (int i = 0; i < L1.size(); i++)
			{
				if (L1.GetValue(i) > 0)
					L2.Insert_end(L1.GetValue(i));
			}
			break;
		}
		case print_to_display_1arr:
		{
			cout << "\n�������� ������: \n" << endl;
			L1.Print();
			cout << "\n";
			break;
		}
		case print_to_display_2arrs:
		{
			cout << "\n�������� ������: \n" << endl;
			L1.Print();

			cout << "\n���������� ������ �� ������������� ��������: \n" << endl;
			L2.Print();
			cout << "\n";
			break;
		}
		case insert_proizv_index:
		{
			int index, value;

			cout << "������� ������, ��� ������� ������ ����������� �������: ";
			cin >> index;
			cout << "������� ��������, ������� ������ ��������� ��� �������� ��������: ";
			cin >> value;

			L1.Insert_proizv(index, value);
			break;
		}
		case delete_proizv_index:
		{
			int index;
			
			cout << "������� ������, ��� ������� ������ ������� �������: ";
			cin >> index;

			L1.Delete_proizv(index);
			break;
		}
		case find_index_po_znach:
		{
			int value;
			
			cout << "������� ��������, ��� �������� ����� ������: ";
			cin >> value;

			Node<int>* root = L1.Move_znach(value);
			cout << root->Value();
			break;
		}
		case find_elem_po_index:
		{
			int index;

			cout << "������� ������, �� �������� ������ ����� �������: ";
			cin >> index;

			Node<int>* root = L1.Move(index);
			cout << "��������� ��������: " << root->Value() << endl;
			break;
		}
		} 
	} while (ans != exit_program);

	L1.~List1();
	L2.~List1();
	return 0;
}