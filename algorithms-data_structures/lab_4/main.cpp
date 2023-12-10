#include <iostream>
#include <fstream>
#include "header.h"
#include<string>

enum Menu
{
	scan_tree_from_keyboard = 1,
	scan_tree_from_file,
	print_to_console,
	print_to_file,
	add_node,
	delete_node,
	poisk_node_key,
	excersise,
	comparison_trees,
	AVL_tree,
	add_AVL_tree,
	cout_AVL_tree,
	exit_program
	
};

enum Menu2
{
	ordered_print = 1,
	unordered_print,
	koncevoe_print
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Tree<string> p;
	Tree<string> p1;
	BalancedTree<int> p3;
	int ans;
	do
	{
		cout << scan_tree_from_keyboard << " - ������ ������ � ����������" << endl
			<< scan_tree_from_file << " - ������� ������ �� �����" << endl
			<< print_to_console << " - ����� ������ � �������" << endl
			<< print_to_file << " - ����� ������ � ����" << endl
			<< add_node << " - �������� ����" << endl
			<< delete_node << " - ������� ����" << endl
			<< poisk_node_key << " - ����� ���� � �������� �������� �����" << endl
			<< excersise << " - ������� �������" << endl
			<< comparison_trees << " - ��������� ���� ��������" << endl
			<< AVL_tree << " - ���������������� �������� ������" << endl
			<< add_AVL_tree << " - �������� ������� � ���������������� ������" << endl
			<< cout_AVL_tree << " - ������� ���������������� ������ �� �����" << endl
			<< exit_program << " - ����� �� ���������" << endl;
		cin >> ans;
		
		switch (ans)
		{
		case scan_tree_from_keyboard:
		{
			if (p.GetHead() != nullptr)
				p.~Tree();

			int size;
			string value;

			cout << "������� ������� ������ (������ ������� ��������� ������): ";
			/*���������� ������ �����*/
			cin >> p;
			break;
		}
		case scan_tree_from_file:
		{
			if (p.GetHead() != nullptr)
				p.~Tree();

			p.scan_file("derevo_ordered_scan.txt");
			break;
		}
		case print_to_console:
		{
			/*���������� ������ ������*/
			cout << "\n" << p << "\n" << endl;
			break;
		}
		case print_to_file:
		{
			int ans2;
			cout << "�������� ������� ������ � ����: " << endl
				/*ordered_print - ������������ ������� ������, ��� ������� ���������
				����������� �� ����� �� �����, ��� ��� ��� ������ ������ ������ ���� ������, �
				����� scan ����� ������ ������� �� ������*/
				<< ordered_print << " - ������ ����� � ����" << endl
				<< unordered_print << " - �������� ����� � ����" << endl
				<< koncevoe_print << " - �������� ����� � ����" << endl;
				cin >> ans2;

				switch (ans2)
				{
				case ordered_print:
				{
					ofstream fout("derevo_ordered_scan.txt");
					p.print_ordered(fout);
					fout.close();
					break;
				}
				case unordered_print:
				{
					ofstream fout("derevo_unordered.txt");
					p.print_unordered(fout);
					fout.close();
					break;
				}
				case koncevoe_print:
				{
					ofstream fout("derevo_koncevoe.txt");
					p.print_koncevoe(fout);
					fout.close();
					break;
				}
				}
				break;
		}
		case add_node:
		{
			string value;
			cout << "������� ���� ��� ���������� ����: ";
			cin >> value;
			p.add(value);
			break;
		}
		case delete_node:
		{
			string value;
			cout << "������� ���� ��� �������� ����: ";
			cin >> value;
			p.RemoveNode(value);
			break;
		}
		case poisk_node_key:
		{
			string value;
			cout << "������� ���� ��� ������ ����: ";
			cin >> value;
			if (p.search(value))
				cout << "\n������� ������ � ��������� � ������.\n" << endl;
			else
				cout << "\n������� �� ��������� � ������.\n" << endl;
			break;
		}
		case excersise:
		{
			int length;
			cout << "������� ����� ��� �������: " << endl;
			cin >> length;
			p.keyLengthRemove(length);
			break;
		}
		case comparison_trees:
		{
			bool check = false;
			/*���������� � ������� ���������� �������� "==",
			��� ��� ���������� ������ ������ �������(p = p1)
			������� ���������� ����������*/
			p = p1;
			cout << "\n��������� �������� p � p1: ";
			if (p == p1)
			{
				cout << "������� ����������" << endl;
				check = true;
			}
			else
			{
				cout << "������� ���������" << endl;
			}
			cout << endl;


			/*������� ������ p3 �������� �� p, ����� ��������,
			��� ���������� "==" �������� �����*/
			Tree<string> p3;
			cin >> p3;

			cout << "\n��������� �������� p � p3: ";
			if (p1 == p3)
			{
				cout << "������� ����������" << endl;
				check = true;
			}
			else
			{
				cout << "������� ���������" << endl;
			}
			cout << endl;
			break;
		}
		case AVL_tree:
		{
			int size;
			int value;
			cout << "������� ���������� ����� � ������: " << endl;
			cin >> size;
			for (int i = 0; i < size; i++)
			{
				cout << "������� �������� ����: ";
				cin >> value;
				p3.Add(value);
			}
			break;
		}
		case add_AVL_tree:
		{
			int value;
			cout << "������� �������, ������� ������ �������� � ������: ";
			cin >> value;
			p3.Add(value);
			break;
		}
		case cout_AVL_tree:
		{
			cout << "������, ���������� �������� ������� (����-������-�����)" << endl;
			p3.PrintTree();
			cout << endl;
			break;
		}
		}
	} while (ans != exit_program);
	return 0;
}