1) �۰� ������ �����ϴ� ������ �˻��Ѵ�
SELECT p.pno, pname, cno, cname
FROM professor p, course c
WHERE p.pno=c.pno
AND pname='�۰�';

2) ȭ�� ���� ������ �����ϴ� ������ ����� �˻��Ѵ�
SELECT pname 'ȭ�� ������ �����ϴ� ����'
FROM professor p, course c
WHERE p.pno=c.pno
AND cname LIKE '%ȭ��%';

3) ������ 2������ ����� �̸� �����ϴ� ������ �˻��Ѵ�
SELECT cname, st_num, pname
FROM professor p, course c
WHERE p.pno=c.pno
AND st_num=2;

4) ȭ�а� ������ �����ϴ� ������ �˻��Ѵ�
SELECT cname 'ȭ�а� ���� ���� ����'
FROM professor p, course c
WHERE p.pno=c.pno
AND section='ȭ��';

5) ȭ�а� 1�г� �л��� �⸻��� ������ �˻��Ѵ�
SELECT major, syear, s.sno, sname, cno, result
FROM student s, score r
WHERE s.sno=r.sno
AND major='ȭ��' AND syear=1;

6) �Ϲ�ȭ�� ������ �⸻��� ������ �˻��Ѵ�
SELECT sno, result
FROM course c, score r
WHERE c.cno=r.cno
AND cname='�Ϲ�ȭ��';

7) ȭ�а� 1�г� �л��� �Ϲ�ȭ�� �⸻��� ������ �˻��Ѵ�
SELECT major, syear, s.sno, sname, cname, result
FROM student s, course c, score r
WHERE s.sno=r.sno AND c.cno=r.cno
AND major='ȭ��' AND syear=1 AND cname='�Ϲ�ȭ��';

8) ȭ�а� 1�г� �л��� �����ϴ� ������ �˻��Ѵ�
SELECT DISTINCT cname
FROM student s, course c, score r
WHERE s.sno=r.sno AND c.cno=r.cno
AND major='ȭ��' AND syear=1;

9) ����ȭ�� ������ �������� F�� �л��� ����� �˻��Ѵ�
SELECT s.sno, sname, cname, result, grade
FROM student s, course c, score r, scgrade g
WHERE s.sno=r.sno AND c.cno=r.cno
AND result BETWEEN loscore AND hiscore
AND cname='����ȭ��' AND grade='F';

