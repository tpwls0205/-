--1) �۰� ������ �����ϴ� ������ �˻��Ѵ�
SELECT PNAME ������, CNAME �����
FROM PROFESSOR
NATURAL JOIN COURSE
WHERE PNAME = '�۰�';

--2) ȭ�� ���� ������ �����ϴ� ������ ����� �˻��Ѵ�
SELECT PNAME �������
FROM PROFESSOR
NATURAL JOIN COURSE
WHERE SECTION LIKE '%ȭ��%';

--3) ������ 2������ ����� �̸� �����ϴ� ������ �˻��Ѵ�
SELECT CNAME �����, PNAME ������
FROM COURSE
NATURAL JOIN PROFESSOR
WHERE ST_NUM = 2;

--4) ȭ�а� ������ �����ϴ� ������ �˻��Ѵ�
SELECT PNAME ������, CNAME �����
FROM PROFESSOR
NATURAL JOIN COURSE
WHERE SECTION = 'ȭ��';

--5) ȭ�а� 1�г� �л��� �⸻��� ������ �˻��Ѵ�
SELECT SNAME �л��̸�, RESULT �⸻����
FROM SCORE
NATURAL JOIN STUDENT
WHERE MAJOR = 'ȭ��'
AND SYEAR = 1;

--6) �Ϲ�ȭ�� ������ �⸻��� ������ �˻��Ѵ�
SELECT CNAME �����, RESULT �⸻����
FROM SCORE
NATURAL JOIN COURSE
WHERE CNAME = '�Ϲ�ȭ��';

--7) ȭ�а� 1�г� �л��� �Ϲ�ȭ�� �⸻��� ������ �˻��Ѵ�
SELECT SNAME �̸�, RESULT ����
FROM SCORE
JOIN COURSE USING (CNO)
JOIN STUDENT USING (SNO)
WHERE SYEAR = 1
AND MAJOR = 'ȭ��'
AND CNAME = '�Ϲ�ȭ��';

--8) ȭ�а� 1�г� �л��� �����ϴ� ������ �˻��Ѵ�
SELECT DISTINCT CNAME ��������
FROM SCORE
JOIN COURSE USING (CNO)
JOIN STUDENT USING (SNO)
WHERE SYEAR = 1
AND MAJOR = 'ȭ��';
