<������ �Լ� - ����, ��¥�� �Լ�>
A) ROUND : N�ڸ����� �ݿø��Ѵ�
           ROUND(M, N)
           ROUND(123.4567, 3) -> 123.457
           
   TRUNC : N�ڸ��̸��� �����Ѵ�
           TRUNC(M, N)
           TRUNC(123,4567, 3) -> 123.456
           
   MOD : M�� N���� ���� ������ ����Ѵ�
         MOD(M, N)
         MOD(10, 4) -> 2
   
   POWER : M�� N���� ����Ѵ�
           POWER(M, N)
           POWER(2, 4) -> 16
   
   CEIL : M���� ū ���� ���� ������ ã�´�
          CEIL(M)
          CEIL(2.34) -> 3
          
   FLOOR : M���� ���� ���� ū ������ ã�´�
           FLOOR(M)
           FLOOR(2.34) -> 2
   
   ABS : M�� ���밪�� ����Ѵ�
         ABS(M)
         ABS(-4) -> 4
  
   SQRT : M�� �������� ����Ѵ�(��Ʈ)
          SQRT(M)
          SQRT(9) -> 3
          
   SIGN : M�� ������ �� -1, ����� �� 1, 0�̸� 0�� ��ȯ�Ѵ�(��ȣ)
          SIGN(M)
          SIGN(-3) -> -1
          
--1) ROUND �Լ��� ���
SELECT ROUND(98.765), TRUNC(98.765),
ROUND(98.765, 2), TRUNC(98.765, 2)
FROM DUAL;

--2) MOD �Լ��� ���
SELECT MOD(19, 3), MOD(-19, 3)
FROM DUAL;

--3) 10�� �μ��� ������ ����Ѵ�. �� 100 ���� �̸��� �����Ѵ�
SELECT ENO, ENAME, TRUNC(SAL*12+NVL(COMM,0), -2) ����
FROM EMP
WHERE DNO = '10';

--<��¥ �Լ�>
--4) ���� ��¥�� �˻��ϰ� ��¥ ��� ����� �����ϼ���
SELECT SYSDATE
FROM DUAL;

ALTER SESSION SET NLS_DATE_FORMAT = 'YYYY/MM/DD:HH24:MI:SS';
ALTER SESSION SET NLS_DATE_FORMAT = 'YYYY/MM/DD';

--5) ���� ��¥, �Ի� ����, �Ի��Ϸκ��� ���ñ��� �Ⱓ, �Ի��� ����
-- 100���� ������ ���� �˻��ϼ���
SELECT SYSDATE, HDATE, SYSDATE-HDATE, HDATE+100
FROM EMP
WHERE ENAME = '�迬��';

<��¥ �Լ�>
; ���󵵰� ����
YYYY : �⵵
MM : ��
DD : ��¥
HH : �ð�
MI : ��
SS : ��

ROUND : ���Ŀ� ���߾� �ݿø��� ��¥�� ��ȯ�Ѵ�
        ROUND(��¥, ����)
        ROUND(SYSDATE, 'DD') -> 2020/09/11
TRUNC : ���Ŀ� ���߾� ������ ��¥�� ��ȯ�Ѵ�
        TRUNC(��¥, ����)
        TRUNC(SYSDATE, 'DD') -> 2020/09/10
        TRUNC(SYSDATE, 'YYYY') -> 2020/01/01
MONTHS_BETWEEN : �� ��¥���� �Ⱓ�� �� ���� ����Ѵ�
        MONTHS_BETWEEN(��¥1, ��¥2)
        MONTHS_BETWEEN('2020/06/01', '2020/09/10')
ADD_MONTHS : ��¥�� N���� ���� ��¥�� ����Ѵ�
        ADD_MONTHS(��¥, N)
        ADD_MONTHS('2020/06/01', 5)
NEXT_DAY : ��¥ ���� ������ ���Ͽ� �ش��ϴ� ��¥�� ����Ѵ�
        NEXT_DAY(��¥, ����)
        ���� ǥ���� 'SUN', '�Ͽ���', 1 �� ���� �پ��� ǥ���� �����ϴ�
        NEXT_DAY('2020/09/10', '1')
LAST_DAY : ��¥�� ������ ���� ������ ��¥�� ����Ѵ�
        LAST_DAY(��¥)
        LAST_DAY('2020/09/10') -> 2020/09/30

--6) ���ڿ� ��¥�� �ݿø��ϰų� �����Ͽ� ����ϼ���
SELECT SYSDATE, ROUND(SYSDATE, 'YY') ��,
ROUND(SYSDATE, 'MM') ��, ROUND(SYSDATE, 'DD') ��
FROM DUAL;

SELECT SYSDATE, TRUNC(SYSDATE, 'YY') ��,
TRUNC(SYSDATE, 'MM') ��, TRUNC(SYSDATE, 'DD') ��
FROM DUAL;

--7) �迬�ư� ���ñ��� ���� �ϼ��� �˻��ϼ���
-- +1�� ���� ����
--ȫ�浿�� 1��~10�ϱ��� ������ �� ���� �ϼ���?
--(10-1) + 1 = 10�� ����
SELECT TRUNC(SYSDATE, 'DD') - TRUNC(HDATE, 'DD')+1 "���� �ϼ�"
FROM EMP
WHERE ENAME = '�迬��';

--8) 20�� �μ� ������� ������� �ٹ��� ���� ���� �˻��ϼ���
SELECT ENO, ENAME, TRUNC(MONTHS_BETWEEN(SYSDATE, HDATE)) �ٹ�����
FROM EMP
WHERE DNO = '20';

--9) 20�� �μ� ������� �Ի� 100��° �Ǵ� ���� 10��° �Ǵ� ���� ���ϼ���
SELECT ENO, ENAME, HDATE �Ի���,
HDATE+99 "100��", ADD_MONTHS(HDATE, 120) "10��"
FROM EMP
WHERE DNO = '20';

--10) 20�� �μ������� �Ի��� ���� ù ��° �Ͽ����� �˻��ϼ���
SELECT ENO, ENAME, HDATE, NEXT_DAY(HDATE, '�Ͽ���') SUNDAY
FROM EMP
WHERE DNO = '20';

--11) 10�� �μ������� �Ի��� ���� ������ ��¥�� �Ի��� ���� 
-- �ٹ� �ϼ��� �˻��ϼ��� (��, �Ի����� �ٹ��Ͽ��� �����մϴ�)
SELECT ENO, ENAME, HDATE, LAST_DAY(HDATE) ��������,
LAST_DAY(TRUNC(HDATE))-TRUNC(HDATE) "�������� �ٹ��ϼ�"
FROM EMP
WHERE DNO = '20';