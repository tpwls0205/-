<단일행 함수 - 숫자, 날짜형 함수>
A) ROUND : N자리까지 반올림한다
           ROUND(M, N)
           ROUND(123.4567, 3) -> 123.457
           
   TRUNC : N자리미만을 절삭한다
           TRUNC(M, N)
           TRUNC(123,4567, 3) -> 123.456
           
   MOD : M을 N으로 나눈 나머지 계산한다
         MOD(M, N)
         MOD(10, 4) -> 2
   
   POWER : M의 N승을 계산한다
           POWER(M, N)
           POWER(2, 4) -> 16
   
   CEIL : M보다 큰 가장 작은 정수를 찾는다
          CEIL(M)
          CEIL(2.34) -> 3
          
   FLOOR : M보다 작은 가장 큰 정수를 찾는다
           FLOOR(M)
           FLOOR(2.34) -> 2
   
   ABS : M의 절대값을 계산한다
         ABS(M)
         ABS(-4) -> 4
  
   SQRT : M의 제곱근을 계산한다(루트)
          SQRT(M)
          SQRT(9) -> 3
          
   SIGN : M이 음수일 때 -1, 양수일 때 1, 0이면 0을 반환한다(부호)
          SIGN(M)
          SIGN(-3) -> -1
          
--1) ROUND 함수를 사용
SELECT ROUND(98.765), TRUNC(98.765),
ROUND(98.765, 2), TRUNC(98.765, 2)
FROM DUAL;

--2) MOD 함수를 사용
SELECT MOD(19, 3), MOD(-19, 3)
FROM DUAL;

--3) 10번 부서의 연봉을 계산한다. 단 100 단위 미만은 절삭한다
SELECT ENO, ENAME, TRUNC(SAL*12+NVL(COMM,0), -2) 연봉
FROM EMP
WHERE DNO = '10';

--<날짜 함수>
--4) 현재 날짜를 검색하고 날짜 출력 양식을 수정하세요
SELECT SYSDATE
FROM DUAL;

ALTER SESSION SET NLS_DATE_FORMAT = 'YYYY/MM/DD:HH24:MI:SS';
ALTER SESSION SET NLS_DATE_FORMAT = 'YYYY/MM/DD';

--5) 오늘 날짜, 입사 일자, 입사일로부터 오늘까지 기간, 입사일 이후
-- 100일이 지난날 등을 검색하세요
SELECT SYSDATE, HDATE, SYSDATE-HDATE, HDATE+100
FROM EMP
WHERE ENAME = '김연아';

<날짜 함수>
; 사용빈도가 높다
YYYY : 년도
MM : 월
DD : 날짜
HH : 시간
MI : 분
SS : 초

ROUND : 형식에 맞추어 반올림한 날짜를 반환한다
        ROUND(날짜, 형식)
        ROUND(SYSDATE, 'DD') -> 2020/09/11
TRUNC : 형식에 맞추어 절삭한 날짜를 반환한다
        TRUNC(날짜, 형식)
        TRUNC(SYSDATE, 'DD') -> 2020/09/10
        TRUNC(SYSDATE, 'YYYY') -> 2020/01/01
MONTHS_BETWEEN : 두 날짜간의 기간을 월 수로 계산한다
        MONTHS_BETWEEN(날짜1, 날짜2)
        MONTHS_BETWEEN('2020/06/01', '2020/09/10')
ADD_MONTHS : 날짜에 N달을 더한 날짜를 계산한다
        ADD_MONTHS(날짜, N)
        ADD_MONTHS('2020/06/01', 5)
NEXT_DAY : 날짜 이후 지정된 요일에 해당하는 날짜를 계산한다
        NEXT_DAY(날짜, 요일)
        요일 표현은 'SUN', '일요일', 1 과 같이 다양한 표현이 가능하다
        NEXT_DAY('2020/09/10', '1')
LAST_DAY : 날짜를 포함한 달의 마지막 날짜를 계산한다
        LAST_DAY(날짜)
        LAST_DAY('2020/09/10') -> 2020/09/30

--6) 숫자와 날짜를 반올림하거나 절삭하여 출력하세요
SELECT SYSDATE, ROUND(SYSDATE, 'YY') 년,
ROUND(SYSDATE, 'MM') 월, ROUND(SYSDATE, 'DD') 일
FROM DUAL;

SELECT SYSDATE, TRUNC(SYSDATE, 'YY') 년,
TRUNC(SYSDATE, 'MM') 월, TRUNC(SYSDATE, 'DD') 일
FROM DUAL;

--7) 김연아가 오늘까지 일한 일수를 검색하세요
-- +1을 더한 이유
--홍길동이 1일~10일까지 일했을 때 일한 일수는?
--(10-1) + 1 = 10일 일함
SELECT TRUNC(SYSDATE, 'DD') - TRUNC(HDATE, 'DD')+1 "일한 일수"
FROM EMP
WHERE ENAME = '김연아';

--8) 20번 부서 사원들이 현재까지 근무한 개월 수를 검색하세요
SELECT ENO, ENAME, TRUNC(MONTHS_BETWEEN(SYSDATE, HDATE)) 근무개월
FROM EMP
WHERE DNO = '20';

--9) 20번 부서 사원들이 입사 100일째 되는 날과 10년째 되는 날을 구하세요
SELECT ENO, ENAME, HDATE 입사일,
HDATE+99 "100일", ADD_MONTHS(HDATE, 120) "10년"
FROM EMP
WHERE DNO = '20';

--10) 20번 부서원들이 입사한 이후 첫 번째 일요일을 검색하세요
SELECT ENO, ENAME, HDATE, NEXT_DAY(HDATE, '일요일') SUNDAY
FROM EMP
WHERE DNO = '20';

--11) 10번 부서원들의 입사한 달의 마지막 날짜와 입사한 달의 
-- 근무 일수를 검색하세요 (단, 입사일은 근무일에서 제외합니다)
SELECT ENO, ENAME, HDATE, LAST_DAY(HDATE) 마지막날,
LAST_DAY(TRUNC(HDATE))-TRUNC(HDATE) "마지막달 근무일수"
FROM EMP
WHERE DNO = '20';