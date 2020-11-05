--<����ΰ� ������>
--SELECT ���̺�1.�÷�, ... ���̺�2.�÷�, ...
--FROM ���̺�1, ���̺�2, ...
--WHERE ��������
--AND �Ϲ�����
--A) �������ǿ� '='�� ����ϴ� ���� �����
--   �ε�ȣ�� ����ϴ� ���� �������̶� �Ѵ�

--1) �� ����� �ٹ� �μ��� �˻��Ѵ�
SELECT EMP.ENO ���, EMP.ENAME �̸�, EMP.DNO �μ���ȣ,
DEPT.DNO �μ���ȣ, DEPT.DNAME �μ���
FROM EMP, DEPT
WHERE DEPT.DNO = EMP.DNO;

SELECT ENO ���, ENAME �̸�, EMP.DNO �μ���ȣ,
DEPT.DNO �μ���ȣ, DNAME �μ���
FROM EMP, DEPT
WHERE DEPT.DNO = EMP.DNO;

--2) �λ꿡�� �ٹ��ϴ� ������ ����� �˻��Ѵ�(�μ���ȣ�� �μ��� �˻�)
SELECT LOC �ٹ�ó, DEPT.DNO �μ���ȣ, DNAME �μ���, ENO ���, ENAME �̸�
FROM DEPT, EMP
WHERE DEPT.DNO = EMP.DNO
AND LOC='�λ�';

SELECT LOC �ٹ�ó, D.DNO �μ���ȣ, DNAME �μ���, ENO ���, ENAME �̸�
FROM DEPT D, EMP E
WHERE D.DNO = E.DNO
AND LOC='�λ�';

--�� ����
--3) �� ������ �޿� ����� �˻��϶�
SELECT ENO ���, ENAME �̸�, SAL �޿�, GRADE ���
FROM EMP, SALGRADE
WHERE SAL BETWEEN LOSAL AND HISAL
ORDER BY GRADE;

SELECT ENO ���, ENAME �̸�, SAL �޿�, GRADE ���
FROM EMP, SALGRADE
WHERE SAL >= LOSAL AND SAL <= HISAL
ORDER BY GRADE;

--4) �� ������ �޿��� 10% �λ��� ��� �޿� ����� �˻��Ѵ�
SELECT ENO ���, ENAME �̸�, SAL * 1.1 "�λ�� �޿�", GRADE ���
FROM EMP, SALGRADE
WHERE SAL * 1.1 BETWEEN LOSAL AND HISAL
ORDER BY GRADE;

--5) �߸��� ���ι���
--���������� ���Եǰų� �߸� ������ ����ϸ� 
--��� ���� 1:1�� ������ �߸��� �����(Catersian Product)��
--��� �ȴ�
--���� ����(Cross Join)�� �Ϲ������� �߸��� ����̴�
--dept�� 7�� ���
--emp�� 15�� ���� ��� 1:1 ������ ���̴�
SELECT D.DNO, DNAME, E.DNO, ENAME
FROM DEPT D, EMP E;
