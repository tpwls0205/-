<���� ������ ����ϼ���>
1) ���캸�� ������ ����� �л��� �й��� �̸��� �˻��ϼ���
SELECT sno, sname
FROM student
WHERE avr > (SELECT avr FROM student
			 WHERE sname='����');

2) ����� ������ �г� �л� �߿� ������ �縶���� ������ �л��� �˻��ϼ���
SELECT sno, sname
FROM student
WHERE syear = (SELECT syear 
			   FROM student
			   WHERE sname='����')
AND avr = (SELECT avr 
		   FROM student
		   WHERE sname='�縶��');

3) ���캸�� �Ϲ� ȭ�а����� ������ �� ���� �л��� ����� ������ �˻��ϼ���
SELECT s.sno, sname, grade
FROM student s, course c, score r, scgrade g
WHERE s.sno=r.sno AND r.cno=c.cno AND result BETWEEN loscore AND hiscore
AND cname='�Ϲ�ȭ��'
AND grade > (SELECT grade
			 FROM student s, course c, score r, scgrade g
			 WHERE s.sno=r.sno AND r.cno=c.cno
			 AND result BETWEEN loscore AND hiscore
			 AND sname='����'
			 AND cname='�Ϲ�ȭ��')
AND sname!='����';

4) �ο����� ���� ���� �а��� �˻��ϼ���
SELECT major
FROM student
GROUP BY major
HAVING COUNT(*) = (SELECT MAX(COUNT(*))
				   FROM student
				   GROUP BY major);

5) �л� �� �⸻��� ������ ���� ���� �л��� ������ �˻��ϼ���
SELECT s.sno, sname
FROM student s, score r
WHERE s.sno=r.sno
GROUP BY s.sno, sname
HAVING AVG(result) = (SELECT MIN(AVG(result))
					  FROM score
					  GROUP BY sno);
