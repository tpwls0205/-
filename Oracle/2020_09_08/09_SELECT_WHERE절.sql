--���� �˻�
--SELECT �÷�, �÷�, ...
--FROM ���̺�
--WHERE ����
--ORDER BY �÷�;

--1) ����߿� �޿��� 4000�̻��� ����� �˻��϶�
SELECT *
FROM EMP
WHERE SAL >= 4000;

--2) �̸��� '�迬��'�� ����� ������ �˻��϶�
SELECT *
FROM EMP
WHERE ENAME = '�迬��';

--3) 10�� �μ��� ������ ����� ����� �˻��϶�
--DNO�� Ÿ���� VARCHAR2 �̹Ƿ�
--�˻��� �� �� '10'���� �˻��ؾ� �Ѵ�
--�׷��� �ʰ� ���ڷ� �˻��ϰ� �Ǹ�
--1�ึ�� ����ȯ�� �̷���� �� �񱳿����� �̷������ �ȴ�
--���� ������ ��뷮 ���̺��� ���
--�˻��ӵ��� ũ�� ���̳��� �ȴ�
SELECT *
FROM EMP
WHERE DNO!='10';

--4) ������ 30,000�̻��� ����� �̸��� �˻��϶�
-- ���Ǻ񱳴�(WHERE) ������ �ȵȴ�
-- ������(ORDER BY) ������ �ȴ�
SELECT ENO ���, ENAME �̸�, SAL*12+NVL(COMM,0) ����
FROM EMP
WHERE SAL*12+NVL(COMM,0) >= 30000;

--5) ���ʽ��� 200 ������ ����� �˻��϶�
SELECT ENO ���, ENAME �̸�, COMM ���ʽ�
FROM EMP
WHERE COMM <= 200;

SELECT ENO ���, ENAME �̸�, COMM ���ʽ�
FROM EMP
WHERE NVL(COMM,0) <= 200;

--6) �Ի����� 1996�� ������ ����� ������ �˻��϶�
SELECT ENO ���, ENAME �̸�, HDATE �Ի���
FROM EMP
WHERE HDATE > '1995/12/31';

-- ��¥ ���� ����
ALTER SESSION SET NLS_DATE_FORMAT='YY/MM/DD';
ALTER SESSION SET NLS_DATE_FORMAT='YYYY/MM/DD';

--7) ���ʽ� �÷��� �� ���� ����� �˻��϶�
SELECT ENO ���, ENAME �̸�, COMM ���ʽ�
FROM EMP
WHERE COMM IS NULL;

--8) ���ʽ� �÷��� �� ���� �ƴ� ����� �˻��϶�
SELECT ENO ���, ENAME �̸�, COMM ���ʽ�
FROM EMP
WHERE COMM IS NOT NULL;

