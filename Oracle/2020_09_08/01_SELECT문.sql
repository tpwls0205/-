--SELECT 문을 이용한 테이블 검색 // Ctrl+/ 주석
/*
SELECT [컬럼, 컬럼, ... | *]
FORM 테이블;
*/

--1) 테이블 구조 검색
DESC emp;

--2) 현재 스키마(사용자)의 모든 테이블 검색
SELECT * FROM tab;

--3) emp 테이블의 구조를 검색하라
DESC emp;

--4) emp 테이블의 모든 내용을 검색하라
SELECT * FROM emp;

--5) dept 테이블의 구조를 검색하라
DESC dept;

--6) dept 테이블의 모든 내용을 검색하라
SELECT * FROM dept;

DESC emp;
--7) 사원의 이름과 업무를 검색하라
SELECT eno, ename, job
FROM emp;

--8) 사원의 사번, 이름, 급여를 검색하라
SELECT eno, ename, sal
FROM emp;

--9) 2+3을 계산하라
SELECT 2+3
FROM dual;