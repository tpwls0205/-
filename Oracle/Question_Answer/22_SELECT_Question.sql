1) �� ������ ������ ��� ������ �������� �˻��϶�
SELECT cno, cname, p.pno, pname
FROM course cname
JOIN professor p ON c.pno=p.pno;

2) ȭ�а� �л��� �⸻��� ������ ��� �˻��϶�
SELECT s.sno, sname, cname, result
FROM student sname
JOIN score r ON (s.sno=r.sno)
JOIN course c ON (c.cno=r.cno)
WHERE major='ȭ��';

3) ����ȭ�а��� �������� �⸻��� ���������� �˻��϶�
SELECT r.sno, result
FROM score result
JOIN course c ON r.cno=c.cno
WHERE cname='����ȭ��';

4) ȭ�а� �л��� �����ϴ� ������ ����ϴ� ������ ����� �˻��϶�
SELECT DISTINCT pname
FROM professor pname
JOIN course c ON p.pno=c.pno
JOIN score r ON c.cno=r.cno
JOIN student s ON s.sno=r.sno
WHERE major='ȭ��';

5) ��� ������ ��ܰ� ��� ������ �˻��Ѵ�
SELECT pno, pname, cname
FROM professor
LEFT JOIN course USING (pno);


6) ��� ������ ��ܰ� ��� ������ �˻��Ѵ�(�� ��� ���� ���� �˻��Ѵ�)
SELECT pno, pname, cname
FROM professor
FULL JOIN course USING (pno);
