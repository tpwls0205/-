<�׷��Լ��� HAVING ��>
; �׷��Լ��� ������ ������ WHERE ���� ����� �� ����
  �׷��� HAVING ���� ����ؾ� �Ѵ�

1) ���̺��� SAL ���� ������ WHERE SAL >= 3000�� ���� �����Ѵ�
SELECT SAL
FROM EMP
WHERE SAL >= 3000;

2) �μ��� ���
--GROUP BY DNO -> ROUND(AVG(SAL)) -> ROUND(AVG(SAL)) >= 3000
SELECT ROUND(AVG(SAL))
FROM EMP
GROUP BY DNO;

3) ������ ���
SELECT ROUND(AVG(SAL))
FROM EMP
GROUP BY JOB;

4) �μ��� �޿� ����� 3õ �̸��� �μ��� �μ���ȣ�� ��� �޿��� �˻��϶�
SELECT DNO �μ�, ROUND(AVG(SAL))
FROM EMP
GROUP BY DNO
HAVING AVG(SAL) < 3000;

5) �μ��� �ο����� ����ϼ���(��, ������ ������ �ƴ� �ο���)
JOB�� �Ϲ� �÷� �����̹Ƿ� HAVING ���� ����� �� ����
SELECT DNO �μ�, COUNT(*)
FROM EMP
GROUP BY DNO
HAVING JOB != '����';

JOB �� WHERE ���� ������ �ο��ؾ� �Ѵ�
SELECT DNO �μ�, COUNT(*)
FROM EMP
WHERE JOB != '����'
GROUP BY DNO;

DNO�� �Ϲ� �÷������� GROUP BY DNO�� ����
�׷��Լ��� ���̴� �Ϲ��÷��̹Ƿ�
�̶��� HAVING ���� DNO�� ����� �� �ִ�
�׷��� DNO�� WHERE ���� ������ �ִ� ���� ��Ģ���� �Ѵ� 
SELECT DNO �μ�, COUNT(*)
FROM EMP
GROUP BY DNO
HAVING DNO != '10';

6) �׷� ��� �÷��� �˻�
DNO���� �׷��� ���̰� �ȴ�
SELECT DNO, COUNT(*) �ο���
FROM EMP
GROUP BY DNO;

DNO���� ���̵� ���������� DNO���� JOB�׷����� ������ ���
SELECT DNO, JOB, COUNT(*) �ο���
FROM EMP
WHERE JOB != '����'
GROUP BY DNO, JOB;
--HAVING JOB != '����';