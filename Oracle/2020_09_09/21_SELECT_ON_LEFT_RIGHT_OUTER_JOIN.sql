--<ON ���� �̿��� ����>
--SELECT ���̺�1.�÷�, ..., ���̺�2.�÷�, ...
--FROM ���̺�1
--JOIN ���̺�2 ON ��������
--WHERE �˻�����;
--A) ��� ������ ������ ǥ���� �� �ִ�
--    (�/�� ����)
    
--1) �� ����� �ٹ��μ��� �˻��Ѵ�
SELECT ENO ���, ENAME �̸�, D.DNO �μ���ȣ, DNAME �μ���
FROM EMP E
JOIN DEPT D ON E.DNO = D.DNO;

SELECT ENO ���, ENAME �̸�, D.DNO �μ���ȣ, DNAME �μ���
FROM EMP E, DEPT D
WHERE E.DNO = D.DNO;

SELECT ENO ���, ENAME �̸�, DNO �μ���ȣ, DNAME �μ���
FROM EMP E
NATURAL JOIN DEPT;

SELECT ENO ���, ENAME �̸�, DNO �μ���ȣ, DNAME �μ���
FROM EMP E
JOIN DEPT USING (DNO);

--2) ���� ������ ����ϴ� ����� �޿� ����� �˻��Ѵ�.
SELECT ENO ���, ENAME �̸�, JOB ����, GRADE �޿����
FROM EMP
JOIN SALGRADE ON SAL BETWEEN LOSAL AND HISAL
WHERE JOB = '����';

--3) ������ �μ���� �޿� ����� �˻��Ѵ�
SELECT ENO ���, ENAME �̸�, DNAME �μ���, GRADE �޿����
FROM EMP
JOIN DEPT USING(DNO)
JOIN SALGRADE ON SAL BETWEEN LOSAL AND HISAL;

SELECT ENO ���, ENAME �̸�, DNAME �μ���, GRADE �޿����
FROM EMP E
JOIN DEPT D ON E.DNO = D.DNO 
JOIN SALGRADE ON SAL BETWEEN LOSAL AND HISAL;

--<�¿� �ܺ� ����(LEFT RIGHT OUTER JOIN)>
--+ ��ȸ�� �̿��ϴ� �ܺ������� �ٸ� ǥ����
--������ �ܺ������� ���ʿ��� +�� ���̴µ�
--���⿡���� ��� +�� �߰��� �Ͱ� ������ ǥ���� �����ϴ�
--SELECT ���̺�1.�÷�, ... ���̺�2.�÷�, ...
--FROM ���̺�1
--[LEFT|RIGHT|FULL] [OUTER] JOIN ���̺�2 [ON ��������|USING(�����÷�)]
--WHERE �˻�����;
--A) LEFT : '���̺�1'�� ���� ���̺��̶� �θ��� ���� ���̺� �������ǰ�
--          ��ġ���� ���� �൵ �˻��� �����Ѵ�.
--B) RIGTH : '���̺�2'�� ������ ���̺��̶� �θ��� ������ ���̺�
--            �������ǰ� ��ġ���� ���� �൵ �˻��� �����Ѵ�.
--C) FULL : ���� ���̺� ��ο��� ���� ���ǿ� ��ġ���� ���� ���� �˻���
--          �����Ѵ�. ���� (+) ��ȣ�� �̿��� �ܺ��������δ� �Ұ����� ǥ���̴�
--D) ON ���̳� USING ���� ��� ����� �� �ִ�.

--4) ����� �̸��� �Ҽ� �μ��� �˻��϶�    
SELECT ENO ���, ENAME �̸�, DNO �μ���ȣ, DNAME �μ���
FROM EMP
RIGHT JOIN DEPT USING(DNO);

SELECT ENO ���, ENAME �̸�, DNO �μ���ȣ, DNAME �μ���
FROM EMP
RIGHT OUTER JOIN DEPT USING(DNO);

SELECT ENO ���, ENAME �̸�, DNO �μ���ȣ, DNAME �μ���
FROM EMP
LEFT JOIN DEPT USING(DNO);

SELECT ENO ���, ENAME �̸�, DNO �μ���ȣ, DNAME �μ���
FROM EMP
FULL JOIN DEPT USING(DNO);