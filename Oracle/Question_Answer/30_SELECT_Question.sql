1) 3�г� �л��� �а��� ���� ��հ� �л� �� ������ �˻��ϼ���
SELECT major, AVG(avr), STDDEV(avr), VARIANCE(avr)
FROM student
WHERE syear=3
GROUP BY major;

2) ȭ�а� �г⺰ ��� ������ �˻��ϼ���
SELECT syear, AVG(avr)
FROM student
WHERE major='ȭ��'
GROUP BY syear;

3) �� �л��� �⸻��� ����� �˻��ϼ���
SELECT sno, AVG(result)
FROM score
GROUP BY sno;

4) �� �а��� �л� ���� �˻��ϼ���
SELECT major, COUNT(*)
FROM student
GROUP BY major;

5) ȭ�а��� �����а� �л� 4.5 ȯ�� ������ ����� ���� �˻��ϼ���
SELECT major, AVG(avr*4.5/4.0)
FROM student
WHERE major IN ('ȭ��', '����')
GROUP BY major;

6) �������� 10�� �̻� �� ���޺�(������, ������, �α���) ������ ���� 
   �˻��ϼ���
SELECT orders, COUNT(*)
FROM professor
WHERE months_between(sysdate, hiredate) >= 120
GROUP BY orders;
   
7) ����� ȭ���� ���Ե� ������ ������ ������ �˻��ϼ���
SELECT SUM(st_num)
FROM course
WHERE cname LIKE '%ȭ��%';

8) ȭ�а� �л����� �⸻��� ������ ���������� �˻��ϼ���
SELECT s.sno, sname, AVG(result)
FROM score r, student s
WHERE r.sno=s.sno
GROUP BY s.sno, sname
ORDER BY 3 DESC;

SELECT sno, sname, AVG(result)
FROM score
NATURAL JOIN student
GROUP BY sno, sname
ORDER BY 3 DESC;

9) �а��� �⸻��� ����� ���������� �˻��ϼ���
SELECT major, AVG(result)
FROM score r, student score
WHERE r.sno=s.sno
GROUP BY major
ORDER BY 2 DESC;

SELECT major, AVG(result)
FROM student
NATURAL JOIN score
GROUP BY major
ORDER BY 2 DESC;
