#include<stdio.h> // <> ���־�Ʃ��� �ȿ� ��Ŭ��� �����ȿ� ��������� �ִ�. - ǥ���Լ�(���̺귯��)
#include<string.h> // ���ڿ��� ���õ� ���
#include<stdlib.h> // �� �ܿ� ��Ÿ �ʿ��� ��� --- �� 3���� ����� �ʼ������� �ٴ´�.
#include<math.h> // �Լ������� ���� ���
#include<conio.h> // ���� 4���� ǥ�������, conio.h�� �ܼ������
#include<time.h> // �ð����� ���

struct _data {
	int code;
	char name[80];
	int type;
};

int main(void) {
	FILE* fp;
	// ���Ͽ� �����Ѵ�� �о���δ�...
	// ���Ͽ� ������ ������ ���� : format
	struct _data d = { 0 };
	d.code = 100;
	strncpy_s(d.name, 80, " ���ǹ��ڿ� ", strlen(" ���ǹ��ڿ� "));
	d.type = 1;

	fopen_s(&fp, "demo-user.dat", "wb");
	fwrite(&d, sizeof(d), 1, fp);
	fclose(fp);

	struct _data t;
	fopen_s(&fp, "demo-user.dat", "rb");
	fread(&t, sizeof(t), 1, fp);
	fclose(fp);
	printf("%d %s %d \n", t.code, t.name, t.type);

	return 0;
}


int main_binary(int argc, char** argv) {
	// �������
	// ũ�� ������ �����
	FILE* fp;
	const char* fname = "demo-block.dat";
	int nums[5][20] = { 0 };							// 20����Ʈ ��ŭ ������ �پ���.
	fopen_s(&fp, fname, "rb");							// wb ���θ���� ����, rb �б�
//	fwrite(nums, sizeof(nums), 1, fp);
	fread(nums, sizeof(nums), 1, fp);
	fclose(fp);
	printf("%s \n", nums[0]);
	printf("%s \n", nums[1]);
	printf("%s \n", nums[2]);
	printf("%s \n", nums[3]);
	return 0;
}


int main_append(int argc, char** argv) {
	// ���� �����
	// FILE �� ����ü, �����ͺ���
	// �Լ��� ������ �˾Ƶθ� �ȴ�.
	// ����, �뵵�� �ִ�.	������, �׷�, �ܺ� - w(����), r(�б�), x(����)
	FILE* fp = NULL;
	fopen_s(&fp, "demo.txt", "a");
	// ������ ������ ���� ���� ���� �߰�
	// ������ ������ ���� ����
	if (fp == NULL) {
		printf("not found error : %s \n", "demo.txt");
		return 0;
	}
	fprintf(fp, "[LOG]%s: %d-%d-%d : %s \n", "192.168.0.1", 2020,10,20, "bitcamp");

	// ���� �ݱ�
	fclose(fp);
	return 0;
}


int main_write(int argc, char** argv) {
	// ���� �����
	// FILE �� ����ü, �����ͺ���
	// �Լ��� ������ �˾Ƶθ� �ȴ�.
	// ����, �뵵�� �ִ�.	������, �׷�, �ܺ� - w(����), r(�б�), x(����)
	FILE* fp = NULL;
		// ���� ����					// w:newfile / r:�б⸸ / a:eof ���ϳ��� �߰� / w+ : �б�, ����(�����ϳ� ����) / r+ : �б�, ����(���� �ϳ�) �������� / a+
		fopen_s(&fp,"demo.txt","w");		// char *:""
		if (fp == NULL) {
			printf("not found error : %s \n", "demo.txt");
			return 0;
		}
		// �б� �Ǵ� ����(���)
		// �ؽ�Ʈ ����
		fputc('A', fp);
		fputc('\n', fp);					// ���๮�� 2byte
		fputs("new new new new", fp);
		// ��������, ���� ���� ������
		fprintf(fp, "%d %s \n", 100, "korea");						// �ٸ� ����Լ����� �ڿ� ������ ���µ�, fprintf�� �տ�����.

		// ���� �ݱ�
		fclose(fp);
	return 0;
}

// BMP�� ������ ������ 54BYTE
// RGB�� �ȼ� �ϳ��ϳ��� 3BYTE : 24BIT
// �̹��� ������ ����ü�� �ʿ�

// ������ �׸�������->�ٸ��̸����� �����ϱ�JPG������ BMP���Ϸ�