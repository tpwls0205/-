--������ �̿��� �˻�
--SELECT �÷� AS "����", �÷� AS "����", ...
--FROM ���̺�;

--1) �� ����� �̸��� �������� �˻��϶�
SELECT eno ���, ename �̸�, job ����
FROM emp;

SELECT eno as ���, ename as �̸�, job as ����
FROM emp;

SELECT eno as "���", ename as "�̸�", job as "����"
FROM emp;

--2) �� ����� �޿��� 1�Ⱓ �����ϴ� �޿��� �˻��϶�
SELECT eno ���, ename �̸�, sal*12 "���� �޿�"
FROM emp;

--3) �� ����� ������ �˻��϶�(12���� �޿� + ���ʽ�(comm))
SELECT eno ���, ename �̸�, sal �޿�, comm ���ʽ�, sal*12+comm ����
FROM emp;

--�����ͺ��̽������� 0�� null�� ���� �ٸ���
--0�� ���� 0�� ��
--null �� ���� �� �� ���� or ���� �������� �ʾҴ��� �ǹ�
--�� ��� 2������ ����� �����ؾ� �Ѵ�
--1) sal*12+comm ���� �����ؼ� null �÷��� ���ԵǾ����� ����� null �� ������ ����
--2) sal*12+NVL(comm, 0)���� �����ؼ� null�� 0���� ġȯ�� �� ������ ����

4) �� ����� ������ �˻��Ѵ�(��, null�� 0���� ġȯ�Ѵ�)
SELECT eno ���, ename �̸�, sal �޿�, comm ���ʽ�, sal*12+NVL(comm,0) ����
FROM emp;