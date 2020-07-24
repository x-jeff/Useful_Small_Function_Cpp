#include<string>
#include<vector>
#include <io.h>

using namespace std;

void getFiles(string path, vector<string>& files, string format)
{
    intptr_t   hFile = 0;
    struct _finddata_t fileinfo;
    string p;
    if ((hFile = _findfirst(p.assign(path).append("\\*" + format).c_str(), &fileinfo)) != -1)
    {
        do
        {
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    getFiles(p.assign(path).append("\\").append(fileinfo.name), files, format);
            }
            else
            {
                files.push_back(fileinfo.name);
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}

int main()
{
    string path = "C:\\PersonalDocument1\\TemporaryMaterial";//搜索路径
    vector<string> files;//文件名以string的形式存储在vector中
    string format = "pdf";//文件后缀
    getFiles(path, files, format);
    return 0;
}