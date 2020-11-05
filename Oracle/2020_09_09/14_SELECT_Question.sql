--1) ������ 3.0���� 4.0������ �л��� �˻��϶�
SELECT *
FROM STUDENT
WHERE AVR BETWEEN 3.0 AND 4.0
ORDER BY AVR;

--2) 1994�⿡�� 1995����� ������ ������ ����� �˻��϶�
SELECT *
FROM PROFESSOR
WHERE HIREDATE BETWEEN '1994/01/01' AND '1995/12/31'
ORDER BY HIREDATE;

--3) ȭ�а��� �����а�, �����а� �л��� �˻��϶�
SELECT *
FROM STUDENT
WHERE MAJOR IN ('ȭ��','����','����')
ORDER BY MAJOR;

--4) �������� �������� �˻��϶�
SELECT *
FROM PROFESSOR
WHERE ORDERS IN ('������','������')
ORDER BY ORDERS;

--5) �������� 1����, 2������ ������ �˻��϶�
SELECT *
FROM COURSE
WHERE ST_NUM IN (1, 2)
ORDER BY ST_NUM;

--6) 1, 2�г� �л� �߿� ������ 2.0���� 3.0������ �л��� �˻��϶�
SELECT *
FROM STUDENT
WHERE SYEAR IN (1, 2)
AND AVR BETWEEN 2.0 AND 3.0
ORDER BY SYEAR;

--7) ȭ��, �����а� �л� �� 1, 2 �г� �л��� ���������� �˻��϶�
SELECT *
FROM STUDENT
WHERE MAJOR IN ('ȭ��', '����')
AND SYEAR IN (1, 2)
ORDER BY AVR DESC;