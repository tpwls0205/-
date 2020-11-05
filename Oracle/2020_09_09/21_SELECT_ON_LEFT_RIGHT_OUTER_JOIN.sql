--<ON 절을 이용한 조인>
--SELECT 테이블1.컬럼, ..., 테이블2.컬럼, ...
--FROM 테이블1
--JOIN 테이블2 ON 조인조건
--WHERE 검색조건;
--A) 모든 형태의 조인을 표현할 수 있다
--    (등가/비등가 조인)
    
--1) 각 사원의 근무부서를 검색한다
SELECT ENO 사번, ENAME 이름, D.DNO 부서번호, DNAME 부서명
FROM EMP E
JOIN DEPT D ON E.DNO = D.DNO;

SELECT ENO 사번, ENAME 이름, D.DNO 부서번호, DNAME 부서명
FROM EMP E, DEPT D
WHERE E.DNO = D.DNO;

SELECT ENO 사번, ENAME 이름, DNO 부서번호, DNAME 부서명
FROM EMP E
NATURAL JOIN DEPT;

SELECT ENO 사번, ENAME 이름, DNO 부서번호, DNAME 부서명
FROM EMP E
JOIN DEPT USING (DNO);

--2) 지원 업무를 담당하는 사원의 급여 등급을 검색한다.
SELECT ENO 사번, ENAME 이름, JOB 업무, GRADE 급여등급
FROM EMP
JOIN SALGRADE ON SAL BETWEEN LOSAL AND HISAL
WHERE JOB = '지원';

--3) 직원의 부서명과 급여 등급을 검색한다
SELECT ENO 사번, ENAME 이름, DNAME 부서명, GRADE 급여등급
FROM EMP
JOIN DEPT USING(DNO)
JOIN SALGRADE ON SAL BETWEEN LOSAL AND HISAL;

SELECT ENO 사번, ENAME 이름, DNAME 부서명, GRADE 급여등급
FROM EMP E
JOIN DEPT D ON E.DNO = D.DNO 
JOIN SALGRADE ON SAL BETWEEN LOSAL AND HISAL;

--<좌우 외부 조인(LEFT RIGHT OUTER JOIN)>
--+ 기회를 이용하는 외부조인의 다른 표현법
--이전의 외부조인은 한쪽에만 +를 붙이는데
--여기에서는 모두 +를 추가한 것과 동일한 표현이 가능하다
--SELECT 테이블1.컬럼, ... 테이블2.컬럼, ...
--FROM 테이블1
--[LEFT|RIGHT|FULL] [OUTER] JOIN 테이블2 [ON 조인조건|USING(조인컬럼)]
--WHERE 검색조건;
--A) LEFT : '테이블1'을 왼쪽 테이블이라 부르고 왼쪽 테이블에 조인조건과
--          일치하지 않은 행도 검색에 포함한다.
--B) RIGTH : '테이블2'을 오른쪽 테이블이라 부르고 오른쪽 테이블에
--            조인조건과 일치하지 않은 행도 검색에 포함한다.
--C) FULL : 양쪽 테이블 모두에서 조인 조건에 일치하지 않은 행을 검색에
--          포함한다. 이전 (+) 기호를 이용한 외부조인으로는 불가능한 표현이다
--D) ON 절이나 USING 절을 모두 사용할 수 있다.

--4) 사원의 이름과 소속 부서를 검색하라    
SELECT ENO 사번, ENAME 이름, DNO 부서번호, DNAME 부서명
FROM EMP
RIGHT JOIN DEPT USING(DNO);

SELECT ENO 사번, ENAME 이름, DNO 부서번호, DNAME 부서명
FROM EMP
RIGHT OUTER JOIN DEPT USING(DNO);

SELECT ENO 사번, ENAME 이름, DNO 부서번호, DNAME 부서명
FROM EMP
LEFT JOIN DEPT USING(DNO);

SELECT ENO 사번, ENAME 이름, DNO 부서번호, DNAME 부서명
FROM EMP
FULL JOIN DEPT USING(DNO);