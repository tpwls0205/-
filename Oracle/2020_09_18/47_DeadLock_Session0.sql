[데드락(DEAD LOCK)을 발생하고 결과를 확인한다 - SESSION 0]

1) '관우' 학생의 행에 독점 잠금이 발생됨
SELECT SNO, SNAME, MAJOR
FROM STUDENT
WHERE SNAME IN ('관우', '장각');

UPDATE STUDENT SET MAJOR = '경제'
WHERE SNAME = '관우';

3) 상대 SESSION 1에 의해 '장각'학생은 독점 잠금이 걸려있는데
   여기서 수정을 시도함으로 WAIT 상태로 진입하게 된다
   그런데 이때 상대가 WAIT 상태이므로
   DEAD LOCK 상태로 진입하게 된다
UPDATE STUDENT SET MAJOR = '사회'
WHERE SNAME = '장각';

4) SESSION 0과 SESSION 1은 모두 WAIT 상태로 진입했으므로
   그냥 내버려두면 무한 WAIT 가 된다
   이것을 DEAD LOCK 이라고 한다
   오라클은 DEAD LOCK을 감지하게 되면
   DEAD LOCK 을 발생시킨 세션의 마지막 명령을 보존하고
   (SESSION 0의 마지막 명령 - '장각'을 '사회'로 변경시도)
   DEAD LOCK 을 유발한 상대 세션(SESSION 1의 마지막 명령
   - '관우'를 '경제'로 변경시도)을 ROLLBACK 한다