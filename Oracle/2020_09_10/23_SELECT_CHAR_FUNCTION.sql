<������ �Լ� - ���� �Լ�>
A) ������ �Լ�
   ����SW�� �ڵ带 ���̰�
   DB�� ������ �ִ��� Ȱ��(������ �����͸� ����)
   - ���� �Լ�
   - ���� �Լ�
   - ��¥ �Լ�
   - ��ȯ �Լ�
   - �Ϲ� �Լ�
   
B) LOWER : ���ڿ��� �ҹ��ڷ� ��ȯ�Ѵ�
           LOWER('ORACLE') -> oracle
   UPPER : ���ڿ��� �빮�ڷ� ��ȯ�Ѵ�
           UPPER('oracle') -> ORACLE
   INITCAP : ù���ڸ� �빮�ڷ� ��ȯ�ϰ� �������� �ҹ��ڷ� ��ȯ�Ѵ�
            INITCAP('orAclE') -> Oracle

C) CONCAT : �ΰ��� ���ڿ��� �����Ѵ�
            �̰ͺ��ٴ� ���Ῥ���ڸ� �ַ� ����Ѵ�('||')
            CONCAT('��', '����') -> �迬��
            '��'||'����'
   SUBSTR : ���ڿ� ���� ������ ��ġ�� ���ڿ��� ��ȯ�Ѵ�
            SUBSTR(���ڿ�, ������ġ, ��¹����� ����)
            SUBSTR('ORACLE', 1, 2) -> OR
   LENGTH : ���ڿ��� ���̸� ��ȯ�Ѵ�
            LENGTH(���ڿ�)
            LENGTH('ORACLE') -> 6
   INSTR : ������ ������ ��ġ�� �����Ѵ�
           INSTR(���ڿ�, �˻�����, [������ġ, [ȸ��]])
           INSTR('ORACLE', 'A') - > 3
   TRIM : ���ξ ���̾ �߶󳽴�
          TRIM(LEADING|TRAILING|BOTH] ���ܹ��� FROM ���ڿ�
          ���ܹ��ڸ� �������� ������ ���鹮�ڸ� �߶󳽴�
          TRIM('O' FROM 'ORACLE') -> RACLE
          _ORACLE_ : _�� SPACE���ڷ� �����Ѵ�
          TRIM('_ORACLE_') -> ORACLE
   LPAD, RPAD : ������ ���ڿ��� ���̸�ŭ ��κп� ���ڸ� ä���
          LPAD(���ڿ�, �����, ä����)
          LPAD('20000', 10, '*') -> *****20000
          RPAD('20000', 10, '#') -> 20000#####

D) ���� ġȯ �Լ�
   TRANSLATE : ���ڴ��� ġȯ�� ���� �����Ѵ�
               TRANSLATE(���ڿ�, �˻�����, ġȯ����)
               TRANSLATE('ORACLE', 'O', '#') -> #RACLE
   REPLACE : ���ڿ� ���� ġȯ�� ���� �����Ѵ�
             REPLACE(���ڿ�, �˻����ڿ�, ġȯ���ڿ�)
             REPLACE('ORACLE', 'OR', '##') -> ##ACLE
     

--1) ERP �μ��� �ִ� ������ �˻��϶�
SELECT LOC "ERP �μ� ����"
FROM DEPT
WHERE LOWER(DNAME) = 'erp';

--2) �μ��� ��� ��ġ�� �ϳ��� �÷����� �˻��Ѵ�
SELECT CONCAT(DNAME, ' '||LOC)
FROM DEPT;

SELECT DNAME||' '||LOC
FROM DEPT;

--3) �μ���� �μ����� ���̸� ����϶�
SELECT DNAME, LENGTH(DNAME)
FROM DEPT;

--4) SUBSTR �Լ��� �̿��ؼ� �÷��� �Ϻ� ���븸�� �˻��϶�
-- SQL�� ù��°�� 0�� �ƴ϶� 1�� �����Ѵ�
SELECT ENAME, SUBSTR(ENAME, 2), -- 2��° ���ں���
SUBSTR(ENAME, -2),              -- �ڿ��� 2��° ���ں���
SUBSTR(ENAME, 1, 2),            -- 1��° ���ں��� 2����
SUBSTR(ENAME, -2, 2)            -- �ڿ��� 2��° ���ں��� 2����
FROM EMP;

--5) ����̸��� 'A'�� ��Ÿ���� ��ġ�� ����϶�
SELECT INSTR('DATABASE', 'A'),  -- A�� ó�� ��Ÿ���� ��ġ
INSTR('DATABASE', 'A', 3),      -- A�� 3�� �ε������� ��Ÿ���� ��ġ
INSTR('DATABASE', 'A', 1, 3)    -- A�� 1�� �ε������� A�� 3��° ��Ÿ���� ��ġ
FROM DUAL;

--6) TRIM�Լ��� ����ؼ� ���ڿ��� �˻��϶�
SELECT TRIM('��' FROM '���Ⳳ'),
TRIM(LEADING '��' FROM '���Ⳳ'),
TRIM(TRAILING '��' FROM '���Ⳳ')
FROM DUAL;

--7) �̸��� �޿��� ���� 10 �÷����� �˻��϶�
SELECT RPAD(ENAME, 10, '*'), LPAD(SAL, 10, '*')
FROM EMP;

--8) �μ����� ������ ���ڸ� �����ϰ� �˻��϶�
SELECT DNAME, SUBSTR(DNAME, 1, LENGTH(DNAME)-1) DNAME
FROM DEPT;

--9) TRANSLATE, REPLACE ����ϱ�
SELECT TRANSLATE('WORLD OF WARCRAFT', 'WO', '--') TRANSLATE,
REPLACE('WORLD OF WARCRAFT', 'WO', '--') REPLACE
FROM DUAL;

SELECT REPLACE('RED HAT', 'RED', '�Ķ�-BLUE') ġȯ
FROM DUAL;