#include<string>
#include<iostream>

using namespace std;

int main()
{
	string str1 = "12";
	int n1 = 5;

	//int to string
	string str2 = to_string(n1);
	cout << "str2 : " << str2 << endl;

	//string to int
	int n2 = stoi(str1);
	cout << "n2 : " << n2 << endl;

	return 0;
}