--1) ��� �л��� ������ 4.5���� �������� �����ϼ���
SELECT AVR FROM STUDENT;
UPDATE STUDENT SET AVR = (AVR/8)*9;

--2) ��� ������ �������ڸ� 100�� ������ �����ϼ���
SELECT HIREDATE FROM PROFESSOR;
UPDATE PROFESSOR SET HIREDATE = HIREDATE - 100;

--3) ȭ�а� 2�г� �л��� ������ �����ϼ���
SELECT * FROM STUDENT;
DELETE FROM STUDENT
WHERE MAJOR = 'ȭ��'
AND SYEAR = 2;

--4) �������� ������ �����ϼ���
SELECT * FROM PROFESSOR;
DELETE FROM PROFESSOR
WHERE ORDERS = '������';