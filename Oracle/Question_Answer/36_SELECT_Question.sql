1) ȭ�а� �л��� ������ ������ �л����� �˻��ϼ���
SELECT sno, sname, major, avr
FROM student
WHERE avr IN (SELECT avr
			  FROM student
			  WHERE major='ȭ��')
AND major!='ȭ��'
ORDER BY major;

2) ȭ�а� ������ �������� ���� ������ �˻��ϼ���
SELECT eno, ename, hiredate
FROM emp
WHERE hiredate IN (SELECT hiredate
				   FROM professor
				   WHERE section='ȭ��');

3) ȭ�а� �л��� ���� �г⿡�� ������ ������ �л����� �˻��ϼ���
SELECT sno, sname, major, syear, avr
FROM student
WHERE (syear, avr) IN (SELECT syear, avr
					   FROM student
					   WHERE major='ȭ��')
AND major!='ȭ��'
ORDER BY major;
