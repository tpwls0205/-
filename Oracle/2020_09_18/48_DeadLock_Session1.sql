[데드락(DEAD LOCK)을 발생하고 결과를 확인한다 - SESSION 1]

2) '장각' 학생의 행에 독점 잠금이 발생됨
   '관우' 학생의 수정을 시도했으나 상대 SESSION 0의
   독점 잠금에 의해 WAIT 상태로 진입하게 된다
SELECT SNO, SNAME, MAJOR
FROM STUDENT
WHERE SNAME IN ('관우', '장각');

UPDATE STUDENT SET MAJOR = '경제'
WHERE SNAME = '장각';

UPDATE STUDENT SET MAJOR = '경제'
WHERE SNAME = '관우';
