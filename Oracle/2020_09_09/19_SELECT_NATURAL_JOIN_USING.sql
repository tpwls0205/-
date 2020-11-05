--<�ڿ� ����(Natural Join)>
--SELECT �÷�, ...
--FROM ���̺�1
--NATURAL JOIN ���̺�2
--WHERE �˻�����;
--A) ������ �̸�/Ÿ���� �÷��� ������ ��
--    ���������� ������� �ʾƵ�
--    �ڵ����� ã�Ƽ� ������ ���ش�
--B) ���� �÷��� �ݵ�� �ϳ� �����ؾ� �Ѵ�
--    �� �̻��� ���� ����� �� ����
--    �̷� ���� USING ���� ����� �� �ִ�

--1) �ڿ� �������� �� ����� �ٹ� �μ��� �˻��϶�
SELECT ENO ���, ENAME �̸�, DNO �μ���ȣ, DNAME �μ���
FROM EMP
NATURAL JOIN DEPT;

SELECT ENO ���, ENAME �̸�, E.DNO �μ���ȣ, DNAME �μ���
FROM EMP E, DEPT D
WHERE E.DNO = D.DNO;

--2) '����'���� �ٹ��ϴ� ������ ����� �˻��϶�(�μ���ȣ�� �μ��� �˻�)
SELECT LOC �ٹ�ó, DNO �μ���ȣ, DNAME �μ���
        ,ENO ���, ENAME �̸�
FROM EMP
NATURAL JOIN DEPT
WHERE LOC = '����';

--<USING ��>
--SELECT �÷�, �÷�, ...
--FROM ���̺�1
--JOIN ���̺�2 USING (���� �÷�)
--WHERE �˻�����;
--3) USING ���� ����� JOIN���� �� ����� �ٹ� �μ��� �˻��϶�
SELECT ENO ���, ENAME �̸�, DNO �μ���ȣ, DNAME �μ���
FROM EMP 
JOIN DEPT USING (DNO);

--4) '����'���� �ٹ��ϴ� ������ ����� �˻��϶�(�μ���ȣ�� �μ��� �˻�)
SELECT LOC �ٹ�ó, DNO �μ���ȣ, DNAME �μ���,
        ENO ���, ENAME �̸�
FROM DEPT
JOIN EMP USING(DNO)
WHERE LOC='����';

--5) ȭ�а� 1�г� �л����� ����ȭ�� ������ �˻��϶�
--ȭ�а� 1�г� �л� : STUDENT
--����ȭ�� : COURSE
--���� : SCORE
SELECT SNO �й�, SNAME �̸�, MAJOR �а�, CNAME �����, RESULT ����
FROM STUDENT
JOIN SCORE USING (SNO)
JOIN COURSE USING (CNO)
WHERE MAJOR = 'ȭ��'
AND SYEAR = 1
AND CNAME = '����ȭ��'
ORDER BY RESULT DESC;

SELECT SNO �й�, SNAME �̸�, MAJOR �а�, CNAME �����, RESULT ����
FROM STUDENT
NATURAL JOIN SCORE
NATURAL JOIN COURSE
WHERE MAJOR = 'ȭ��'
AND SYEAR = 1
AND CNAME = '����ȭ��'
ORDER BY RESULT DESC;

SELECT ST.SNO �й�, SNAME �̸�, MAJOR �а�, CNAME �����, RESULT ����
FROM STUDENT ST, COURSE C, SCORE R
WHERE ST.SNO = R.SNO AND C.CNO = R.CNO
AND MAJOR = 'ȭ��'
AND SYEAR = 1
AND CNAME = '����ȭ��'
ORDER BY RESULT DESC;