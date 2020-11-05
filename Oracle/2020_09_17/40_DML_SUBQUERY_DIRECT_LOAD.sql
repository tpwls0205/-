<서브쿼리를 이용한 DML 문>
INSERT INTO [/*+APPEND */] 테이블 [NOLOGGING] [(컬럼, 컬럼, ...)]
SELECT 문;
1) SELECT 문에 의해 검색된 행을 입력값으로 사용한다
2) 한 번에 많은 행을 입력할 수 있다
3) 컬럼 리스트와 SELECT 문의 컬럼이 1:1로 대응되어야 한다
4) SELECT 문에 사용한 서브 쿼리 문과는 달리 괄호르 쓰지 않는다
5) /*+ APPEND */ : 다이렉트 로드(대량 작업의 속도 향상)
6) [NOLOGGING] : 로그 정보를 남기지 않음으로 입력작업이 빨라진다
                 그러나 장애 발생시 복구할 수 없다.
7) 다이렉트 로드 : 일반적인 DML 처리는 오라클의 메모리에 임시 저장하였다가
                 나중에 디스크에 저장하는데 메모리에 저장하는 중간과정을
                 없애고 바로 디스크에 저장하는 것을 말한다

UPDATE 테이블
 SET 컬럼명 = (SELECT 문),
     컬럼명 = (SELECT 문), ...
 [WHERE 조건];
 
UPDATE 테이블
 SET (컬럼, 컬럼, ...) = (SELECT 문)
  [WHERE 조건];
A) UPDATE 문의 SET 절에는 단일 행 서브쿼리 문이나 다중 열 서브쿼리문을
   이용할 수 있다.
   - 다중 열인 경우도 반드시 결과 행은 하나여야 한다.
B) 이 때 검색되는 DATA 는 반드시 수정되는 컬럼명과 1:1 대응되어야 한다
C) SET 절에는 단일행 서브쿼리만 허용되지만 WHERE 절의 서브쿼리는
   연산자에 따라 달라진다.
   
--1) EMP2 테이블에 사번과 연봉을 입력하세요   
DESC EMP2;
SELECT * FROM EMP2;

INSERT INTO EMP2(ENO, ASAL)
SELECT ENO, SAL*12+NVL(COMM,0)
FROM EMP;

SELECT * FROM EMP2;

입력 데이터의 타입이 일치하지 않으면 오류가 발생한다
INSERT INTO EMP2(ENO, ASAL)
SELECT ENO, HDATE
FROM EMP;
INSERT INTO EMP2(ENO, ASAL)
SELECT ENO, ENAME
FROM EMP;

2) 각 사원의 정보와 근무지를 EMP3 테이블에 저장하세요
DESC EMP3;
SELECT * FROM EMP3;

<다이렉트 로드>
다이렉트 로드로 입력했을 때는 트랜잭션을 완료하지 않으면 검색되지 않는다
INSERT /*+APPEND */ INTO EMP3 NOLOGGING (ENO, ENAME, DNO, DNAME)
SELECT ENO, ENAME, D.DNO, DNAME
FROM EMP E, DEPT D
WHERE D.DNO = E.DNO;

COMMIT;

SELECT * FROM EMP3;

--SELECT 작업이나 DML 작업은 모두 메모리에서 이루어진다
--오라클은 SGA 라는 메모리 영역 내에 데이터베이스 버퍼 캐시(DATABASE)
--(DATABASE BUFFER CACHE)라는 영역을 이들 작업 공간으로 이용한다
--이를 통해 디스크 접근 회수와 양을 줄여 성능을 향상시킨다
--그러나 일괄적인 대량의 DML 작업이 메모리에서 일어나면 이를 디스크에서
--반영하고 다시 메모리를 정리하는 등의 비효율이 발생한다
--이를 피하기 위해 대량 DML 작업에서는 메모리를 통하지 않고 디스크에
--직접 작업을 수행하는 것을 다이렉트 로드(Direct Load)라고 한다
--DML 작업으 다이렉트 로드하기 위해서는 '/*+ APPEND */'를 문장에 삽입한다
--
--그리고 오라클은 안전한 시스템 운영을 위해 장애 발생 시 복구할 수 있도록
--DB에 변경을 가하는 모든 작업의 내역을 리두 로그(Redo log)영역에
--로그정보로 보관한다. 그러나 대량의 DML 작업은 작업의 효율을 위해 이를
--수행하지 않을 수 있다. 작업 성능을 위해 로그 정보를 남기지 않는다면
--'NOLOGGING'옵션을 이용한다. 그러나 이렇게 복구가 불가능하도록 작업한
--이후에는 장애에 대비한 백업을 잊지 않아야 한다. 대량의 작업에서 다이렉트
--로그와 노로깅방식을 이용하면 작업 성능은 비약적으로 빨라지지만 작업의
--안전도는 떨어질 수 밖에 없다.
--
--다이렉트 로드 후에는 COMMIT 처리를 해야 검색할 수 있다.
--COMMIT 으로 트랜잭션을 마무리 하지 않고 검색하면 'ORA-12838'
--에러를 만난다. 이 에러는 입력데이터의 손상을 방지하기 위한 기능이다.
--
--<서브 쿼리를 이용한 UPDATE 문을 수행한다>

--3) 윤고은의 급여와 보너스를 각각 김연아의 급여와 양선호의 보너스와
--   동일하게 수정하세요
UPDATE EMP
 SET SAL = (SELECT SAL FROM EMP WHERE ENAME='김연아'),
     COMM = (SELECT COMM FROM EMP WHERE ENAME='안영숙')
 WHERE ENAME = '윤고은';
 
SELECT ENAME, SAL, COMM FROM EMP WHERE ENAME = '윤고은';
SELECT * FROM EMP WHERE ENAME IN ('윤고은','김연아','안영숙');
   
4) 제갈민과 동일한 부서의 사원들의 급여를 제갈민의 급여와 동일하게
   수정하세요
UPDATE EMP
 SET SAL = (SELECT SAL FROM EMP WHERE ENAME = '제갈민')
 WHERE DNO = (SELECT DNO FROM EMP WHERE ENAME = '제갈민');

SELECT * FROM EMP
WHERE DNO = (SELECT DNO FROM EMP WHERE ENAME = '제갈민');

5) 이초록의 급여와 보너스를 김연아와 동일하게 수정하세요
UPDATE EMP
 SET (SAL, COMM) = (SELECT SAL, COMM FROM EMP WHERE ENAME='김연아')
 WHERE ENAME='이초록';

아래처럼 단일 행 서브쿼리로 바꿀 수 있지만 서브쿼리를 여러 번 수행함으로
(즉, 테이블 스캔을 여러 번 하므로) 성능이 보다 떨어진다
UPDATE EMP
 SET SAL = (SELECT SAL FROM EMP WHERE ENAME='김연아'),
     COMM = (SELECT COMM FROM EMP WHERE ENAME='김연아')
 WHERE ENAME = '이초록';

SELECT * FROM EMP
WHERE ENAME IN ('김연아', '이초록');