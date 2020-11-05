<인라인 뷰(Inline View)>
; FROM 절에 사용하는 서브쿼리를 의미한다.
  테이블 전체를 이용하지 않고 이중 일부만을 이용하는 방법이다.
  좀 더 작은 범위나 연산된 구역을 대상으로 검색을 함으로써
  단순 SQL 보다 다양한 기능을 수행할 수 있으며 RDBMS 의 
  특성으로 인해 단순 문장으로 수행이 어려운 문제를 해결하는데
  많이 사용된다. Top-N 분석이 대표적인 경우이다.
  
<인라인 뷰 생성>
SELECT ...
FROM (SELECT 문 : sub query 문) 별명
...;
 1) 서브 쿼리에 별명을 부여할 경우 인라인 뷰가 생성된다.
 2) 인라인 뷰는 문장이 실행되는 동안만 존재하는 뷰이다.
 
--각 부서별 최소 급여자를 검색한다
SELECT eno, ename, d.dno, sal, msal
FROM emp e,
     (SELECT dno, MIN(sal) msal FROM emp
      GROUP BY dno) d
WHERE e.dno=d.dno
AND sal=msal;

--ROWNUM 을 이용한 Top-N 분석
SELECT ROWNUM, [컬럼, ...]
FROM (SELECT ... ORDER BY ...)
WHERE ROWNUM <= N;
 1) 상/하위 N개의 행을 검색한다
 2) 인라인 뷰에 반드시 ORDER BY 절이 필요하다
 3) ROWNUM 은 검색된 행의 순서이다.
 
--emp 테이블로부터 3행까지만 검색한다.
SELECT ROWNUM, eno, ename, job, mgr, hdate
FROM emp
WHERE ROWNUM <= 3;

--최상위 연봉을 받는 3인을 검색하라
SELECT ROWNUM, eno, ename, ansal
FROM (SELECT eno, ename, sal*12+NVL(comm,0) ansal
      FROM emp
      ORDER BY ansal DESC)
WHERE ROWNUM <= 3;

--ROWNUM 이 단지 출력 결과에 순서일 뿐만 아니라
--읽는 행의 개수도 제한하기 때문에
--무작위 3명이 검색되어 정렬된다.
--그래서 이럴 때는 위처럼 해야 한다.
SELECT eno, ename, sal*12+NVL(comm,0) ansal
FROM emp
WHERE ROWNUM <= 3
ORDER BY ansal DESC;









 
 
 
 
 






