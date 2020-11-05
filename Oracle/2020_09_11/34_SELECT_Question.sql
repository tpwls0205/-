--<���� ������ ����ϼ���>
--1) ���캸�� ������ ����� �л��� �й��� �̸��� �˻��ϼ���
SELECT SNO �й�, SNAME �̸�
FROM STUDENT
WHERE AVR > (SELECT AVR
            FROM STUDENT
            WHERE SNAME = '����');

--2) ����� ������ �г� �л� �߿� ������ �縶���� ������ �л��� �˻��ϼ���
SELECT SNAME �̸�
FROM STUDENT
WHERE SYEAR = (SELECT SYEAR
              FROM STUDENT
              WHERE SNAME = '����')
AND AVR = (SELECT AVR
          FROM STUDENT
          WHERE SNAME = '�縶��');

--3) ���캸�� �Ϲ� ȭ�а����� ������ �� ���� �л��� ����� ������ �˻��ϼ���
SELECT SNAME �̸�, RESULT ����
FROM SCORE
JOIN STUDENT USING(SNO)
JOIN COURSE USING(CNO)
WHERE RESULT < (SELECT RESULT
                FROM SCORE
                JOIN STUDENT USING(SNO)
                JOIN COURSE USING(CNO)
                WHERE SNAME = '����'
                AND CNAME = '�Ϲ�ȭ��')
AND CNAME = '�Ϲ�ȭ��';

--4) �ο����� ���� ���� �а��� �˻��ϼ���
SELECT MAJOR, COUNT(MAJOR)
FROM STUDENT
GROUP BY MAJOR
HAVING COUNT(MAJOR) >= (SELECT MAX(COUNT(MAJOR))
                      FROM STUDENT
                      GROUP BY MAJOR);

--5) �л� �� �⸻��� ������ ���� ���� �л��� ������ �˻��ϼ���
SELECT *
FROM STUDENT
JOIN SCORE USING(SNO)
WHERE RESULT = (SELECT MIN(RESULT)
                FROM SCORE);