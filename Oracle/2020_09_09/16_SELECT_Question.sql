--1) �۰� ������ �����ϴ� ������ �˻��Ѵ�
SELECT CNAME ���ǰ���
FROM COURSE C , PROFESSOR P
WHERE C.PNO = P.PNO
AND P.PNAME = '�۰�';

--2) ȭ�� ���� ������ �����ϴ� ������ ����� �˻��Ѵ�
SELECT PNAME
FROM COURSE C, PROFESSOR P
WHERE CNAME LIKE '%ȭ��%'
AND C.PNO = P.PNO;

--3) ������ 2������ ����� �̸� �����ϴ� ������ �˻��Ѵ�
SELECT CNAME �����, PNAME ������
FROM COURSE C, PROFESSOR P
WHERE ST_NUM = 2
AND C.PNO = P.PNO;

--4) ȭ�а� ������ �����ϴ� ������ �˻��Ѵ�
SELECT PNAME ������, CNAME �����
FROM COURSE C, PROFESSOR P
WHERE SECTION = 'ȭ��'
AND C.PNO = P.PNO;

--5) ȭ�а� 1�г� �л��� �⸻��� ������ �˻��Ѵ�
SELECT SNAME �л���, S.RESULT ����
FROM STUDENT ST, SCORE S
WHERE SYEAR = 1
AND MAJOR = 'ȭ��'
AND S.SNO = ST.SNO;

--6) �Ϲ�ȭ�� ������ �⸻��� ������ �˻��Ѵ�
SELECT RESULT ����
FROM COURSE C, SCORE S
WHERE CNAME = '�Ϲ�ȭ��'
AND C.CNO = S.CNO;

--7) ȭ�а� 1�г� �л��� �Ϲ�ȭ�� �⸻��� ������ �˻��Ѵ�
SELECT RESULT ����, ST.SNAME �л���
FROM STUDENT ST, COURSE C, SCORE S
WHERE ST.MAJOR = 'ȭ��'
AND ST.SYEAR = 1
AND C.CNAME = '�Ϲ�ȭ��'
AND C.CNO = S.CNO
AND ST.SNO = S.SNO;

--8) ȭ�а� 1�г� �л��� �����ϴ� ������ �˻��Ѵ�
SELECT DISTINCT CNAME �����
FROM STUDENT ST, SCORE S, COURSE C
WHERE ST.SYEAR = 1
AND ST.MAJOR = 'ȭ��'
AND ST.SNO = S.SNO
AND S.CNO = C.CNO;

--9) ����ȭ�� ������ �������� F�� �л��� ����� �˻��Ѵ�
SELECT G.GRADE ������, ST.SNAME �л���
FROM COURSE C, SCGRADE G, SCORE S, STUDENT ST
WHERE CNAME = '����ȭ��'
AND C.CNO = S.CNO
AND S.SNO = ST.SNO
AND S.RESULT BETWEEN G.LOSCORE AND G.HISCORE
AND G.GRADE = 'F';