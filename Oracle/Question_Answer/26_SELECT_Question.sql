<���� �� �Լ��� �̿��ϼ���>
1) �������� ������ �޿� �ٹ��� �ϼ��� �� ������ �˻��ϼ���
SELECT pno, pname, hiredate,
	   LAST_DAY(TRUNC(hiredate)) - TRUNC(hiredate)+1
FROM professor;

2) �������� ���ñ��� �ٹ��� �ְ� �� ������ �˻��ϼ���
SELECT pno, pname, TRUNC((sysdate-hiredate+1)/7)
FROM professor;

3) 1991�⿡�� 1995�� ���̿� ������ ������ �˻��ϼ���
SELECT pno, pname, hiredate
FROM professor
WHERE TRUNC(hiredate) BETWEEN '1991/01/01' AND '1995/12/31';

4) �л����� 4.5 ȯ�� ������ �˻��ϼ���(�� �Ҽ� ���� ��°�ڸ�����)
SELECT sno, sname, ROUND(avr*4.5/4.0, 2)
FROM student;

