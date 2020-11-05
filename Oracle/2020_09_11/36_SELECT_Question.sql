--1) 화학과 학생과 평점이 동일한 학생들을 검색하세요
SELECT *
FROM STUDENT
WHERE AVR IN (SELECT AVR
              FROM STUDENT
              WHERE MAJOR = '화학')
AND MAJOR != '화학';

--2) 화학과 교수와 부임일이 같은 직원을 검색하세요
SELECT *
FROM PROFESSOR
WHERE HIREDATE IN (SELECT HIREDATE
                  FROM PROFESSOR
                  WHERE SECTION = '화학')
AND SECTION != '화학';                  

--3) 화학과 학생과 같은 학년에서 평점이 동일한 학생들을 검색하세요
SELECT *
FROM STUDENT
WHERE (SYEAR, AVR) IN (SELECT SYEAR, AVR
                      FROM STUDENT
                      WHERE MAJOR = '화학')
AND MAJOR != '화학';                      