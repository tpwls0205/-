--<단일 행 함수를 이용하세요>
--1) 교수들이 부임한 달에 근무한 일수는 몇 일인지 검색하세요
SELECT PNAME 교수명, HIREDATE, LAST_DAY(HIREDATE),
LAST_DAY(TRUNC(HIREDATE))-TRUNC(HIREDATE)
FROM PROFESSOR;

--2) 교수들의 오늘까지 근무한 주가 몇 주인지 검색하세요
SELECT PNAME 교수명,
TRUNC(MONTHS_BETWEEN(SYSDATE, HIREDATE))*4 "근무한 주"
FROM PROFESSOR;

--3) 1991년에서 1995년 사이에 부임한 교수를 검색하세요 (다른 형식으로 해야함)
SELECT PNAME 교수명, HIREDATE 부임날짜
FROM PROFESSOR
WHERE HIREDATE >= '1991/01/01'
AND HIREDATE <= '1995/12/31';

--4) 학생들의 4.5 환산 평점을 검색하세요(단 소수 이하 둘째자리까지)
SELECT SNAME 학생명, TRUNC((AVR/8)*9, 2)
FROM STUDENT;
