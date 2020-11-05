[트랜잭션에 의한 대기 현상 확인 - SESSION 0]

1) DML 을 수행한 후 COMMIT 을 하지 않았기 때문에
  '마초'학생의 행에 EXCLUSIVE LOCK 이 발생한다.
UPDATE STUDENT SET MAJOR = '사회'
WHERE SNAME = '마초';
SELECT SNO, SNAME, MAJOR
FROM STUDENT
WHERE SNAME = '마초';

4) 트랜잭션을 완료하자
COMMIT;