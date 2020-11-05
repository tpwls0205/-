<그룹함수와 HAVING 절>
; 그룹함수를 포함한 조건은 WHERE 절을 사용할 수 없다
  그래서 HAVING 절을 사용해야 한다

1) 테이블의 SAL 접근 이전에 WHERE SAL >= 3000을 먼저 연산한다
SELECT SAL
FROM EMP
WHERE SAL >= 3000;

2) 부서별 평균
--GROUP BY DNO -> ROUND(AVG(SAL)) -> ROUND(AVG(SAL)) >= 3000
SELECT ROUND(AVG(SAL))
FROM EMP
GROUP BY DNO;

3) 업무별 평균
SELECT ROUND(AVG(SAL))
FROM EMP
GROUP BY JOB;

4) 부서별 급여 평균이 3천 미만인 부서의 부서번호와 평균 급여를 검색하라
SELECT DNO 부서, ROUND(AVG(SAL))
FROM EMP
GROUP BY DNO
HAVING AVG(SAL) < 3000;

5) 부서별 인원수를 출력하세요(단, 업무가 개발이 아닌 인원만)
JOB은 일반 컬럼 조건이므로 HAVING 절을 사용할 수 없다
SELECT DNO 부서, COUNT(*)
FROM EMP
GROUP BY DNO
HAVING JOB != '개발';

JOB 은 WHERE 절에 조건을 부여해야 한다
SELECT DNO 부서, COUNT(*)
FROM EMP
WHERE JOB != '개발'
GROUP BY DNO;

DNO는 일반 컬럼이지만 GROUP BY DNO에 의해
그룹함수와 묶이는 일반컬럼이므로
이때는 HAVING 절에 DNO를 사용할 수 있다
그러나 DNO도 WHERE 절에 조건을 주는 것을 원칙으로 한다 
SELECT DNO 부서, COUNT(*)
FROM EMP
GROUP BY DNO
HAVING DNO != '10';

6) 그룹 대상 컬럼과 검색
DNO별로 그룹이 묶이게 된다
SELECT DNO, COUNT(*) 인원수
FROM EMP
GROUP BY DNO;

DNO별로 묶이되 세부적으로 DNO내의 JOB그룹으로 묶여서 출력
SELECT DNO, JOB, COUNT(*) 인원수
FROM EMP
WHERE JOB != '개발'
GROUP BY DNO, JOB;
--HAVING JOB != '개발';