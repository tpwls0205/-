--<등가조인과 비등가조인>
--SELECT 테이블1.컬럼, ... 테이블2.컬럼, ...
--FROM 테이블1, 테이블2, ...
--WHERE 조인조건
--AND 일반조건
--A) 조인조건에 '='를 사용하는 것을 등가조인
--   부등호를 사용하는 것을 비등가조인이라 한다

--1) 각 사원의 근무 부서를 검색한다
SELECT EMP.ENO 사번, EMP.ENAME 이름, EMP.DNO 부서번호,
DEPT.DNO 부서번호, DEPT.DNAME 부서명
FROM EMP, DEPT
WHERE DEPT.DNO = EMP.DNO;

SELECT ENO 사번, ENAME 이름, EMP.DNO 부서번호,
DEPT.DNO 부서번호, DNAME 부서명
FROM EMP, DEPT
WHERE DEPT.DNO = EMP.DNO;

--2) 부산에서 근무하는 직원의 명단을 검색한다(부서번호와 부서명도 검색)
SELECT LOC 근무처, DEPT.DNO 부서번호, DNAME 부서명, ENO 사번, ENAME 이름
FROM DEPT, EMP
WHERE DEPT.DNO = EMP.DNO
AND LOC='부산';

SELECT LOC 근무처, D.DNO 부서번호, DNAME 부서명, ENO 사번, ENAME 이름
FROM DEPT D, EMP E
WHERE D.DNO = E.DNO
AND LOC='부산';

--비등가 조인
--3) 각 직원의 급여 등급을 검색하라
SELECT ENO 사번, ENAME 이름, SAL 급여, GRADE 등급
FROM EMP, SALGRADE
WHERE SAL BETWEEN LOSAL AND HISAL
ORDER BY GRADE;

SELECT ENO 사번, ENAME 이름, SAL 급여, GRADE 등급
FROM EMP, SALGRADE
WHERE SAL >= LOSAL AND SAL <= HISAL
ORDER BY GRADE;

--4) 각 직원의 급여를 10% 인상한 경우 급여 등급을 검색한다
SELECT ENO 사번, ENAME 이름, SAL * 1.1 "인상된 급여", GRADE 등급
FROM EMP, SALGRADE
WHERE SAL * 1.1 BETWEEN LOSAL AND HISAL
ORDER BY GRADE;

--5) 잘못된 조인문장
--조인조건이 없게되거나 잘못 조건을 기술하면 
--모든 행이 1:1로 대응된 잘못된 결과값(Catersian Product)를
--얻게 된다
--교차 조인(Cross Join)은 일반적으로 잘못된 결과이다
--dept의 7개 행과
--emp의 15개 행이 모두 1:1 대응된 것이다
SELECT D.DNO, DNAME, E.DNO, ENAME
FROM DEPT D, EMP E;
