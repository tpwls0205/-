--1) �������� ������, �Ŀ��� �л��� �˻��϶�
SELECT *
FROM STUDENT
WHERE MAJOR = '����'
OR MAJOR = '����'
OR MAJOR = '�Ŀ�';

--2) ȭ�а��� �ƴ� �л��߿� 1�г� �л��� �˻��϶�
SELECT *
FROM STUDENT
WHERE MAJOR != 'ȭ��'
AND SYEAR = 1;

--3) �����а� 3�г� �л��� �˻��϶�
SELECT *
FROM STUDENT
WHERE MAJOR = '����'
AND SYEAR = 3;

--4) ������ 2.0���� 3.0������ �л��� �˻��϶�
SELECT *
FROM STUDENT
WHERE AVR >= 2.0
AND AVR < 3.0;

--5) ������ �������� ���� �����߿� ������ 3������ ������ �˻��϶�
SELECT *
FROM COURSE
WHERE PNO IS NULL
AND ST_NUM = 3;

--6) ȭ�а� ���õ� ������ ������ 2���� ������ ������ �˻��϶�
SELECT *
FROM COURSE
WHERE CNAME LIKE '%ȭ��%'
AND ST_NUM <= 2;

--7) ȭ�а� �������� �˻��϶�
SELECT *
FROM PROFESSOR
WHERE SECTION = 'ȭ��'
AND ORDERS = '������';

--8) �����а� �л��߿� ���� �縶���� �л��� �˻��϶�
SELECT *
FROM STUDENT
WHERE MAJOR = '����'
AND SNAME LIKE '�縶%';

--9) �������� 1995�� ������ �������� �˻��϶�
SELECT *
FROM PROFESSOR
WHERE HIREDATE < '1996/01/01'
AND ORDERS = '������';

--10) ���� �̸��� ���� 1������ ������ �˻��϶�
SELECT *
FROM PROFESSOR
WHERE PNAME LIKE '__';