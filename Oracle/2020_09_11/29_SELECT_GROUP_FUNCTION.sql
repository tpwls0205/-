<�׷� �Լ�>
; ������� ���� ���� ���Ǵ� �Լ�
���� ���� ���� �࿡�� ���ǰų� �����ϴ� ���� �����ϴ� �Լ�
A)
MAX : ���� �߿� �ִ� ���� ��ȯ�Ѵ�
      MAX(�÷�)
MIN : ���� �߿� �ּ� ���� ��ȯ�Ѵ�
      MIN(�÷�)
AVG : ��� ���� ����Ѵ�
      AVG(�÷�)
COUNT : ��ȯ�� ���� ���� ����Ѵ�
      COUNT(�÷�|*)
SUM : �հ踦 ����Ѵ�
      SUM(�÷�)
STDDEV : ǥ�������� ����Ѵ�
      STDDEV(�÷�)
VARIANCE : �л��� ����Ѵ�
      VARIANCE(�÷�)
B) 
  NULL ���� ���õȴ�
  �ݵ�� �� �ϳ��� ������ ��ȯ�Ѵ�
  GROUP BY ���� ���� �Ϲ� �÷��� ����� �� ����.
  
--1) ����� �޿� ����� �˻��Ѵ�.
SELECT AVG(SAL) ��ձ޿�, ROUND(AVG(SAL)) ��ձ޿�
FROM EMP;

--2) ����鿡�� ���޵� ���ʽ� ���հ� ���ʽ� ����� �˻��ϼ���
SELECT SUM(COMM) �Ѿ�, ROUND(AVG(COMM)) ���, 
COUNT(COMM) �����ο�,
ROUND(AVG(NVL(COMM,0))) ȯ�����, COUNT(*) ��ü�ο�
FROM EMP;

SELECT COUNT(*)
FROM EMP
WHERE COMM IS NOT NULL;

SELECT COUNT(*)
FROM EMP
WHERE COMM IS NULL;

SELECT COUNT(*)
FROM EMP;

<�׷� �Լ��� GROUP BY ��>

3) ��� �޿��� ��� ������ �˻��ϼ���
SELECT ROUND(AVG(SAL)) ��ձ޿�,
ROUND(AVG(SAL*12+NVL(COMM,0))) ��տ���
FROM EMP;

4) �μ��� ��� �޿��� ��� ������ �˻��ϼ���
SELECT DNO, ROUND(AVG(SAL)) ��ձ޿�,
ROUND(AVG(SAL*12+NVL(COMM,0))) ��տ���
FROM EMP;

ī��θ�Ƽ�� ���̰� �־ ������ �߻��Ѵ�
ī��θ�Ƽ(Cadinality) : ��� ���� ����

14���� ����� ���´�
SELECT DNO
FROM EMP;

1���� ����� ���´�
SELECT ROUND(AVG(SAL)) ��ձ޿�,
ROUND(AVG(SAL*12+NVL(COMM,0))) ��տ���
FROM EMP;

5) �μ��� ��� �޿��� ��� ������ �˻��ϼ���
�μ��� : GROUP BY DNO
�׷��Լ��� �Բ� ���Ǵ� �Ϲ� �÷���
�ݵ�� GROUP BY ���� ���Ǿ�� �Ѵ�
SELECT DNO, ROUND(AVG(SAL)) ��ձ޿�,
ROUND(AVG(SAL*12+NVL(COMM,0))) ��տ���
FROM EMP
GROUP BY DNO;

6) ������ ��� �޿��� ��� ������ �˻��ϼ���
SELECT JOB, ROUND(AVG(SAL)) ��ձ޿�,
ROUND(AVG(SAL*12+NVL(COMM,0))) ��տ���
FROM EMP
GROUP BY JOB;

7) �μ��� ��տ����� ���ϼ���(�μ���ȣ�� �μ������ ����ϼ���)
SELECT D.DNO, DNAME, ROUND(AVG(SAL*12+NVL(COMM,0))) ��տ���
FROM DEPT D, EMP E
WHERE D.DNO = E.DNO
GROUP BY D.DNO, DNAME;

8) �μ��� �޿� ����� �ִ밪�� �ּҰ��� �˻��ϼ���
GROUP BY DNO�� ���� DNO�� ī��θ�Ƽ�� 7���̴�
�׸��� GROUP BY DNO�� �Բ� ���Ǵ� AVG(SAL)�� ī��θ�Ƽ�� 7���̴�
�׷��� MAX(AVG(SAL))�� �μ��߿� �ִ밪�� �����ϴ� ���̹Ƿ�
ī��θ�Ƽ�� 1���̴�
�׷��Ƿ� �Ʒ��� SQL ���� ī��θ�Ƽ�� ����ġ�� ���� ������ �߻��Ѵ�
�׷��� �� ������ '��������'�� �̿��ؾ� �Ѵ�
SELECT DNO, MAX(AVG(SAL)) �ִ�, MIN(AVG(SAL)) �ּ�
FROM EMP
GROUP BY DNO;