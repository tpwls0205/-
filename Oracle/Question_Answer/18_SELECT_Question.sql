1) �л��߿� ���������� �˻��Ѵ�
SELECT DISTINCT s1.sno, s1.sname
FROM student s1, student s2
WHERE s1.sno!=s2.sno
AND s1.sname=s2.sname;

2) ��ü ���� ��ܰ� ������ ����ϴ� ������ �̸��� �а� ������ �˻��Ѵ�
SELECT p.pno, pname, cname
FROM professor p, course c
WHERE p.pno=c.pno(+);

3) �̹� �б� ��ϵ� ��� ����� ��� ������ ���� ������ �˻��Ѵ�
SELECT c.cno, cname, st_num, pname
FROM course c, professor p
WHERE c.pno=p.pno(+)
ORDER BY st_num;
