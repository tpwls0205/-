1) ���������� �л��� �̸��� �˻��϶�
SELECT avr, sno, sname
FROM student
ORDER BY avr;

2) �а��� ���������� �л��� ������ �˻��϶�
SELECT major, sno, sname, avr
FROM student
ORDER BY major, avr DESC;

3) �г⺰ ���������� �л��� ������ �˻��϶�
SELECT syear, sno, sname, avr
FROM student
ORDER BY syear, avr DESC;

4) �а��� �г⺰�� �л��� ������ ���������� �˻��϶�
SELECT major, syear, sno, sname, avr
FROM student
ORDER BY major, syear, avr DESC;

5) ���������� ���� �̸��� �˻��϶�
SELECT cname, st_num
FROM course
ORDER BY st_num DESC;

6) �� �а����� ������ ������ �˻��϶�
SELECT section, pno, pname, hiredate, orders
FROM professor
ORDER BY section;

7) �������� ������ ������ �˻��϶�
SELECT orders, pno, pname, hiredate, section
FROM professor
ORDER BY orders;

8) �� �а����� ������ ������ �������� ������ �˻��϶�
SELECT section, orders, hiredate, pno, pname
FROM professor
ORDER BY section, orders;

