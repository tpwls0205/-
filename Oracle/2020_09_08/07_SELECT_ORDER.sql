--���ĵ� ������ �˻�
--SELECT [DISTINCT | ALL] �÷�, �÷�, ...
--FROM ���̺�
--ORDER BY �÷� [ASC/DESC], �÷� [ASC/DESC] ...;

--1) ����� �̸��� �޿� ������ �˻��϶�
SELECT ENO ���, ENAME �̸�, SAL �޿�
FROM EMP
ORDER BY SAL DESC;

--2) ����� ����� �̸��� ���� ������ �˻��϶�
SELECT ENO ���, ENAME �̸�
FROM EMP
ORDER BY SAL*12+NVL(COMM,0) DESC;

SELECT ENO ���, ENAME �̸�, SAL*12+NVL(COMM,0) ����
FROM EMP
ORDER BY ���� DESC;

SELECT ENO ���, ENAME �̸�, SAL*12+NVL(COMM,0) ����
FROM EMP
ORDER BY 1 DESC;

SELECT ENO ���, ENAME �̸�, SAL*12+NVL(COMM,0) ����
FROM EMP
ORDER BY ENO DESC;

--������ �̿��� ���� �˻�
--3) �������� ����� ������ �˻��Ѵ�
SELECT JOB ����, ENO ���, ENAME �̸�, SAL �޿�
FROM EMP
ORDER BY ����;

--4) �� �μ����� ����� �޿��� �˻��Ѵ�. �� �޿��� ���� �޴� ������� �˻��Ѵ�.
SELECT DNO �μ���ȣ, ENO ���, ENAME �̸�, SAL �޿�
FROM EMP
ORDER BY �μ���ȣ, �޿� DESC;

SELECT DNO �μ���ȣ, ENO ���, ENAME �̸�, SAL �޿�
FROM EMP
ORDER BY �μ���ȣ ASC, �޿� DESC;