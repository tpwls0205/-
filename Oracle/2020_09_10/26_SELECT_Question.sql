--<���� �� �Լ��� �̿��ϼ���>
--1) �������� ������ �޿� �ٹ��� �ϼ��� �� ������ �˻��ϼ���
SELECT PNAME ������, HIREDATE, LAST_DAY(HIREDATE),
LAST_DAY(TRUNC(HIREDATE))-TRUNC(HIREDATE)
FROM PROFESSOR;

--2) �������� ���ñ��� �ٹ��� �ְ� �� ������ �˻��ϼ���
SELECT PNAME ������,
TRUNC(MONTHS_BETWEEN(SYSDATE, HIREDATE))*4 "�ٹ��� ��"
FROM PROFESSOR;

--3) 1991�⿡�� 1995�� ���̿� ������ ������ �˻��ϼ��� (�ٸ� �������� �ؾ���)
SELECT PNAME ������, HIREDATE ���ӳ�¥
FROM PROFESSOR
WHERE HIREDATE >= '1991/01/01'
AND HIREDATE <= '1995/12/31';

--4) �л����� 4.5 ȯ�� ������ �˻��ϼ���(�� �Ҽ� ���� ��°�ڸ�����)
SELECT SNAME �л���, TRUNC((AVR/8)*9, 2)
FROM STUDENT;
