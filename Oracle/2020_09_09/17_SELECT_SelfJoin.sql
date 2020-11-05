--<자기참조조인(Self Join)>
--; 자신의 테이블의 컬럼끼리 조인하는 것
--; 예) 사원의 관리자 사원 검색
--      부서의 상위 부서 검색

--1) 각 사원을 관리하는 관리자의 이름을 검색하라
SELECT E1.ENO 사번, E1.ENAME 이름, E1.MGR 관리자사번
, E2.ENO 관리자사번, E2.ENAME 관리자이름
FROM EMP E1, EMP E2
WHERE E1.MGR = E2.ENO;

--<외부 조인>
--SELECT 테이블1.컬럼, ... 테이블2.컬럼, ...
--FROM 테이블1, 테이블2, ...
--WHERE 조인조건(+)
--AND 일반조건;
--A) 조인조건에 일치하지 않는 데이터를 출력해준다
--B) '+' 기호는 데이터가 부족한 쪽에 기술한다

--2) 각 부서별로 사원을 검색한다
SELECT D.DNO 부서번호, DNAME 부서명, ENAME 사원명
FROM DEPT D, EMP E
WHERE D.DNO = E.DNO
ORDER BY 1;

--외부조인
--사원이 없는 부서를 검색하기 위해서는 외부조인을 사용해야 한다
SELECT D.DNO 부서번호, DNAME 부서명, ENAME 사원명
FROM DEPT D, EMP E
WHERE D.DNO = E.DNO(+)
ORDER BY 1;