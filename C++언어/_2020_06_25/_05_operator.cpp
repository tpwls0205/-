#include <iostream>

void main()
{
	int num1, num2;									
	std::cout << "���� 2�� �Է�: " << std::endl;		// std��� �� �ȿ� �Ҽӵ� ::
	// std�ȿ� �Ҽӵ� �ܼ־ƿ��Լ��� ����ϰ� std�ȿ� �Ҽӵ� ���๮�ڸ� ���
	// ������ �����ε�(���������� ǥ���Ѵ�)
	std::cin >> num1 >> num2;						// cin �ַܼ� ���� �Է¹޾ƶ�.
	std::cout << num1 << "+" << num2 << "=" << num1 + num2 << std::endl;
}