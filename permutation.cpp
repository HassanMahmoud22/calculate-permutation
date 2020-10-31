#include <vector>
#include <iostream>
#include <string>
using namespace std;
class perm
{
private:
	int counter;
	int count;
	string var;
public:
	vector<string> vec;
	perm()
	{
		counter = 0;
		count = 0;
	}

	void RecPermute(string soFar, string rest)
	{
		if (rest == "")
		{
			vec.push_back(soFar);		//storing all elements in vector
		}
		else
		{
			for (int i = 0; i < rest.length(); i++) {
				string next = soFar + rest[i]; // Glue next char
				string remaining = rest.substr(0, i) + rest.substr(i + 1);

				RecPermute(next, remaining);
			}
		}

	}
	// "wrapper" function
	void ListPermutations(string s) {
		RecPermute("", s);
	}
	void printer()
	{							//function print them and prevent repeating
		for (int i = 0; i < vec.size() - 1; i++)
		{

			for (int j = i+1; j < vec.size(); j++)
			{
				if (vec[i] == vec[j])
				{
					vec.erase(vec.begin() + j);	//if repetation found then delete the first one
					j--;
				}
			}

		}
		for (int i = 0; i < vec.size(); i++)
		{
				cout << vec[i] << endl;		//for loop to print the elements after deleting the repeating ones
		}

	}

};


int main()
{
	string name = "Makka";
	perm obj , obj1 , obj2, obj3;
	obj.ListPermutations(name);  //test case 1
	cout << "Test 1:- \n the value is : " << name << endl << "it's permutations are : " << endl;
	obj.printer();
	name = "abc";             //test case 2
	obj1.ListPermutations(name);
	cout << "Test 2:- \n the value is : " << name << endl << "it's permutations are : " << endl;
	obj1.printer();
	name = "oqoq";           //test case 3
	obj2.ListPermutations(name);
	cout << "Test 3:- \n the value is : " << name << endl << "it's permutations are : " << endl;
	obj2.printer();
	name = "ooo";               //test cas 4
	obj3.ListPermutations(name);
	cout << "Test 4:- \n the value is : " << name << endl << "it's permutations are : " << endl;
	obj3.printer();

}

