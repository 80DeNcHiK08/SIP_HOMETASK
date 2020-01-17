#include "pch.h"
#include "Tree.h"
#include "Tree.cpp"
#include "Student.h"
#include "Group.h"
#include "Faculty.h"
#include <ctime>

int main()
{
	Tree<int, int> tree;
	
	double duration;
	int counter = 1;
	for (int i = 0; i < 33; i++)
	{
		clock_t start = clock();
		tree.Add(rand());
		duration = ((double)clock() - start) / (double)CLOCKS_PER_SEC;
		std::cout << "Inserting " << counter << " element; Time: " << duration << std::endl;
		counter++;
	}

	int keytodelete = 11;

	TreeNode<int, int>* result;
	if (tree.Find(keytodelete, result, false))
		std::cout << "Success! Value is: " << result->Value << std::endl;
	else
		std::cout << "There is no value with such key" << std::endl;
	tree.PrintLevelOrder();
	tree.Remove(keytodelete);
	if (tree.Find(keytodelete, result, false))
		std::cout << "Success! Value is: " << result->Value << std::endl;
	else
		std::cout << "There is no value with such key" << std::endl;
	tree.PrintLevelOrder();

	Student stud1 = Student(_T("Naвыаывme1"),
							_T("LastName1"),
							_T("MidName1"),
							9199,
							14.3);
	Student stud2 = Student(_T("Name2"),
							_T("LastName2"),
							_T("MidName2"),
							11368,
							11.2);
	Student stud3 = Student(_T("Name2"),
							_T("LastName2"),
							_T("MidName2"),
							11368,
							11.2);

	Faculty ftree = Faculty(_T("FFEKS"));
	Group gtree = Group(_T("KS-16-1"));

	gtree.Add(stud1);
	gtree.Add(stud2);
	ftree.Add(gtree);
	if (stud1 != stud3)
		std::cout << "Theese studends are different;\n";
	else
		std::cout << "Theese students are the same!\n";

	system("Pause");
}