[Ʈ����ǿ� ���� ��� ���� Ȯ�� - SESSION 0]

1) DML �� ������ �� COMMIT �� ���� �ʾұ� ������
  '����'�л��� �࿡ EXCLUSIVE LOCK �� �߻��Ѵ�.
UPDATE STUDENT SET MAJOR = '��ȸ'
WHERE SNAME = '����';
SELECT SNO, SNAME, MAJOR
FROM STUDENT
WHERE SNAME = '����';

4) Ʈ������� �Ϸ�����
COMMIT;