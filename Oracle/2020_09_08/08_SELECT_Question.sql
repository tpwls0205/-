--1) ���������� �л��� �̸��� �˻��϶�
SELECT SNO �������, SNAME �̸�, AVR ����
FROM STUDENT
ORDER BY AVR DESC;

--2) �а��� ���������� �л��� ������ �˻��϶�
SELECT SNO �������, SNAME �̸�, MAJOR �а�, AVR ����
FROM STUDENT
ORDER BY �а�, ���� DESC;

--3) �г⺰ ���������� �л��� ������ �˻��϶�
SELECT SNO �������, SNAME �̸�, SYEAR �г�, AVR ����
FROM STUDENT
ORDER BY �г�, ���� DESC;

--4) �а��� �г⺰�� �л��� ������ ���������� �˻��϶�
SELECT SNO �������, SNAME �̸�, MAJOR �а�, SYEAR �г�
FROM STUDENT
ORDER BY �а�, �г�;

--5) ���������� ���� �̸��� �˻��϶�
SELECT AVR ����, MAJOR ����
FROM STUDENT
ORDER BY ���� DESC, ���� ASC;

--6) �� �а����� ������ ������ �˻��϶�
SELECT SECTION �а�, ORDERS ����, PNAME �̸�
FROM PROFESSOR
ORDER BY �а�;

--7) �������� ������ ������ �˻��϶�
SELECT SECTION �а�, ORDERS ����, PNAME �̸�
FROM PROFESSOR
ORDER BY ����;

--8) �� �а����� ������ ������ �������� ������ �˻��϶�
SELECT SECTION �а�, ORDERS ����, PNAME �̸�, HIREDATE ��������
FROM PROFESSOR
ORDER BY ��������;

