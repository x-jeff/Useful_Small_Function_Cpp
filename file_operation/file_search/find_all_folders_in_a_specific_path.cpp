#include<string>
#include<vector>
#include<io.h>

using namespace std;

void getFolder(string path, vector<string>& folder)
{
    intptr_t hFile = 0;
    struct _finddata_t fileInfo;
    string p;
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileInfo)) != -1)
    {
        do
        {
            //如果是目录，存入列表
            if ((fileInfo.attrib & _A_SUBDIR))
            {

                if (strcmp(fileInfo.name, ".") != 0 && strcmp(fileInfo.name, "..") != 0)
                    folder.push_back(fileInfo.name);
            }
            else
            {
                continue;

            }
        } while (_findnext(hFile, &fileInfo) == 0);
    }
    _findclose(hFile);
}
int main()
{
    string path = "C:\\PersonalDocument1\\TemporaryMaterial";//搜索路径
    vector<string> folders;//文件夹名以string的形式存储在vector中
    getFolder(path, folders);
    return 0;
}