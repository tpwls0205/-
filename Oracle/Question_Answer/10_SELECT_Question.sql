1) ȭ�а� �л��� �˻��϶�
SELECT *
FROM student
WHERE major='ȭ��';

2) ������ 2.0 �̸��� �л��� �˻��϶�
SELECT *
FROM student
WHERE avr < 2.0;

3) ���� �л��� ������ �˻��϶�
SELECT *
FROM student
WHERE sname='����';

4) ������ ����� �˻��϶�
SELECT *
FROM professor
WHERE orders='������';

5) ȭ�а� �Ҽ� ������ ����� �˻��϶�
SELECT *
FROM professor
WHERE section='ȭ��';

6) �۰� ������ ������ �˻��϶�
SELECT *
FROM professor
WHERE pname='�۰�';

7) �г⺰�� ȭ�а� �л��� ������ �˻��϶�
SELECT *
FROM student
WHERE major='ȭ��'
ORDER BY syear;

8) 2000�� ������ ������ ������ ������ �����ϼ����� �˻��϶�
SELECT *
FROM professor
WHERE hiredate < '2000/01/01'
ORDER BY hiredate;

9) ��� ������ ���� ������ ������ �˻��϶�
SELECT *
FROM course
WHERE pno IS NULL;

