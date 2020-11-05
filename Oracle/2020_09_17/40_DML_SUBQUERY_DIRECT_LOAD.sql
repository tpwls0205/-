<���������� �̿��� DML ��>
INSERT INTO [/*+APPEND */] ���̺� [NOLOGGING] [(�÷�, �÷�, ...)]
SELECT ��;
1) SELECT ���� ���� �˻��� ���� �Է°����� ����Ѵ�
2) �� ���� ���� ���� �Է��� �� �ִ�
3) �÷� ����Ʈ�� SELECT ���� �÷��� 1:1�� �����Ǿ�� �Ѵ�
4) SELECT ���� ����� ���� ���� ������ �޸� ��ȣ�� ���� �ʴ´�
5) /*+ APPEND */ : ���̷�Ʈ �ε�(�뷮 �۾��� �ӵ� ���)
6) [NOLOGGING] : �α� ������ ������ �������� �Է��۾��� ��������
                 �׷��� ��� �߻��� ������ �� ����.
7) ���̷�Ʈ �ε� : �Ϲ����� DML ó���� ����Ŭ�� �޸𸮿� �ӽ� �����Ͽ��ٰ�
                 ���߿� ��ũ�� �����ϴµ� �޸𸮿� �����ϴ� �߰�������
                 ���ְ� �ٷ� ��ũ�� �����ϴ� ���� ���Ѵ�

UPDATE ���̺�
 SET �÷��� = (SELECT ��),
     �÷��� = (SELECT ��), ...
 [WHERE ����];
 
UPDATE ���̺�
 SET (�÷�, �÷�, ...) = (SELECT ��)
  [WHERE ����];
A) UPDATE ���� SET ������ ���� �� �������� ���̳� ���� �� ������������
   �̿��� �� �ִ�.
   - ���� ���� ��쵵 �ݵ�� ��� ���� �ϳ����� �Ѵ�.
B) �� �� �˻��Ǵ� DATA �� �ݵ�� �����Ǵ� �÷���� 1:1 �����Ǿ�� �Ѵ�
C) SET ������ ������ ���������� �������� WHERE ���� ����������
   �����ڿ� ���� �޶�����.
   
--1) EMP2 ���̺� ����� ������ �Է��ϼ���   
DESC EMP2;
SELECT * FROM EMP2;

INSERT INTO EMP2(ENO, ASAL)
SELECT ENO, SAL*12+NVL(COMM,0)
FROM EMP;

SELECT * FROM EMP2;

�Է� �������� Ÿ���� ��ġ���� ������ ������ �߻��Ѵ�
INSERT INTO EMP2(ENO, ASAL)
SELECT ENO, HDATE
FROM EMP;
INSERT INTO EMP2(ENO, ASAL)
SELECT ENO, ENAME
FROM EMP;

2) �� ����� ������ �ٹ����� EMP3 ���̺� �����ϼ���
DESC EMP3;
SELECT * FROM EMP3;

<���̷�Ʈ �ε�>
���̷�Ʈ �ε�� �Է����� ���� Ʈ������� �Ϸ����� ������ �˻����� �ʴ´�
INSERT /*+APPEND */ INTO EMP3 NOLOGGING (ENO, ENAME, DNO, DNAME)
SELECT ENO, ENAME, D.DNO, DNAME
FROM EMP E, DEPT D
WHERE D.DNO = E.DNO;

COMMIT;

SELECT * FROM EMP3;

--SELECT �۾��̳� DML �۾��� ��� �޸𸮿��� �̷������
--����Ŭ�� SGA ��� �޸� ���� ���� �����ͺ��̽� ���� ĳ��(DATABASE)
--(DATABASE BUFFER CACHE)��� ������ �̵� �۾� �������� �̿��Ѵ�
--�̸� ���� ��ũ ���� ȸ���� ���� �ٿ� ������ ����Ų��
--�׷��� �ϰ����� �뷮�� DML �۾��� �޸𸮿��� �Ͼ�� �̸� ��ũ����
--�ݿ��ϰ� �ٽ� �޸𸮸� �����ϴ� ���� ��ȿ���� �߻��Ѵ�
--�̸� ���ϱ� ���� �뷮 DML �۾������� �޸𸮸� ������ �ʰ� ��ũ��
--���� �۾��� �����ϴ� ���� ���̷�Ʈ �ε�(Direct Load)��� �Ѵ�
--DML �۾��� ���̷�Ʈ �ε��ϱ� ���ؼ��� '/*+ APPEND */'�� ���忡 �����Ѵ�
--
--�׸��� ����Ŭ�� ������ �ý��� ��� ���� ��� �߻� �� ������ �� �ֵ���
--DB�� ������ ���ϴ� ��� �۾��� ������ ���� �α�(Redo log)������
--�α������� �����Ѵ�. �׷��� �뷮�� DML �۾��� �۾��� ȿ���� ���� �̸�
--�������� ���� �� �ִ�. �۾� ������ ���� �α� ������ ������ �ʴ´ٸ�
--'NOLOGGING'�ɼ��� �̿��Ѵ�. �׷��� �̷��� ������ �Ұ����ϵ��� �۾���
--���Ŀ��� ��ֿ� ����� ����� ���� �ʾƾ� �Ѵ�. �뷮�� �۾����� ���̷�Ʈ
--�α׿� ��α����� �̿��ϸ� �۾� ������ ��������� ���������� �۾���
--�������� ������ �� �ۿ� ����.
--
--���̷�Ʈ �ε� �Ŀ��� COMMIT ó���� �ؾ� �˻��� �� �ִ�.
--COMMIT ���� Ʈ������� ������ ���� �ʰ� �˻��ϸ� 'ORA-12838'
--������ ������. �� ������ �Էµ������� �ջ��� �����ϱ� ���� ����̴�.
--
--<���� ������ �̿��� UPDATE ���� �����Ѵ�>

--3) �������� �޿��� ���ʽ��� ���� �迬���� �޿��� �缱ȣ�� ���ʽ���
--   �����ϰ� �����ϼ���
UPDATE EMP
 SET SAL = (SELECT SAL FROM EMP WHERE ENAME='�迬��'),
     COMM = (SELECT COMM FROM EMP WHERE ENAME='�ȿ���')
 WHERE ENAME = '������';
 
SELECT ENAME, SAL, COMM FROM EMP WHERE ENAME = '������';
SELECT * FROM EMP WHERE ENAME IN ('������','�迬��','�ȿ���');
   
4) �����ΰ� ������ �μ��� ������� �޿��� �������� �޿��� �����ϰ�
   �����ϼ���
UPDATE EMP
 SET SAL = (SELECT SAL FROM EMP WHERE ENAME = '������')
 WHERE DNO = (SELECT DNO FROM EMP WHERE ENAME = '������');

SELECT * FROM EMP
WHERE DNO = (SELECT DNO FROM EMP WHERE ENAME = '������');

5) ���ʷ��� �޿��� ���ʽ��� �迬�ƿ� �����ϰ� �����ϼ���
UPDATE EMP
 SET (SAL, COMM) = (SELECT SAL, COMM FROM EMP WHERE ENAME='�迬��')
 WHERE ENAME='���ʷ�';

�Ʒ�ó�� ���� �� ���������� �ٲ� �� ������ ���������� ���� �� ����������
(��, ���̺� ��ĵ�� ���� �� �ϹǷ�) ������ ���� ��������
UPDATE EMP
 SET SAL = (SELECT SAL FROM EMP WHERE ENAME='�迬��'),
     COMM = (SELECT COMM FROM EMP WHERE ENAME='�迬��')
 WHERE ENAME = '���ʷ�';

SELECT * FROM EMP
WHERE ENAME IN ('�迬��', '���ʷ�');