--<���� �� �Լ��� ����ϼ���>
--1) �̸��� �� ������ �л��� �̸��� �˻��ϼ���
SELECT SNAME �̸�
FROM STUDENT
WHERE LENGTH(SNAME) = 2;

--2) '��'�� ���� ���� �л��� �̸��� �˻��ϼ���
SELECT SNAME �̸�
FROM STUDENT
WHERE SUBSTR(SNAME, 1, 1) = '��';

--3) ������ ������ �ѱ��ڷ� �˻��ϼ���(ex. ������ -> ��)
SELECT SUBSTR(ORDERS, 1, 1) ����
FROM PROFESSOR;

--4) �Ϲ� ������ ���� �������� �����ؼ� ��� ������ �˻��ϼ���
--   (ex. �Ϲ�ȭ�� -> ����ȭ��)
SELECT REPLACE(CNAME, '�Ϲ�', '����') ����
FROM COURSE;

--5) ���� �Է� �Ǽ��� student���̺��� sname�÷��� �����Ͱ� �Էµ� ��
--   ���ڿ� �������� ������ �߰��Ǿ��ٸ� �˻��� �� �̸� �����ϰ�
--   �˻��ϴ� SELECT ���� �ۼ��ϼ���
SELECT TRIM(TRAILING FROM SNAME)
FROM STUDENT;

select replace(sname,' ','')
from student;