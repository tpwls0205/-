--조건 검색
--SELECT 컬럼, 컬럼, ...
--FROM 테이블
--WHERE 조건
--ORDER BY 컬럼;

--1) 사원중에 급여가 4000이상인 사원을 검색하라
SELECT *
FROM EMP
WHERE SAL >= 4000;

--2) 이름이 '김연아'인 사원의 정보를 검색하라
SELECT *
FROM EMP
WHERE ENAME = '김연아';

--3) 10번 부서를 제외한 사원의 명단을 검색하라
--DNO는 타입이 VARCHAR2 이므로
--검색을 할 때 '10'으로 검색해야 한다
--그렇지 않고 숫자로 검색하게 되면
--1행마다 형변환이 이루어진 후 비교연산이 이루어지게 된다
--만일 대기업의 대용량 테이블일 경우
--검색속도가 크게 차이나게 된다
SELECT *
FROM EMP
WHERE DNO!='10';

--4) 연봉이 30,000이상인 사원의 이름을 검색하라
-- 조건비교는(WHERE) 별명이 안된다
-- 정렬은(ORDER BY) 별명이 된다
SELECT ENO 사번, ENAME 이름, SAL*12+NVL(COMM,0) 연봉
FROM EMP
WHERE SAL*12+NVL(COMM,0) >= 30000;

--5) 보너스가 200 이하인 사원을 검색하라
SELECT ENO 사번, ENAME 이름, COMM 보너스
FROM EMP
WHERE COMM <= 200;

SELECT ENO 사번, ENAME 이름, COMM 보너스
FROM EMP
WHERE NVL(COMM,0) <= 200;

--6) 입사일이 1996년 이후인 사원의 정보를 검색하라
SELECT ENO 사번, ENAME 이름, HDATE 입사일
FROM EMP
WHERE HDATE > '1995/12/31';

-- 날짜 포멧 변경
ALTER SESSION SET NLS_DATE_FORMAT='YY/MM/DD';
ALTER SESSION SET NLS_DATE_FORMAT='YYYY/MM/DD';

--7) 보너스 컬럼이 널 값인 사원을 검색하라
SELECT ENO 사번, ENAME 이름, COMM 보너스
FROM EMP
WHERE COMM IS NULL;

--8) 보너스 컬럼이 널 값이 아닌 사원을 검색하라
SELECT ENO 사번, ENAME 이름, COMM 보너스
FROM EMP
WHERE COMM IS NOT NULL;

