<���� ���� - ���� �� ���� ����>
A-1) ���� �� ��������
    ; ���������� �ϳ��� �÷����� �ϳ��� ���� �˻��Ѵ�
A-2) ���� �� ��������
    ; ���������� �ϳ��� �÷����� ���� ���� ���� �˻��Ѵ�
A-3) ���� �� ��������
    ; ���������� ���� ���� �÷��� �˻��Ѵ�
    
1) �迬�ƺ��� �޿��� ���� �޴� ����� �˻��ϼ���
SELECT ENO, ENAME
FROM EMP
WHERE SAL > (SELECT SAL
FROM EMP WHERE ENAME='�迬��');

2) '����'�� ������ ������ �л��� ������ �˻��ϼ���
SELECT *
FROM STUDENT
WHERE AVR = (SELECT AVR
FROM STUDENT WHERE SNAME = '����');

SELECT *
FROM STUDENT
WHERE AVR IN (SELECT AVR
FROM STUDENT WHERE SNAME = '����');

3) �迬�ƿ� �μ��� �ٸ��� ������ ������ �ϴ� ����� ������ �˻��ϼ���
SELECT *
FROM EMP
WHERE DNO!=(SELECT DNO
FROM EMP
WHERE ENAME='�迬��')
AND JOB=(SELECT JOB
FROM EMP
WHERE ENAME='�迬��');

4) �μ� �� ���� �޿��� ���� �޴� �μ��� �˻��ϼ���
SELECT DNO "�޿��ִ�μ�", ROUND(AVG(SAL))
FROM EMP
GROUP BY DNO
HAVING AVG(SAL) = (SELECT MAX(AVG(SAL))
                  FROM EMP
                  GROUP BY DNO);
                  
5) �μ� �� ���� �޿��� ���� �޴� �μ��� �˻��ϼ���                  
SELECT E.DNO "�޿��ּҺμ�", DNAME, ROUND(AVG(SAL))
FROM EMP E, DEPT D
WHERE E.DNO = D.DNO
GROUP BY E.DNO, DNAME
HAVING AVG(SAL) = (SELECT MIN(AVG(SAL))
                  FROM EMP
                  GROUP BY DNO);
                  
6) �λ꿡�� �ٹ��ϴ� ����� ������ �˻��ϼ���
SELECT *
FROM EMP
WHERE DNO = (SELECT DNO
FROM DEPT WHERE LOC='�λ�');

SELECT *
FROM EMP
JOIN DEPT USING(DNO)
WHERE LOC = '�λ�';

SELECT *
FROM EMP E, DEPT D
WHERE E.DNO = D.DNO
AND LOC = '�λ�';