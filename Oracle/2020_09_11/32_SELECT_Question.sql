--1) ȭ�а��� �����ϰ� �л����� ���� ����� �˻��ϼ���
SELECT SNAME �л��̸�, AVG(AVR) �������
FROM STUDENT
WHERE MAJOR != 'ȭ��'
GROUP BY SNAME;

--2) ȭ�а��� ������ �� �а��� ��� ���� �߿� ������ 2.0 �̻��� 
--������ �˻��ϼ���
SELECT MAJOR �а�, AVG(AVR) �������
FROM STUDENT
WHERE MAJOR != 'ȭ��'
GROUP BY MAJOR
HAVING AVG(AVR) >= 2.0;

--3) �⸻��� ����� 60�� �̻��� �л��� ������ �˻��ϼ���(�й��� �⸻��� ���)
SELECT SNO �й�, AVG(RESULT)
FROM STUDENT
JOIN SCORE USING(SNO)
GROUP BY SNO
HAVING AVG(RESULT) >= 60;

--4) ���� �������� 3���� �̻��� ������ ������ �˻��ϼ���(������ȣ, �̸��� ��� ������)
SELECT PNO ������ȣ, PNAME �̸�, SUM(ST_NUM) "��� ������"
FROM PROFESSOR
NATURAL JOIN COURSE
GROUP BY PNO, PNAME
HAVING SUM(ST_NUM) >= 3;