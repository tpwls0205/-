<���� �� �Լ��� ����ϼ���>
1) �̸��� �� ������ �л��� �̸��� �˻��ϼ���
SELECT sno, sname
FROM student
WHERE LENGTH(sname)=2;

2) '��'�� ���� ���� �л��� �̸��� �˻��ϼ���
SELECT sno, sname 
FROM student
WHERE SUBSTR(sname, 1, 1)='��';

3) ������ ������ �ѱ��ڷ� �˻��ϼ���(ex. ������ -> ��)
SELECT pno, pname, SUBSTR(orders, 1, 1)
FROM professor;

4) �Ϲ� ������ ���� �������� �����ؼ� ��� ������ �˻��ϼ���
   (ex. �Ϲ�ȭ�� -> ����ȭ��)
SELECT cno, cname, REPLACE(cname, '�Ϲ�', '����')
FROM course
WHERE cname LIKE '�Ϲ�%';
   
5) ���� �Է� �Ǽ��� student���̺��� sname�÷��� �����Ͱ� �Էµ� ��
   ���ڿ� �������� ������ �߰��Ǿ��ٸ� �˻��� �� �̸� �����ϰ�
   �˻��ϴ� SELECT ���� �ۼ��ϼ���
SELECT TRIM(trailing FROM sname)
FROM student;
   
   