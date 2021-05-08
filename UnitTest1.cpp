#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\Proc_1\program.h"
#include "..\..\Proc_1\program.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace type_plants;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		// ���� ������� ���������� ���������� "container_Fill"
		TEST_METHOD(Test_Container_Fill_Empty)
		{
			ifstream ifst("In_Empty.txt");	// ������ ������� ����
			container* c = new container;
			container_Init(c);
			container_Fill(c, ifst);
			ifst.close();

			Assert::AreEqual(c->size, 0);
		}

		// ���� ������� container_Fill()
		TEST_METHOD(Test_Container_Fill_4_elem)
		{
			ifstream ifst("In_4_elem.txt"); // ������� ����, ���������� 4 ��������
			container* c = new container;
			container_Init(c);
			container_Fill(c, ifst);
			ifst.close();

			ifstream input_file("In_4_elem.txt");
			int count_string = 0;
			while (input_file.ignore(numeric_limits<streamsize>::max(), '\n'))
			{
				if (!input_file.eof())
					count_string++;
			}
			count_string = count_string + 1;
				
			input_file.close();
			
			Assert::AreEqual(c->size, count_string / 4);
			container_Clear(c);
		}

		// ���� ������� container_Clear()
		TEST_METHOD(Test_container_Clear_Empty)
		{
			ifstream ifst("In_Empty.txt"); // ������ ������� ����
			container* c = new container;
			container_Init(c);
			container_Fill(c, ifst);
			container_Clear(c);
			ifst.close();

			Assert::AreEqual(c->size, 0);
		}

		// ���� ������� container_Clear()
		TEST_METHOD(Test_container_Clear_4_elem)
		{
			ifstream ifst("In_4_elem.txt"); // ������� ����, ���������� 4 ��������
			container* c = new container;
			container_Init(c);
			container_Fill(c, ifst);
			container_Clear(c);
			ifst.close();

			Assert::AreEqual(c->size, 0);
		}
		
		// ���� ������� container_Output()
		TEST_METHOD(Test_container_Output_4_elem)
		{
			ifstream ifst("In_4_elem.txt"); // ������� ����, ���������� 4 ��������
			ofstream ofst("Out_4_elem.txt");
			container* c = new container;
			container_Init(c);
			container_Fill(c, ifst);
			container_Output(c, ofst);
			ifst.close();
			ofst.close();

			ifstream input_file("Out_4_elem.txt");
			int count_string = 0;
			while (input_file.ignore(numeric_limits<streamsize>::max(), '\n'))
			{
				if (!input_file.eof())
					count_string++;
			}
			count_string = count_string + 1;

			input_file.close();

			Assert::AreEqual(c->size, (count_string - 6) / 4);
			container_Clear(c);
		}


		// �������� ��������� ��� ������� ������ ����� ����� ����������
		TEST_METHOD(Test_input_Plants_empty_lines)
		{
			ifstream ifst("In_Plants_empty_lines.txt"); //� ����� 6 �������� � ������� �������� ����� ����
			ofstream ofst("Out_Plants_empty_lines.txt");
			container* c = new container;
			container_Init(c);
			container_Fill(c, ifst);
			container_Output(c, ofst);
			ifst.close();
			ofst.close();

			Assert::AreEqual(c->size, 6);
			container_Clear(c);
		}

		// ���� ���� �� ������� ����� ��������
		TEST_METHOD(Test_input_Plants_shift)
		{
			ifstream ifst("In_Plants_shift.txt"); // � ����� 1 �������� �� ���������� ������
			ofstream ofst("Out_Plants_shift.txt");
			container* c = new container;
			container_Init(c);
			container_Fill(c, ifst);
			container_Output(c, ofst);
			ifst.close();
			ofst.close();

			Assert::AreEqual(c->size, 1);
			container_Clear(c);
		}

		// ���� ������� sort()
		TEST_METHOD(Test_sort_4_elem)
		{
			ifstream ifst("In_4_elem.txt"); // ������� ����, ���������� 4 ��������
			ofstream ofst("Out_sort_4_elem.txt");
			container* c = new container;
			container_Init(c);
			container_Fill(c, ifst);
			sort(c);
			container_Output(c, ofst);
			ifst.close();
			ofst.close();

			ifstream input_file("In_4_elem.txt");
			int count_string = 0;
			while (input_file.ignore(numeric_limits<streamsize>::max(), '\n'))
			{
				if (!input_file.eof())
					count_string++;
			}
			count_string = count_string + 1;

			input_file.close();

			Assert::AreEqual(c->size, count_string / 4);
			container_Clear(c);
		}

		// ���� ������� sort()
		TEST_METHOD(Test_sort_1_elem)
		{
			ifstream ifst("In_1_elem.txt"); // ������� ����, ���������� 1 �������
			ofstream ofst("Out_sort_1_elem.txt");
			container* c = new container;
			container_Init(c);
			container_Fill(c, ifst);
			sort(c);
			container_Output(c, ofst);
			ifst.close();
			ofst.close();

			Assert::AreEqual(c->size, 1);
			container_Clear(c);
		}

		// ���� ������� sort() 
		TEST_METHOD(Test_sort_2_elem)
		{
			ifstream ifst("In_2_elem.txt"); // ������� ����, ���������� 2 ��������
			ofstream ofst("Out_sort_2_elem.txt");
			container* c = new container;
			container_Init(c);
			container_Fill(c, ifst);
			sort(c);
			container_Output(c, ofst);
			ifst.close();
			ofst.close();

			Assert::AreEqual(c->size, 2);
			container_Clear(c);
		}

		// �������� ������� number_consonants() � ������ ��������� ��������� ���� � �������� ��������
		TEST_METHOD(Test_number_consonants_0)
		{
			ifstream ifst("In_number_consonants_0.txt"); // � �������� �������� ��� ��������� ����
			ofstream ofst("Out_number_consonants_0.txt");
			container* c = new container;
			container_Init(c);
			container_Fill(c, ifst);
			container_Output(c, ofst);
			container_Clear(c);
			ifst.close();
			ofst.close();

			ifstream input_file("Out_number_consonants_0.txt");
			string s;
			while (input_file.peek() != EOF) 
			{
				getline(input_file, s);
			}
			input_file.close();
			s = s[s.length() - 2];

			Assert::AreEqual(atoi(s.c_str()), 0);
		}

		// �������� ������� number_consonants() � ������ ����� ��������� ����� � �������� ��������
		TEST_METHOD(Test_number_consonants_1)
		{
			ifstream ifst("In_number_consonants_1.txt"); // � �������� �������� 1 ��������� �����
			ofstream ofst("Out_number_consonants_1.txt");
			container* c = new container;
			container_Init(c);
			container_Fill(c, ifst);
			container_Output(c, ofst);
			container_Clear(c);
			ifst.close();
			ofst.close();

			ifstream input_file("Out_number_consonants_1.txt");
			string s;
			while (input_file.peek() != EOF)
			{
				getline(input_file, s);
			}
			input_file.close();
			s = s[s.length() - 2];

			Assert::AreEqual(atoi(s.c_str()), 1);
		}

		// �������� ������� number_consonants() � ������ ������� ��������� ���� � �������� ��������
		TEST_METHOD(Test_number_consonants_4)
		{
			ifstream ifst("In_number_consonants_4.txt"); // � �������� �������� 4 ��������� �����
			ofstream ofst("Out_number_consonants_4.txt");
			container* c = new container;
			container_Init(c);
			container_Fill(c, ifst);
			container_Output(c, ofst);
			container_Clear(c);
			ifst.close();
			ofst.close();

			ifstream input_file("Out_number_consonants_4.txt");
			string s;
			while (input_file.peek() != EOF)
			{
				getline(input_file, s);
			}
			input_file.close();
			s = s[s.length() - 2];

			Assert::AreEqual(atoi(s.c_str()), 4);
		}

		int Compare(ifstream& ifst_1, ifstream& ifst_2)
		{
			char c1, c2;
			int pos = -1;
			while (ifst_1.get(c1) && ifst_2.get(c2)) 
			{
				pos++;
				if (c1 != c2)
				{
					return pos;
				}
			}
			return -1;
		}
		
		// ���� ������� tree_Output()
		TEST_METHOD(Test_Output_tree)
		{
			ifstream ifst("In_tree.txt");
			ofstream ofst("Out_tree.txt");
			container* c = new container;
			container_Init(c);
			container_Fill(c, ifst);
			container_Output(c, ofst);
			container_Clear(c);
			ifst.close();
			ofst.close();

			ifstream pattern("Pattern_Out_tree.txt");
			ifstream current("Out_tree.txt");
			int res = Compare(current, pattern);
			pattern.close();
			current.close();

			Assert::AreEqual((res + 1), 0);
		}
		
		// ���� ������� bash_Output()
		TEST_METHOD(Test_Output_bush)
		{
			ifstream ifst("In_bush.txt");
			ofstream ofst("Out_bush.txt");
			container* c = new container;
			container_Init(c);
			container_Fill(c, ifst);
			container_Output(c, ofst);
			container_Clear(c);
			ifst.close();
			ofst.close();

			ifstream pattern("Pattern_Out_bush.txt");
			ifstream current("Out_bush.txt");
			int res = Compare(current, pattern);
			pattern.close();
			current.close();

			Assert::AreEqual((res + 1), 0);
		}

		// ���� ������� flower_Output()
		TEST_METHOD(Test_Output_flower)
		{
			ifstream ifst("In_flower.txt");
			ofstream ofst("Out_flower.txt");
			container* c = new container;
			container_Init(c);
			container_Fill(c, ifst);
			container_Output(c, ofst);
			container_Clear(c);
			ifst.close();
			ofst.close();

			ifstream pattern("Pattern_Out_flower.txt");
			ifstream current("Out_flower.txt");
			int res = Compare(current, pattern);
			pattern.close();
			current.close();

			Assert::AreEqual((res + 1), 0);
		}
		

		// ���� ������� Output_only_tree() ��� ������� ����������
		TEST_METHOD(Test_Output_only_tree_Empty)
		{
			ifstream ifst("In_Empty.txt"); // ������ ������� ����
			ofstream ofst("Out_only_tree_Empty.txt");
			container* c = new container;
			container_Init(c);
			container_Fill(c, ifst);
			Output_only_tree(c, ofst);
			container_Clear(c);
			ifst.close();
			ofst.close();

			ifstream input_file("Out_only_tree_Empty.txt");

			int count_string = 0;
			while (input_file.ignore(numeric_limits<streamsize>::max(), '\n'))
			{
				if (!input_file.eof())
					count_string++;
			}
			count_string = count_string + 1;

			input_file.close();

			Assert::AreEqual((count_string - 1) / 4, 0);
		}

		
		// ���� ������� Output_only_tree() ��� �������� � ����������
		TEST_METHOD(Test_Output_only_tree_Without_tree)
		{
			ifstream ifst("In_Without_tree.txt"); // ������� ����, ���������� 2 ��������
			ofstream ofst("Out_only_tree_Without_tree.txt");
			container* c = new container;
			container_Init(c);
			container_Fill(c, ifst);
			Output_only_tree(c, ofst);
			container_Clear(c);
			ifst.close();
			ofst.close();

			ifstream input_file("Out_only_tree_Without_tree.txt");
			int count_string = 0;
			while (input_file.ignore(numeric_limits<streamsize>::max(), '\n'))
			{
				if (!input_file.eof())
					count_string++;
			}
			count_string = count_string + 1;

			input_file.close();

			Assert::AreEqual((count_string - 2) / 4, 0);
		}
		
	};
}
