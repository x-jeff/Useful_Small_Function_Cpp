#include<string>
#include <WINDOWS.H>
using namespace std;
int main()
{
	string source = "C:\\PersonalDocument1\\TemporaryMaterial\\test\\before\\1.png";//待拷贝的文件
	string destination = "C:\\PersonalDocument1\\TemporaryMaterial\\test\\after\\2.png";//文件拷贝后的位置
	CopyFileA(source.c_str(), destination.c_str(), TRUE);
	return 0;
}