<서브 쿼리 - 단일 행 서브 쿼리>
A-1) 단일 행 서브쿼리
    ; 서브쿼리가 하나의 컬럼에서 하나의 행을 검색한다
A-2) 다중 행 서브쿼리
    ; 서브쿼리가 하나의 컬럼에서 여러 개의 행을 검색한다
A-3) 다중 열 서브쿼리
    ; 서브쿼리가 여러 개의 컬럼을 검색한다
    
1) 김연아보다 급여를 많이 받는 사원을 검색하세요
SELECT ENO, ENAME
FROM EMP
WHERE SAL > (SELECT SAL
FROM EMP WHERE ENAME='김연아');

2) '노육'과 평점이 동일한 학생의 정보를 검색하세요
SELECT *
FROM STUDENT
WHERE AVR = (SELECT AVR
FROM STUDENT WHERE SNAME = '노육');

SELECT *
FROM STUDENT
WHERE AVR IN (SELECT AVR
FROM STUDENT WHERE SNAME = '노육');

3) 김연아와 부서가 다르고 동일한 업무를 하는 사원의 정보를 검색하세요
SELECT *
FROM EMP
WHERE DNO!=(SELECT DNO
FROM EMP
WHERE ENAME='김연아')
AND JOB=(SELECT JOB
FROM EMP
WHERE ENAME='김연아');

4) 부서 중 가장 급여를 많이 받는 부서를 검색하세요
SELECT DNO "급여최대부서", ROUND(AVG(SAL))
FROM EMP
GROUP BY DNO
HAVING AVG(SAL) = (SELECT MAX(AVG(SAL))
                  FROM EMP
                  GROUP BY DNO);
                  
5) 부서 중 가장 급여를 적게 받는 부서를 검색하세요                  
SELECT E.DNO "급여최소부서", DNAME, ROUND(AVG(SAL))
FROM EMP E, DEPT D
WHERE E.DNO = D.DNO
GROUP BY E.DNO, DNAME
HAVING AVG(SAL) = (SELECT MIN(AVG(SAL))
                  FROM EMP
                  GROUP BY DNO);
                  
6) 부산에서 근무하는 사원의 정보를 검색하세요
SELECT *
FROM EMP
WHERE DNO = (SELECT DNO
FROM DEPT WHERE LOC='부산');

SELECT *
FROM EMP
JOIN DEPT USING(DNO)
WHERE LOC = '부산';

SELECT *
FROM EMP E, DEPT D
WHERE E.DNO = D.DNO
AND LOC = '부산';