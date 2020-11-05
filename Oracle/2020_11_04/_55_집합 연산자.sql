--<집합 연산자>
--; 합집합, 교집합, 차집합을 의미하는 연산자로
-- SELECT 결과에 대해서 집합 연산을 수행한다.
-- 
-- UNION : 합집합, 검색된 결과의 합으로 중복은 제거된다
-- UNION ALL : 합집합, 중복을 포함한 결과의 합이다
-- INTERSECT : 교집합, 양쪽 모두에서 포함된 행을 검색한다
-- MINUS : 차집합, 첫 번째 검색된 결과에서 두 번째 검색
--         결과를 제외한 나머지를 검색한다
--         
--<집합연산>
--SELECT ...
--[UNION ALL|UNION|INTERSECT|MINUS]
--SELECT ...
-- 1) 두 SELECT 문의 결과를 집합 연산한다
-- 2) 검색 결과 헤더는 앞쪽 SELECT 문에 의해 결정된다
-- 3) 두 SELECT 문의 컬럼 개수와 데이터 타입이 일치해야 한다
-- 4) ALL : 중복을 제거한다
 
--2000년 이후에 입사한 사원과 교수의 명단을 검색한다
--앞의 컬럼을 기준으로 출력된다
SELECT eno, ename, hdate
FROM emp
WHERE hdate > '2000/01/01'
UNION
SELECT pno, pname, hiredate
FROM professor
WHERE hiredate > '2000/01/01';

--UNION 은 중복을 제거하므로 정렬 후 제거
--UNION ALL 은 그냥 검색
--속도가 UNION ALL 이 빠르다

--제갈씨를 가진 사원 중에 지원 업무를 하지 않는 사원을 검색
SELECT eno, ename, job
FROM emp
WHERE ename LIKE '제갈%'
MINUS
SELECT eno, ename, job
FROM emp
WHERE job='지원';


 
 
 
 
 
 






         
         
         
         
         
         
         
         
         
         