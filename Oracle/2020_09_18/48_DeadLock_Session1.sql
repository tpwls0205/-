[�����(DEAD LOCK)�� �߻��ϰ� ����� Ȯ���Ѵ� - SESSION 1]

2) '�尢' �л��� �࿡ ���� ����� �߻���
   '����' �л��� ������ �õ������� ��� SESSION 0��
   ���� ��ݿ� ���� WAIT ���·� �����ϰ� �ȴ�
SELECT SNO, SNAME, MAJOR
FROM STUDENT
WHERE SNAME IN ('����', '�尢');

UPDATE STUDENT SET MAJOR = '����'
WHERE SNAME = '�尢';

UPDATE STUDENT SET MAJOR = '����'
WHERE SNAME = '����';
