<단일행 함수 - 문자 함수>
A) 단일행 함수
   응용SW의 코드를 줄이고
   DB의 성능을 최대한 활용(정제된 데이터만 추출)
   - 문자 함수
   - 숫자 함수
   - 날짜 함수
   - 변환 함수
   - 일반 함수
   
B) LOWER : 문자열을 소문자로 변환한다
           LOWER('ORACLE') -> oracle
   UPPER : 문자열을 대문자로 변환한다
           UPPER('oracle') -> ORACLE
   INITCAP : 첫문자만 대문자로 변환하고 나머지는 소문자로 변환한다
            INITCAP('orAclE') -> Oracle

C) CONCAT : 두개의 문자열을 연결한다
            이것보다는 연결연산자를 주로 사용한다('||')
            CONCAT('김', '연아') -> 김연아
            '김'||'연아'
   SUBSTR : 문자열 내의 지정된 위치의 문자열을 반환한다
            SUBSTR(문자열, 시작위치, 출력문자의 개수)
            SUBSTR('ORACLE', 1, 2) -> OR
   LENGTH : 문자열의 길이를 반환한다
            LENGTH(문자열)
            LENGTH('ORACLE') -> 6
   INSTR : 지정된 문자의 위치를 리턴한다
           INSTR(문자열, 검색문자, [시작위치, [회수]])
           INSTR('ORACLE', 'A') - > 3
   TRIM : 접두어나 접미어를 잘라낸다
          TRIM(LEADING|TRAILING|BOTH] 제외문자 FROM 문자열
          제외문자를 지정하지 않으면 공백문자를 잘라낸다
          TRIM('O' FROM 'ORACLE') -> RACLE
          _ORACLE_ : _를 SPACE문자로 가정한다
          TRIM('_ORACLE_') -> ORACLE
   LPAD, RPAD : 지정된 문자열의 길이만큼 빈부분에 문자를 채운다
          LPAD(문자열, 출력폭, 채움문자)
          LPAD('20000', 10, '*') -> *****20000
          RPAD('20000', 10, '#') -> 20000#####

D) 문자 치환 함수
   TRANSLATE : 문자단위 치환된 값을 리턴한다
               TRANSLATE(문자열, 검색문자, 치환문자)
               TRANSLATE('ORACLE', 'O', '#') -> #RACLE
   REPLACE : 문자열 단위 치환된 값을 리턴한다
             REPLACE(문자열, 검색문자열, 치환문자열)
             REPLACE('ORACLE', 'OR', '##') -> ##ACLE
     

--1) ERP 부서가 있는 지역을 검색하라
SELECT LOC "ERP 부서 지역"
FROM DEPT
WHERE LOWER(DNAME) = 'erp';

--2) 부서의 명과 위치를 하나의 컬럼으로 검색한다
SELECT CONCAT(DNAME, ' '||LOC)
FROM DEPT;

SELECT DNAME||' '||LOC
FROM DEPT;

--3) 부서명과 부서명의 길이를 출력하라
SELECT DNAME, LENGTH(DNAME)
FROM DEPT;

--4) SUBSTR 함수를 이용해서 컬럼에 일부 내용만을 검색하라
-- SQL은 첫번째를 0이 아니라 1로 생각한다
SELECT ENAME, SUBSTR(ENAME, 2), -- 2번째 글자부터
SUBSTR(ENAME, -2),              -- 뒤에서 2번째 글자부터
SUBSTR(ENAME, 1, 2),            -- 1번째 글자부터 2글자
SUBSTR(ENAME, -2, 2)            -- 뒤에서 2번째 글자부터 2글자
FROM EMP;

--5) 사원이름에 'A'가 나타나는 위치를 출력하라
SELECT INSTR('DATABASE', 'A'),  -- A가 처음 나타나는 위치
INSTR('DATABASE', 'A', 3),      -- A가 3번 인덱스부터 나타나는 위치
INSTR('DATABASE', 'A', 1, 3)    -- A가 1번 인덱스부터 A가 3번째 나타나는 위치
FROM DUAL;

--6) TRIM함수를 사용해서 문자열을 검색하라
SELECT TRIM('남' FROM '남기남'),
TRIM(LEADING '남' FROM '남기남'),
TRIM(TRAILING '남' FROM '남기남')
FROM DUAL;

--7) 이름과 급여를 각각 10 컬럼으로 검색하라
SELECT RPAD(ENAME, 10, '*'), LPAD(SAL, 10, '*')
FROM EMP;

--8) 부서명의 마지막 글자를 제외하고 검색하라
SELECT DNAME, SUBSTR(DNAME, 1, LENGTH(DNAME)-1) DNAME
FROM DEPT;

--9) TRANSLATE, REPLACE 사용하기
SELECT TRANSLATE('WORLD OF WARCRAFT', 'WO', '--') TRANSLATE,
REPLACE('WORLD OF WARCRAFT', 'WO', '--') REPLACE
FROM DUAL;

SELECT REPLACE('RED HAT', 'RED', '파란-BLUE') 치환
FROM DUAL;