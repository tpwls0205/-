[�����(DEAD LOCK)�� �߻��ϰ� ����� Ȯ���Ѵ� - SESSION 0]

1) '����' �л��� �࿡ ���� ����� �߻���
SELECT SNO, SNAME, MAJOR
FROM STUDENT
WHERE SNAME IN ('����', '�尢');

UPDATE STUDENT SET MAJOR = '����'
WHERE SNAME = '����';

3) ��� SESSION 1�� ���� '�尢'�л��� ���� ����� �ɷ��ִµ�
   ���⼭ ������ �õ������� WAIT ���·� �����ϰ� �ȴ�
   �׷��� �̶� ��밡 WAIT �����̹Ƿ�
   DEAD LOCK ���·� �����ϰ� �ȴ�
UPDATE STUDENT SET MAJOR = '��ȸ'
WHERE SNAME = '�尢';

4) SESSION 0�� SESSION 1�� ��� WAIT ���·� ���������Ƿ�
   �׳� �������θ� ���� WAIT �� �ȴ�
   �̰��� DEAD LOCK �̶�� �Ѵ�
   ����Ŭ�� DEAD LOCK�� �����ϰ� �Ǹ�
   DEAD LOCK �� �߻���Ų ������ ������ ����� �����ϰ�
   (SESSION 0�� ������ ��� - '�尢'�� '��ȸ'�� ����õ�)
   DEAD LOCK �� ������ ��� ����(SESSION 1�� ������ ���
   - '����'�� '����'�� ����õ�)�� ROLLBACK �Ѵ�