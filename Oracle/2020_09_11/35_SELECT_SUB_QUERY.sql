<서브 쿼리 - 다중 행, 다중 열>
A) 다중 행 : 여러 개 행이 검색
   단일 행 서브쿼리와 구조는 같으나 사용 연산자가 다르다
   단일 행은 =, != 를 사용한다
   다중 행은 IN : 검색된 값 중에 하나가 일치하면 참
           ANY : 검색된 값 중에 조건이 하나 이상 맞으면 참
           ALL : 검색된 값들과 모두 조건에 맞으면 참

1) 20번 부서원들과 동일한 관리자로부터 관리받는 사원을 검색하세요
SELECT *
FROM EMP
WHERE MGR IN (SELECT MGR
              FROM EMP
              WHERE DNO = '20')
AND DNO != '20';

2) 10번 부서원들보다 급여가 낮은 사원을 검색하세요
SELECT ENO, ENAME, DNO
FROM EMP
WHERE SAL < ALL(SELECT SAL
            FROM EMP
            WHERE DNO = '10')
AND DNO!='10';

SELECT ENO, ENAME, DNO
FROM EMP
WHERE SAL < (SELECT MIN(SAL)
            FROM EMP
            WHERE DNO = '10')
AND DNO!='10';

3) 20번 부서원들과 보너스가 같은 사원을 검색하세요
SELECT ENO, ENAME, DNO, COMM
FROM EMP
WHERE COMM IN (SELECT COMM
              FROM EMP
              WHERE DNO = '20')
AND DNO != '20';         

--NULL 이 포함된 경우는 0으로 치환할지 결정하자
SELECT ENO, ENAME, DNO, COMM
FROM EMP
WHERE NVL(COMM, 0) IN (SELECT NVL(COMM, 0)
              FROM EMP
              WHERE DNO = '20')
AND DNO != '20';

<다중 열 서브쿼리>
; 여러 개 컬럼 항목이 검색되는 것
; IN 연산자를 사용한다

4)손하늘과 동일한 관리자의 관리를 받으면서 업무도 같은 사원을 검색하세요
다중열일 경우 IN을 사용하면 모든 열이 만족되는 경우를 찾는다
SELECT ENO, ENAME , MGR, JOB
FROM EMP
WHERE (MGR, JOB) IN (SELECT MGR, JOB
                    FROM EMP
                    WHERE ENAME = '손하늘')
AND ENAME != '손하늘';    

--아래는 위 문제의 답은 아니다
SELECT ENO, ENAME, MGR, JOB
FROM EMP
WHERE MGR IN (SELECT MGR
            FROM EMP
            WHERE ENAME = '손하늘')
AND JOB IN (SELECT JOB
            FROM EMP
            WHERE ENAME = '손하늘')
AND ENAME != '손하늘';

5) 각 부서별로 최소 급여를 받는 사원의 정보를 검색하세요
--    (이름, 급여)
SELECT DNO, ENAME, SAL
FROM EMP
WHERE (DNO, SAL) IN (SELECT DNO, MIN(SAL)
                    FROM EMP
                    GROUP BY DNO)
ORDER BY DNO;