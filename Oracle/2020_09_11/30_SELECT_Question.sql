--1) 3�г� �л��� �а��� ���� ��հ� �л� �� ������ �˻��ϼ���
SELECT MAJOR �а�, AVG(AVR) ���, VARIANCE(AVR) �л�,
STDDEV(AVR) ǥ������
FROM STUDENT
WHERE SYEAR = 3
GROUP BY MAJOR;

--2) ȭ�а� �г⺰ ��� ������ �˻��ϼ���
SELECT SYEAR �г�, AVG(AVR) "��� ����"
FROM STUDENT
WHERE MAJOR = 'ȭ��'
GROUP BY SYEAR;

--3) �� �л��� �⸻��� ����� �˻��ϼ���
SELECT SNAME �л��̸�, AVG(RESULT)
FROM SCORE
JOIN STUDENT USING(SNO)
GROUP BY SNAME;

SELECT SNAME �л��̸�, AVG(RESULT)
FROM STUDENT ST, SCORE S
WHERE ST.SNO = S.SNO
GROUP BY SNAME;

--4) �� �а��� �л� ���� �˻��ϼ���
SELECT MAJOR �а�, COUNT(SNAME) �л���
FROM STUDENT
GROUP BY MAJOR;

--5) ȭ�а��� �����а� �л� 4.5 ȯ�� ������ ����� ���� �˻��ϼ���
SELECT MAJOR �а�, AVG(AVR/8)*9 ȯ�����
FROM STUDENT
WHERE MAJOR = 'ȭ��'
OR MAJOR = '����'
GROUP BY MAJOR;

--6) �������� 10�� �̻� �� ���޺�(������, ������, �α���) ������ ���� 
--   �˻��ϼ���
SELECT ORDERS ����, COUNT(*) "������ ��"
FROM PROFESSOR
WHERE TO_CHAR(HIREDATE, 'YYYY')+'10' <=  TO_CHAR(SYSDATE, 'YYYY')
GROUP BY ORDERS;

--7) ����� ȭ���� ���Ե� ������ ������ ������ �˻��ϼ���
SELECT SUM(ST_NUM) ����, COUNT(CNAME) �����
FROM COURSE
WHERE CNAME LIKE '%ȭ��%';

--8) ȭ�а� �л����� �⸻��� ������ ���������� �˻��ϼ���
SELECT SNAME �̸�, AVG(RESULT) ����
FROM SCORE
JOIN STUDENT USING(SNO)
WHERE MAJOR = 'ȭ��'
GROUP BY SNAME
ORDER BY AVG(RESULT) DESC;

--9) �а��� �⸻��� ����� ���������� �˻��ϼ���
SELECT MAJOR �а�, AVG(RESULT) ����
FROM SCORE
JOIN STUDENT USING(SNO)
GROUP BY MAJOR
ORDER BY AVG(RESULT) DESC;