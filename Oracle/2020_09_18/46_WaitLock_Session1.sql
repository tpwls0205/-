[Ʈ����ǿ� ���� ��� ���� Ȯ�� - SESSION 1]

2) SESSION 0�� ���� '����'�л��� �а��� ����Ǿ���
   COMMIT �� ���� �ʾƼ� EXCLUSIVE LOCK �� �ɸ� �����̴�
   �׷��Ƿ� SESSION 1�� UNDO SEGMENT �� ���� �а��� �о�´�
SELECT SNO, SNAME, MAJOR
FROM STUDENT
WHERE SNAME = '����';

3) SESSION 1�� '����'�� �а��� '����'�� �����Ϸ��� �Ѵ�
   SESSION 0�� ���� EXCLUSIVE LOCK �� �߻��� ����
   ���� �𸣴� �����̴�
   -> SESSION 0�� ���� ���� ����� �Ǹ�
      SESSION 1�� DML �� ���̺��� ���� ������ �� ����
      ��ٸ��� �ȴ�(��� ���¿� �����Ѵ�)
      �׷��ٰ� SESSION 0�� COMMIT �� �ϸ�
      �׶� ���̺��� ���� �����ϰ� ���� ����� �ɰ� �ȴ�
UPDATE STUDENT SET MAJOR = '����'
WHERE SNAME = '����';