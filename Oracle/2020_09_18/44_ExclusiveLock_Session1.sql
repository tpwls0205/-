[Session 1]
2) Session 0�� '����' �л��� ���� ������ ���
   Session 1�� ��� ��µǴ°�?
   -> ���̺��� ���� Session 0�� ���������Ƿ�
   Session 1�� UNDO SEGMENT �� ���� ���� �о�´�
SELECT SNO, SNAME, AVR
FROM STUDENT
WHERE SNAME = '����';

4) SESSION 0�� COMMIT �� �� �ٽ� �˻�����
   -> Exclusive Lock �� �����Ǿ����Ƿ�
   ���̺��� �����͸� ���������� �����ϰ� �ִ�.
SELECT SNO, SNAME, AVR
FROM STUDENT
WHERE SNAME = '����';
