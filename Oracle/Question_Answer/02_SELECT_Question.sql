--1)student ���̺� ������ �˻��ض�
DESC student;

--2)course ���̺� ������ �˻��ض�
DESC course;

--3)professor ���̺� ������ �˻��ض�
DESC professor;

--4)score ���̺� ������ �˻��ض�
DESC score;

--5) ��� �л��� ������ �˻��ض�
SELECT * 
FROM student;

--7) ��� ������ ������ �˻��ض�
SELECT *
FROM course;

--8) �⸻��� ���������� �˻��ض�
SELECT *
FROM score;

--9) �л����� �а��� �г��� �˻��ض�
SELECT sno, sname, major, syear
FROM student;

--10) �� ������ �̸��� ������ �˻��ض�
SELECT cno, cname, result 
FROM course;

--11) ��� ������ ������ �˻��ض�
SELECT pno, pname, orders
FROM professor;
