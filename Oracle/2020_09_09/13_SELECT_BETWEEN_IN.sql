--BETWEEN..AND ������
--SELECT �÷�, �÷�, ...
--FROM ���̺�
--WHERE �÷� BETWEEN ��1 AND ��2;
--; �ش� �÷� >= ��1 AND <= ��2

--1) �޿��� 1000���� 2000�̳��� ���
SELECT *
FROM EMP
WHERE SAL BETWEEN 1000 AND 2000;

SELECT *
FROM EMP
WHERE SAL >= 1000 AND SAL <= 2000;

--2) 10��, 20�� �μ� ���
SELECT *
FROM EMP
WHERE DNO BETWEEN '10' AND '20';

--3) 1992�⿡�� 1996�� ���̿� �Ի��� ����� �˻��϶�
--'1992/01/01' => '1992/01/01:0��0��0��'
--'1996/12/31' => '1996/12/31:0��0��0��'
--��ڸ� '1996/12/31:0��0��1��'�� �Ի��� ����� ���ܵȴ�
SELECT *
FROM EMP
WHERE HDATE BETWEEN '1992/01/01' AND '1996/12/31'
ORDER BY HDATE;

ALTER SESSION SET nls_date_format='YYYY/MM/DD:HH24:MI:SS';

SELECT *
FROM EMP
WHERE HDATE BETWEEN '1992/01/01:00:00:00' AND '1996/12/31:23:59:59'
ORDER BY HDATE;

--4) �޿��� 2000���� 1000 ������ ����� �˻��϶�
SELECT *
FROM EMP
WHERE SAL BETWEEN 2000 AND 1000;

-- BETWEEN�� ������ �ݵ�� ���� �;��Ѵ�
SELECT *
FROM EMP
WHERE SAL BETWEEN 1000 AND 2000;

--IN ������
--SELECT �÷�, �÷�
--FROM ���̺�
--WHERE �÷� IN (��1, ��2, ...)
--ORDER BY �÷�, ...;
--������ �� �߿� ��ġ�ϴ� ���� �ϳ��� ������ �˻�

--4) �����̳� ���� ������ ����ϴ� ���
SELECT *
FROM EMP
WHERE JOB IN ('����','ȸ��')
ORDER BY JOB;

--5) 10, 20�� �μ����
SELECT *
FROM EMP
WHERE DNO IN ('10', '20')
ORDER BY DNO;

SELECT *
FROM EMP
WHERE DNO='10' OR DNO='20'
ORDER BY DNO;


