[Session 0]
1) '����' �л� �࿡ Exclusive Lock �� �߻��Ѵ�
    Session 0 �� ���̺��� ����� ���� �о���� �ִ�.
UPDATE STUDENT SET AVR = 0.1
WHERE SNAME = '����';
SELECT SNO, SNAME, AVR
FROM STUDENT
WHERE SNAME = '����';

3) Ʈ������� �Ϸ��Ͽ� Exclusive Lock �� ��������
-- (���̺� �ɸ� Share Lock �� �����ȴ�)
COMMIT;