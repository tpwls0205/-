1) �л��� ��� ������ ���� ���Ŀ� ���� �Ҽ��� ���� 2�ڸ����� �˻��ϼ���
'OOO �л��� ��� ������ O.OO�Դϴ�.'
SELECT sname||' �л��� ��� ������ '||TO_CHAR(avr, '0.99')||'�Դϴ�.'
FROM student;

2) ������ �������� ���� �������� ǥ���ϼ���
'OOO ������ �������� YYYY�� MM�� DD���Դϴ�.'
SELECT pname||' ������ �������� '||TO_CHAR(hiredate, 'YYYY"��" MM"�� "DD"��"')||'�Դϴ�.'
FROM professor; 

3) �����߿� 3���� ������ ������ ����� �˻��ϼ���
SELECT pno, pname, hiredate
FROM professor
WHERE TO_CHAR(hiredate, 'MM')=03;