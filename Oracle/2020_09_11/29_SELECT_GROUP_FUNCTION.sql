<그룹 함수>
; 통계정보 계산시 자주 사용되는 함수
보통 여러 개의 행에서 계산되거나 추출하는 값을 제공하는 함수
A)
MAX : 값들 중에 최대 값을 반환한다
      MAX(컬럼)
MIN : 값들 중에 최소 값을 반환한다
      MIN(컬럼)
AVG : 평균 값을 계산한다
      AVG(컬럼)
COUNT : 반환된 행의 수를 계산한다
      COUNT(컬럼|*)
SUM : 합계를 계산한다
      SUM(컬럼)
STDDEV : 표준편차를 계산한다
      STDDEV(컬럼)
VARIANCE : 분산을 계산한다
      VARIANCE(컬럼)
B) 
  NULL 값은 무시된다
  반드시 단 하나의 값만을 반환한다
  GROUP BY 설정 없이 일반 컬럼과 기술될 수 없다.
  
--1) 사원의 급여 평균을 검색한다.
SELECT AVG(SAL) 평균급여, ROUND(AVG(SAL)) 평균급여
FROM EMP;

--2) 사원들에게 지급된 보너스 총합과 보너스 평균을 검색하세요
SELECT SUM(COMM) 총액, ROUND(AVG(COMM)) 평균, 
COUNT(COMM) 수령인원,
ROUND(AVG(NVL(COMM,0))) 환산평균, COUNT(*) 전체인원
FROM EMP;

SELECT COUNT(*)
FROM EMP
WHERE COMM IS NOT NULL;

SELECT COUNT(*)
FROM EMP
WHERE COMM IS NULL;

SELECT COUNT(*)
FROM EMP;

<그룹 함수와 GROUP BY 절>

3) 평균 급여와 평균 연봉을 검색하세요
SELECT ROUND(AVG(SAL)) 평균급여,
ROUND(AVG(SAL*12+NVL(COMM,0))) 평균연봉
FROM EMP;

4) 부서별 평균 급여와 평균 연봉을 검색하세요
SELECT DNO, ROUND(AVG(SAL)) 평균급여,
ROUND(AVG(SAL*12+NVL(COMM,0))) 평균연봉
FROM EMP;

카디널리티가 차이가 있어서 오류가 발생한다
카디널리티(Cadinality) : 결과 행의 개수

14개의 결과가 나온다
SELECT DNO
FROM EMP;

1개의 결과가 나온다
SELECT ROUND(AVG(SAL)) 평균급여,
ROUND(AVG(SAL*12+NVL(COMM,0))) 평균연봉
FROM EMP;

5) 부서별 평균 급여와 평균 연봉을 검색하세요
부서별 : GROUP BY DNO
그룹함수와 함께 사용되는 일반 컬럼은
반드시 GROUP BY 절에 사용되어야 한다
SELECT DNO, ROUND(AVG(SAL)) 평균급여,
ROUND(AVG(SAL*12+NVL(COMM,0))) 평균연봉
FROM EMP
GROUP BY DNO;

6) 업무별 평균 급여와 평균 연봉을 검색하세요
SELECT JOB, ROUND(AVG(SAL)) 평균급여,
ROUND(AVG(SAL*12+NVL(COMM,0))) 평균연봉
FROM EMP
GROUP BY JOB;

7) 부서별 평균연봉을 구하세요(부서번호와 부서명까지 출력하세요)
SELECT D.DNO, DNAME, ROUND(AVG(SAL*12+NVL(COMM,0))) 평균연봉
FROM DEPT D, EMP E
WHERE D.DNO = E.DNO
GROUP BY D.DNO, DNAME;

8) 부서별 급여 평균의 최대값과 최소값을 검색하세요
GROUP BY DNO에 의해 DNO는 카디널리티가 7개이다
그리고 GROUP BY DNO와 함께 사용되는 AVG(SAL)도 카디널리티가 7개이다
그러나 MAX(AVG(SAL))은 부서중에 최대값을 추출하는 것이므로
카디널리티가 1개이다
그러므로 아래의 SQL 문은 카디널리티의 불일치로 인해 오류가 발생한다
그래서 이 문제는 '서브쿼리'를 이용해야 한다
SELECT DNO, MAX(AVG(SAL)) 최대, MIN(AVG(SAL)) 최소
FROM EMP
GROUP BY DNO;