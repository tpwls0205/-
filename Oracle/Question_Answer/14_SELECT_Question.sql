1) ������ 3.0���� 4.0������ �л��� �˻��϶�
SELECT *
FROM student
WHERE avr BETWEEN 3 AND 4;

2) 1994�⿡�� 1995����� ������ ������ ����� �˻��϶�
SELECT *
FROM professor
WHERE hiredate BETWEEN '1994/01/01' AND '1995/12/31';

3) ȭ�а��� �����а�, �����а� �л��� �˻��϶�
SELECT *
FROM student
WHERE major IN ('����, 'ȭ��', '����');

4) �������� �������� �˻��϶�
SELECT *
FROM professor
WHERE orders IN ('������', '������');

5) �������� 1����, 2������ ������ �˻��϶�
SELECT *
FROM course
WHERE st_num IN (1, 2);

6) 1, 2�г� �л� �߿� ������ 2.0���� 3.0������ �л��� �˻��϶�
SELECT *
FROM student
WHERE syear IN (1, 2)
AND avr BETWEEN 2 AND 3;

7) ȭ��, �����а� �л� �� 1, 2 �г� �л��� ���������� �˻��϶�
SELECT *
FROM student
WHERE major IN ('����', 'ȭ��')
AND syear IN (1, 2)
ORDER BY major, syear, avr DESC;

