<���� ���� - ���� ��, ���� ��>
A) ���� �� : ���� �� ���� �˻�
   ���� �� ���������� ������ ������ ��� �����ڰ� �ٸ���
   ���� ���� =, != �� ����Ѵ�
   ���� ���� IN : �˻��� �� �߿� �ϳ��� ��ġ�ϸ� ��
           ANY : �˻��� �� �߿� ������ �ϳ� �̻� ������ ��
           ALL : �˻��� ����� ��� ���ǿ� ������ ��

1) 20�� �μ������ ������ �����ڷκ��� �����޴� ����� �˻��ϼ���
SELECT *
FROM EMP
WHERE MGR IN (SELECT MGR
              FROM EMP
              WHERE DNO = '20')
AND DNO != '20';

2) 10�� �μ����麸�� �޿��� ���� ����� �˻��ϼ���
SELECT ENO, ENAME, DNO
FROM EMP
WHERE SAL < ALL(SELECT SAL
            FROM EMP
            WHERE DNO = '10')
AND DNO!='10';

SELECT ENO, ENAME, DNO
FROM EMP
WHERE SAL < (SELECT MIN(SAL)
            FROM EMP
            WHERE DNO = '10')
AND DNO!='10';

3) 20�� �μ������ ���ʽ��� ���� ����� �˻��ϼ���
SELECT ENO, ENAME, DNO, COMM
FROM EMP
WHERE COMM IN (SELECT COMM
              FROM EMP
              WHERE DNO = '20')
AND DNO != '20';         

--NULL �� ���Ե� ���� 0���� ġȯ���� ��������
SELECT ENO, ENAME, DNO, COMM
FROM EMP
WHERE NVL(COMM, 0) IN (SELECT NVL(COMM, 0)
              FROM EMP
              WHERE DNO = '20')
AND DNO != '20';

<���� �� ��������>
; ���� �� �÷� �׸��� �˻��Ǵ� ��
; IN �����ڸ� ����Ѵ�

4)���ϴð� ������ �������� ������ �����鼭 ������ ���� ����� �˻��ϼ���
���߿��� ��� IN�� ����ϸ� ��� ���� �����Ǵ� ��츦 ã�´�
SELECT ENO, ENAME , MGR, JOB
FROM EMP
WHERE (MGR, JOB) IN (SELECT MGR, JOB
                    FROM EMP
                    WHERE ENAME = '���ϴ�')
AND ENAME != '���ϴ�';    

--�Ʒ��� �� ������ ���� �ƴϴ�
SELECT ENO, ENAME, MGR, JOB
FROM EMP
WHERE MGR IN (SELECT MGR
            FROM EMP
            WHERE ENAME = '���ϴ�')
AND JOB IN (SELECT JOB
            FROM EMP
            WHERE ENAME = '���ϴ�')
AND ENAME != '���ϴ�';

5) �� �μ����� �ּ� �޿��� �޴� ����� ������ �˻��ϼ���
--    (�̸�, �޿�)
SELECT DNO, ENAME, SAL
FROM EMP
WHERE (DNO, SAL) IN (SELECT DNO, MIN(SAL)
                    FROM EMP
                    GROUP BY DNO)
ORDER BY DNO;