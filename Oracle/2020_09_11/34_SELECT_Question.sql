--<서브 쿼리를 사용하세요>
--1) 관우보다 평점이 우수한 학생의 학번과 이름을 검색하세요
SELECT SNO 학번, SNAME 이름
FROM STUDENT
WHERE AVR > (SELECT AVR
            FROM STUDENT
            WHERE SNAME = '관우');

--2) 관우와 동일한 학년 학생 중에 평점이 사마감과 동일한 학생을 검색하세요
SELECT SNAME 이름
FROM STUDENT
WHERE SYEAR = (SELECT SYEAR
              FROM STUDENT
              WHERE SNAME = '관우')
AND AVR = (SELECT AVR
          FROM STUDENT
          WHERE SNAME = '사마감');

--3) 관우보다 일반 화학과목의 학점이 더 낮은 학생의 명단을 학점과 검색하세요
SELECT SNAME 이름, RESULT 학점
FROM SCORE
JOIN STUDENT USING(SNO)
JOIN COURSE USING(CNO)
WHERE RESULT < (SELECT RESULT
                FROM SCORE
                JOIN STUDENT USING(SNO)
                JOIN COURSE USING(CNO)
                WHERE SNAME = '관우'
                AND CNAME = '일반화학')
AND CNAME = '일반화학';

--4) 인원수가 가장 많은 학과를 검색하세요
SELECT MAJOR, COUNT(MAJOR)
FROM STUDENT
GROUP BY MAJOR
HAVING COUNT(MAJOR) >= (SELECT MAX(COUNT(MAJOR))
                      FROM STUDENT
                      GROUP BY MAJOR);

--5) 학생 중 기말고사 성적이 가장 낮은 학생의 정보를 검색하세요
SELECT *
FROM STUDENT
JOIN SCORE USING(SNO)
WHERE RESULT = (SELECT MIN(RESULT)
                FROM SCORE);