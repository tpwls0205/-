--1) ȭ�а� �л��� ������ ������ �л����� �˻��ϼ���
SELECT *
FROM STUDENT
WHERE AVR IN (SELECT AVR
              FROM STUDENT
              WHERE MAJOR = 'ȭ��')
AND MAJOR != 'ȭ��';

--2) ȭ�а� ������ �������� ���� ������ �˻��ϼ���
SELECT *
FROM PROFESSOR
WHERE HIREDATE IN (SELECT HIREDATE
                  FROM PROFESSOR
                  WHERE SECTION = 'ȭ��')
AND SECTION != 'ȭ��';                  

--3) ȭ�а� �л��� ���� �г⿡�� ������ ������ �л����� �˻��ϼ���
SELECT *
FROM STUDENT
WHERE (SYEAR, AVR) IN (SELECT SYEAR, AVR
                      FROM STUDENT
                      WHERE MAJOR = 'ȭ��')
AND MAJOR != 'ȭ��';                      