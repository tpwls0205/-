[Session 0]
1) '마초' 학생 행에 Exclusive Lock 이 발생한다
    Session 0 은 테이블의 변경된 값을 읽어오고 있다.
UPDATE STUDENT SET AVR = 0.1
WHERE SNAME = '마초';
SELECT SNO, SNAME, AVR
FROM STUDENT
WHERE SNAME = '마초';

3) 트랜잭션을 완료하여 Exclusive Lock 을 해제하자
-- (테이블에 걸린 Share Lock 도 해제된다)
COMMIT;