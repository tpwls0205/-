1) ȭ�а��� �����ϰ� �л����� ���� ����� �˻��ϼ���
SELECT sno, AVG(avr)
FROM student
WHERE major!='ȭ��'
GROUP BY sno;


2) ȭ�а��� ������ �� �а��� ��� ���� �߿� ������ 2.0 �̻��� ������ �˻��ϼ���
SELECT major, AVG(avr)
FROM student
WHERE major!='ȭ��'
GROUP BY major
HAVING AVG(avr) > 2.0;

3) �⸻��� ����� 60�� �̻��� �л��� ������ �˻��ϼ���(�й��� �⸻��� ���)
SELECT sno, AVG(result)
FROM score
GROUP BY sno
HAVING AVG(result) >= 60;

4) ���� �������� 3���� �̻��� ������ ������ �˻��ϼ���(������ȣ, �̸��� ��� ������)
SELECT p.pno, pname, SUM(st_num)
FROM professor p, course c
WHERE p.pno = c.pno
GROUP BY p.pno, pname
HAVING SUM(st_num) >= 3;

SELECT pno, pname, SUM(st_num)
FROM professor
NATURAL JOIN course
GROUP BY pno, pname
HAVING SUM(st_num) >= 3;



<������ ����>
1) �׻� �����ϵ��� ����� ��(�̼����� ����)
   �̼Ҵ� ������ �ſ� ������
   (���� ��Ȳ���� ������ ã������ ����ϴ� ���)
2) �����ϰ� �����ϴ� ����� �� ��(�ݼ�)
3) ���� �Ͼ ��(����)
4) �ǰ��� ��(����)
5) �׻� ȣ����� ���� ��(���, ����)