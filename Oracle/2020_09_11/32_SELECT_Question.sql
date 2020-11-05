--1) 화학과를 제외하고 학생들의 평점 평균을 검색하세요
SELECT SNAME 학생이름, AVG(AVR) 평균평점
FROM STUDENT
WHERE MAJOR != '화학'
GROUP BY SNAME;

--2) 화학과를 제외한 각 학과별 평균 평점 중에 평점이 2.0 이상인 
--정보를 검색하세요
SELECT MAJOR 학과, AVG(AVR) 평균평점
FROM STUDENT
WHERE MAJOR != '화학'
GROUP BY MAJOR
HAVING AVG(AVR) >= 2.0;

--3) 기말고사 평균이 60점 이상인 학생의 정보를 검색하세요(학번과 기말고사 평균)
SELECT SNO 학번, AVG(RESULT)
FROM STUDENT
JOIN SCORE USING(SNO)
GROUP BY SNO
HAVING AVG(RESULT) >= 60;

--4) 강의 학점수가 3학점 이상인 교수의 정보를 검색하세요(교수번호, 이름과 담당 학점수)
SELECT PNO 교수번호, PNAME 이름, SUM(ST_NUM) "담당 학점수"
FROM PROFESSOR
NATURAL JOIN COURSE
GROUP BY PNO, PNAME
HAVING SUM(ST_NUM) >= 3;