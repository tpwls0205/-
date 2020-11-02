#include <iostream>

using namespace std;

void main()
{
	string filename[] = { "readme.txt", "presentation.ppt", "word.doc", "manual.pdf", "plain.txt" };
	for (int i = 0; i < sizeof(filename) / sizeof(filename[0]); i++)
	{
		int period = filename[i].rfind('.');	// 뒤에서 부터 거슬러스 '.'를 찾아내라
		if (period != string::npos) // 못찾지 않았다면 = 즉, 찾았다면
		{
			string ext = filename[i].substr(period);	// 확장자를 검색해서
			if (ext.compare(".txt") == 0)				// .txt로 끝나는 확장자만
			{
				cout << filename[i] << endl;			// 출력하자 = readme, plain
			}
		}
	}
}