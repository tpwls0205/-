--SELECT ���� �̿��� ���̺� �˻� // Ctrl+/ �ּ�
/*
SELECT [�÷�, �÷�, ... | *]
FORM ���̺�;
*/

--1) ���̺� ���� �˻�
DESC emp;

--2) ���� ��Ű��(�����)�� ��� ���̺� �˻�
SELECT * FROM tab;

--3) emp ���̺��� ������ �˻��϶�
DESC emp;

--4) emp ���̺��� ��� ������ �˻��϶�
SELECT * FROM emp;

--5) dept ���̺��� ������ �˻��϶�
DESC dept;

--6) dept ���̺��� ��� ������ �˻��϶�
SELECT * FROM dept;

DESC emp;
--7) ����� �̸��� ������ �˻��϶�
SELECT eno, ename, job
FROM emp;

--8) ����� ���, �̸�, �޿��� �˻��϶�
SELECT eno, ename, sal
FROM emp;

--9) 2+3�� ����϶�
SELECT 2+3
FROM dual;