#include <iostream>

using namespace std;

void main()
{
	string filename[] = { "readme.txt", "presentation.ppt", "word.doc", "manual.pdf", "plain.txt" };
	for (int i = 0; i < sizeof(filename) / sizeof(filename[0]); i++)
	{
		int period = filename[i].rfind('.');	// �ڿ��� ���� �Ž����� '.'�� ã�Ƴ���
		if (period != string::npos) // ��ã�� �ʾҴٸ� = ��, ã�Ҵٸ�
		{
			string ext = filename[i].substr(period);	// Ȯ���ڸ� �˻��ؼ�
			if (ext.compare(".txt") == 0)				// .txt�� ������ Ȯ���ڸ�
			{
				cout << filename[i] << endl;			// ������� = readme, plain
			}
		}
	}
}