1) '__�а��� __�л��� ���� ������ __�Դϴ�' ���·� �л��� ������ ����϶�
SELECT major||'�а��� '||sname||'�л��� ���� ������ '||avr||'�Դϴ�.'
FROM student;

2) '__������ __���� �����Դϴ�.' ���·� ������ ������ ����϶�
SELECT cname||'������ '||st_num||'���� �����Դϴ�.'
FROM course;

3) '__������ __�а� �Ҽ��Դϴ�.' ���·� ������ ������ ����϶�
SELECT pname||'������ '||section||'�а� �Ҽ��Դϴ�.'
FROM professor;

4) �б����� � �а��� �ִ��� �˻��Ѵ�(�л� ���̺� ������� �˻��Ѵ�)
SELECT DISTINCT major
FROM student;

5) �б����� � �а��� �ִ��� �˻��Ѵ�(���� ���̺� ������� �˻��Ѵ�)
SELECT DISTINCT section
FROM professor;

6) ������ ������ � �͵��� �ִ��� �˻��Ѵ�
SELECT DISTINCT orders
FROM professor;







