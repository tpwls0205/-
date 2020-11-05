--정렬된 데이터 검색
--SELECT [DISTINCT | ALL] 컬럼, 컬럼, ...
--FROM 테이블
--ORDER BY 컬럼 [ASC/DESC], 컬럼 [ASC/DESC] ...;

--1) 사원의 이름을 급여 순으로 검색하라
SELECT ENO 사번, ENAME 이름, SAL 급여
FROM EMP
ORDER BY SAL DESC;

--2) 사원의 사번과 이름을 연봉 순으로 검색하라
SELECT ENO 사번, ENAME 이름
FROM EMP
ORDER BY SAL*12+NVL(COMM,0) DESC;

SELECT ENO 사번, ENAME 이름, SAL*12+NVL(COMM,0) 연봉
FROM EMP
ORDER BY 연봉 DESC;

SELECT ENO 사번, ENAME 이름, SAL*12+NVL(COMM,0) 연봉
FROM EMP
ORDER BY 1 DESC;

SELECT ENO 사번, ENAME 이름, SAL*12+NVL(COMM,0) 연봉
FROM EMP
ORDER BY ENO DESC;

--정렬을 이용한 묶음 검색
--3) 업무별로 사원의 연봉을 검색한다
SELECT JOB 업무, ENO 사번, ENAME 이름, SAL 급여
FROM EMP
ORDER BY 업무;

--4) 각 부서별로 사원의 급여를 검색한다. 단 급여를 많이 받는 사람부터 검색한다.
SELECT DNO 부서번호, ENO 사번, ENAME 이름, SAL 급여
FROM EMP
ORDER BY 부서번호, 급여 DESC;

SELECT DNO 부서번호, ENO 사번, ENAME 이름, SAL 급여
FROM EMP
ORDER BY 부서번호 ASC, 급여 DESC;