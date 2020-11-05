--1) 성적순으로 학생의 이름을 검색하라
SELECT SNO 생년월일, SNAME 이름, AVR 학점
FROM STUDENT
ORDER BY AVR DESC;

--2) 학과별 성적순으로 학생의 정보를 검색하라
SELECT SNO 생년월일, SNAME 이름, MAJOR 학과, AVR 학점
FROM STUDENT
ORDER BY 학과, 학점 DESC;

--3) 학년별 성적순으로 학생의 정보를 검색하라
SELECT SNO 생년월일, SNAME 이름, SYEAR 학년, AVR 학점
FROM STUDENT
ORDER BY 학년, 학점 DESC;

--4) 학과별 학년별로 학생의 정보를 성적순으로 검색하라
SELECT SNO 생년월일, SNAME 이름, MAJOR 학과, SYEAR 학년
FROM STUDENT
ORDER BY 학과, 학년;

--5) 학점순으로 과목 이름을 검색하라
SELECT AVR 학점, MAJOR 과목
FROM STUDENT
ORDER BY 학점 DESC, 과목 ASC;

--6) 각 학과별로 교수의 정보를 검색하라
SELECT SECTION 학과, ORDERS 지위, PNAME 이름
FROM PROFESSOR
ORDER BY 학과;

--7) 지위별로 교수의 정보를 검색하라
SELECT SECTION 학과, ORDERS 지위, PNAME 이름
FROM PROFESSOR
ORDER BY 지위;

--8) 각 학과별로 교수의 정보를 부임일자 순으로 검색하라
SELECT SECTION 학과, ORDERS 지위, PNAME 이름, HIREDATE 부임일자
FROM PROFESSOR
ORDER BY 부임일자;

