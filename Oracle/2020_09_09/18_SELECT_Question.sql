--1) �л��߿� ���������� �˻��Ѵ�
SELECT DISTINCT ST1.SNAME ��������
FROM STUDENT ST1, STUDENT ST2
WHERE ST1.SNAME = ST2.SNAME
AND ST1.SNO != ST2.SNO;

--2) ��ü ���� ��ܰ� ������ ����ϴ� ������ �̸��� �а� ������ �˻��Ѵ�
SELECT PNAME ������, CNAME �����
FROM PROFESSOR P, COURSE C
WHERE P.PNO = C.PNO(+)
ORDER BY CNAME;

--3) �̹� �б� ��ϵ� ��� ����� ��� ������ ���� ������ �˻��Ѵ�
SELECT C.CNAME ����, P.PNAME �����̸�, ST_NUM ����
FROM COURSE C, PROFESSOR P
WHERE P.PNO(+) = C.PNO
ORDER BY ST_NUM DESC;
