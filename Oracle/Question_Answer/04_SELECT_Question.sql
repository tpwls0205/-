1) �� �л��� ������ �˻��϶�(������ ���)
SELECT sno, sname, avr
FROM student;

2) �� ������ �������� �˻��϶�(������ ���)
SELECT cno, cname, st_num
FROM course;

3) �� ������ ������ �˻��϶�(������ ���)
SELECT pno, pname, orders
FROM professor;

4) �޿��� 10%�λ����� �� ���� ���޵Ǵ� �޿��� �˻��϶�(������ ���)
SELECT eno, ename, sal*12*1.1 "���� �λ�޿�"
FROM emp;

5) ���� �л��� ��� ������ 4.0�����̴�. �̸� 4.5�������� ȯ���ؼ� �˻��϶�(������ ���)
SELECT sno, sname, avr*4.5/4.0 ȯ������
FROM student;



