--<자연 조인(Natural Join)>
--SELECT 컬럼, ...
--FROM 테이블1
--NATURAL JOIN 테이블2
--WHERE 검색조건;
--A) 동일한 이름/타입의 컬럼이 존재할 때
--    조인조건을 명시하지 않아도
--    자동으로 찾아서 조인을 해준다
--B) 공통 컬럼이 반드시 하나 존재해야 한다
--    둘 이상인 경우는 사용할 수 없다
--    이럴 경우는 USING 절을 사용할 수 있다

--1) 자연 조인으로 각 사원의 근무 부서를 검색하라
SELECT ENO 사번, ENAME 이름, DNO 부서번호, DNAME 부서명
FROM EMP
NATURAL JOIN DEPT;

SELECT ENO 사번, ENAME 이름, E.DNO 부서번호, DNAME 부서명
FROM EMP E, DEPT D
WHERE E.DNO = D.DNO;

--2) '광주'에서 근무하는 직원의 명단을 검색하라(부서번호와 부서명도 검색)
SELECT LOC 근무처, DNO 부서번호, DNAME 부서명
        ,ENO 사번, ENAME 이름
FROM EMP
NATURAL JOIN DEPT
WHERE LOC = '광주';

--<USING 절>
--SELECT 컬럼, 컬럼, ...
--FROM 테이블1
--JOIN 테이블2 USING (조인 컬럼)
--WHERE 검색조건;
--3) USING 절을 사용한 JOIN으로 각 사원의 근무 부서를 검색하라
SELECT ENO 사번, ENAME 이름, DNO 부서번호, DNAME 부서명
FROM EMP 
JOIN DEPT USING (DNO);

--4) '서울'에서 근무하는 직원의 명단을 검색하라(부서번호와 부서명도 검색)
SELECT LOC 근무처, DNO 부서번호, DNAME 부서명,
        ENO 사번, ENAME 이름
FROM DEPT
JOIN EMP USING(DNO)
WHERE LOC='서울';

--5) 화학과 1학년 학생들의 유기화학 점수를 검색하라
--화학과 1학년 학생 : STUDENT
--유기화학 : COURSE
--점수 : SCORE
SELECT SNO 학번, SNAME 이름, MAJOR 학과, CNAME 과목명, RESULT 점수
FROM STUDENT
JOIN SCORE USING (SNO)
JOIN COURSE USING (CNO)
WHERE MAJOR = '화학'
AND SYEAR = 1
AND CNAME = '유기화학'
ORDER BY RESULT DESC;

SELECT SNO 학번, SNAME 이름, MAJOR 학과, CNAME 과목명, RESULT 점수
FROM STUDENT
NATURAL JOIN SCORE
NATURAL JOIN COURSE
WHERE MAJOR = '화학'
AND SYEAR = 1
AND CNAME = '유기화학'
ORDER BY RESULT DESC;

SELECT ST.SNO 학번, SNAME 이름, MAJOR 학과, CNAME 과목명, RESULT 점수
FROM STUDENT ST, COURSE C, SCORE R
WHERE ST.SNO = R.SNO AND C.CNO = R.CNO
AND MAJOR = '화학'
AND SYEAR = 1
AND CNAME = '유기화학'
ORDER BY RESULT DESC;