--1) �������� ������, �Ŀ��� �л��� �˻��϶�
SELECT *
FROM student
WHERE major='����' OR major='����' OR major='�Ŀ�';

--2) ȭ�а��� �ƴ� �л��߿� 1�г� �л��� �˻��϶�
SELECT *
FROM student
WHERE NOT major='ȭ��' AND syear=1;

--3) �����а� 3�г� �л��� �˻��϶�
SELECT *
FROM student
WHERE major='���� ANS syear=3;

--4) ������ 2.0���� 3.0������ �л��� �˻��϶�
SELECT *
FROM student
WHERE avr >= 2.0 AND avr <= 3.0;

--5) ������ �������� ���� �����߿� ������ 3������ ������ �˻��϶�
SELECT *
FROM course
WHERE pno IS NULL AND st_num=3;

--6) ȭ�а� ���õ� ������ ������ 2���� ������ ������ �˻��϶�
SELECT *
FROM course
WHERE st_num <= 2 AND cname LIKE '%ȭ��%';

--7) ȭ�а� �������� �˻��϶�
SELECT *
FROM professor
WHERE section='ȭ��' AND orders='������';

--8) �����а� �л��߿� ���� �縶���� �л��� �˻��϶�
SELECT *
FROM student
WHERE major='ȭ��' AND sname LIKE '��%';

--9) �������� 1995�� ������ �������� �˻��϶�
SELECT * 
FROM professor
WHERE hiredate < '1995/01/01' AND orders='������';

--10) ���� �̸��� ���� 1������ ������ �˻��϶�
SELECT *
FROM professor
WHERE pname LIKE '__';

