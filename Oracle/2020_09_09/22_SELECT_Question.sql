--1) �� ������ ������ ��� ������ �������� �˻��϶�
SELECT PNAME ��米��, CNAME �����
FROM COURSE
JOIN PROFESSOR USING(PNO);

--2) ȭ�а� �л��� �⸻��� ������ ��� �˻��϶�
SELECT SNAME �̸�, MAJOR �а�, RESULT ����
FROM STUDENT
NATURAL JOIN SCORE
WHERE MAJOR = 'ȭ��';

--3) ����ȭ�а��� �������� �⸻��� ���������� �˻��϶�
SELECT CNAME �����, SNAME �л��̸�, RESULT ��������
FROM SCORE
JOIN COURSE USING(CNO)
JOIN STUDENT USING(SNO)
WHERE CNAME = '����ȭ��';

--4) ȭ�а� �л��� �����ϴ� ������ ����ϴ� ������ ����� �˻��϶�
SELECT DISTINCT PNAME ������, CNAME �����, MAJOR �а�
FROM SCORE
JOIN STUDENT USING(SNO)
JOIN COURSE USING(CNO)
JOIN PROFESSOR USING(PNO)
WHERE MAJOR = 'ȭ��'
ORDER BY PNAME;

--5) ��� ������ ��ܰ� ��� ������ �˻��Ѵ�
SELECT PNAME ��米��, CNAME �����
FROM COURSE
RIGHT JOIN PROFESSOR USING(PNO);

--6) ��� ������ ��ܰ� ��� ������ �˻��Ѵ�(�� ��� ���� ���� �˻��Ѵ�)
SELECT PNAME ��米��, CNAME �����
FROM COURSE
FULL JOIN PROFESSOR USING(PNO);