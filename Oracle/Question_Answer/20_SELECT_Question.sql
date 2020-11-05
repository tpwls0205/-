1) �۰� ������ �����ϴ� ������ �˻��Ѵ�
SELECT pno, pname, cno, cname
FROM professor
NATURAL JOIN course
WHERE pname='�۰�';

SELECT pno, pname, cno, cname
FROM professor
JOIN course USING (pno)
WHERE pname='�۰�';

2) ȭ�� ���� ������ �����ϴ� ������ ����� �˻��Ѵ�
SELECT pname 'ȭ�� ������ �����ϴ� ����'
FROM professor
NATURAL JOIN course
WHERE cname LIKE '%ȭ��%';

SELECT pname 'ȭ�� ������ �����ϴ� ����'
FROM professor
JOIN course USING (pno)
WHERE cname LIKE '%ȭ��%';

3) ������ 2������ ����� �̸� �����ϴ� ������ �˻��Ѵ�
SELECT cname, st_num, pname
FROM course
NATURAL JOIN professor
WHERE st_num=2;

SELECT cname, st_num, pname
FROM course
JOIN professor USING (pno)
WHERE st_num=2;

4) ȭ�а� ������ �����ϴ� ������ �˻��Ѵ�
SELECT cname 'ȭ�а� ���� ���� ����'
FROM course
NATURAL JOIN professor
WHERE section='ȭ��';

SELECT cname 'ȭ�а� ���� ���� ����'
FROM course
JOIN professor USING (pno)
WHERE section='ȭ��';


5) ȭ�а� 1�г� �л��� �⸻��� ������ �˻��Ѵ�
SELECT major, syear, sno, sname, cno, result
FROM student
NATURAL JOIN score
WHERE major='ȭ��' AND syear=1;

SELECT major, syear, sno, sname, cno, result
FROM student
JOIN score USING (sno)
WHERE major='ȭ��' AND syear=1;

6) �Ϲ�ȭ�� ������ �⸻��� ������ �˻��Ѵ�
SELECT sno, result
FROM score
NATURAL JOIN course
WHERE cname='�Ϲ�ȭ��';

SELECT sno, result
FROM score
JOIN course USING (cno)
WHERE cname='�Ϲ�ȭ��';

7) ȭ�а� 1�г� �л��� �Ϲ�ȭ�� �⸻��� ������ �˻��Ѵ�
SELECT major, syear, sno, sname, cname, result
FROM student
NATURAL JOIN score
NATURAL JOIN course
WHERE major='ȭ��' AND syear=1 AND cname='�Ϲ�ȭ��';

SELECT major, syear, sno, sname, cname, result
FROM student
JOIN score USING (sno)
JOIN course USING (cno)
WHERE major='ȭ��' AND syear=1 AND cname='�Ϲ�ȭ��';

8) ȭ�а� 1�г� �л��� �����ϴ� ������ �˻��Ѵ�
SELECT DISTINCT cname
FROM student
NATURAL JOIN score
NATURAL JOIN course
WHERE major='ȭ��' AND syear=1;

SELECT DISTINCT cname
FROM student
JOIN score USING (sno)
JOIN course USING (cno)
WHERE major='ȭ��' AND syear=1;
