[트랜잭션에 의한 대기 현상 확인 - SESSION 1]

2) SESSION 0에 의해 '마초'학생의 학과가 변경되었고
   COMMIT 을 하지 않아서 EXCLUSIVE LOCK 이 걸린 상태이다
   그러므로 SESSION 1은 UNDO SEGMENT 의 이전 학과를 읽어온다
SELECT SNO, SNAME, MAJOR
FROM STUDENT
WHERE SNAME = '마초';

3) SESSION 1은 '마초'의 학과를 '경제'로 변경하려고 한다
   SESSION 0에 의해 EXCLUSIVE LOCK 이 발생된 것은
   전혀 모르는 상태이다
   -> SESSION 0에 의해 독점 잠금이 되면
      SESSION 1의 DML 은 테이블의 행을 변경할 수 없고
      기다리게 된다(대기 상태에 진입한다)
      그러다가 SESSION 0이 COMMIT 을 하면
      그때 테이블의 행을 변경하고 독점 잠금을 걸게 된다
UPDATE STUDENT SET MAJOR = '경제'
WHERE SNAME = '마초';