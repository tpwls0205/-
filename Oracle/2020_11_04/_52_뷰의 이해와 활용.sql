<뷰의 이해와 활용>
; 뷰(view)는 논리적으로 하나의 테이블 또는 여러 테이블의
논리적인 부분집합을 의미한다.
 사용자/응용 프로그램은 뷰를 통해서 뷰의 기반이 되는 테이블의
정보에 접근 할 수 있다.
 뷰는 가상테이블이라 할 수 있다.
 뷰는 물리적인 공간을 차지하는 테이블은 아니지만
 테이블과 유사하게 사용된다.
 뷰는 주로 READ ONLY 속성을 통해 읽기 전용으로 주로 사용된다.

<뷰의 종류>
1) 단순 뷰(simple view)
  1-1) 단일 table 로부터 만들어진 view
  1-2) 함수나 수식등을 포함하지 않고 단순 컬럼으로만 구성된다
  1-3) DML 문장 수행이 가능하다.
2) 복합 뷰(complex view)
  1-1) 다중 table 로부터 만들어진 view
  1-2) 함수나 수식등을 포함한다
  1-3) DML 문장 수행이 불가능하다
  1-4) 보안을 강화하기 위해
       사용자/응용프로그램이 직접 테이블에 접근/변경하는 
       것을 방지하기 위해 사용된다.

<뷰 생성과 확인>
CREATE [ON REPLACE][FORCE|NOFORCE] VIEW 뷰명(컬럼...)
AS (SELECT 문 : sub query 문);
[WITH CHECK OPTION [CONSTRAINT constraint_name]]
[WITH READ ONLY [CONSTRAINT constraint_name]];
1) 뷰를 생성한다
2) 서브 쿼리를 이용한 테이블 생성문장과 유사하다
3) ON REPLACE : 뷰를 수정한다
  - 동일한 이름의 뷰를 삭제하고 새로 생성한다
  - ALTER VIEW 명령을 대체한다
4) FORCE : 기반 테이블이 없어도 뷰가 생성된다.
  - 기본 값은 NOFORCE 이다.
5) WITH CHECK OPTION: 뷰에 의해서 검색 가능한 행만
    DML 작업이 가능하도록 제약한다.
6) WITH READ ONLY : 뷰를 통해서는 SELECT 만 가능하도록
    제한한다. 많이 사용한다.
    
<뷰의 장점>
1) 복잡한 쿼리를 단순화
2) Table의 직접 접근을 방지
   사용자가 Table의 구성을 알 수 없게 한다
   (필요정보만 노출)
   보안성 향상
3) 필요한 정보로만 View 를 구성하므로
   어플리케이션 개발이 심플해진다.
    

--각 일반화학 과목의 학과별 기말고사 평균을 검색하고 뷰로 생성한다.
SELECT c.cno, cname, major, AVG(result)
FROM student s, course c, score r
WHERE s.sno=r.sno AND r.cno=c.cno
AND cname='일반화학'
GROUP BY c.cno, cname, major;

CREATE VIEW ma_result(과목번호, 과목명, 학과, 기말평균)
AS SELECT c.cno, cname, major, AVG(result)
   FROM student s, course c, score r
   WHERE s.sno=r.sno AND r.cno=c.cno
   AND cname='일반화학'
   GROUP BY c.cno, cname, major;
  
서브 쿼리를 이용한 테이블은 물리적인 테이블을 만들어서
새로 데이터를 추출/입력하므로
나중에 테이블간의 데이터의 오류가 발생할 수 있다.
학생 10명의 평균을 추출해서 테이블을 만들었는데
시간이 흘러서 학생이 100명으로 증가하면 테이블의 평균은
전체 학생의 평균과 달라지게 된다.
'무결성의 오류'가 발생하게 된다.

그런데 View를 사용하면 물리적인 Table 을 만드는 것이 아닌
View를 검색할 때 View 에 정의된 기반 테이블을 검색해서
가져오는 것이므로 '무결성'이 보장되게 된다.

1) 서브쿼리를 이용한 테이블 생성
  ; 해당 시점의 통계/데이터를 저장하기 위해서 사용
    다 사용했으면 지우는 것도 고려해야 한다.
2) 뷰를 이용한 기존 테이블 접근
  ; 시간에 따라 자동으로 뷰에서 검색되는 데이터도 변경되므로
    어플리케이션에서 사용하면 된다.
SELECT * FROM ma_result;


--WITH CHECK OPTION 을 이용해서 뷰를 생성한다
CREATE VIEW st_ch
AS SELECT sno, sname, syear, avr
   FROM student
   WHERE syear=1;

--뷰를 통해 student 테이블에 저장된다.
--하지만 뷰는 1학년만 보여주게 되어 있다.
INSERT INTO st_ch 
VALUES ('000001', '홍길동', 2, 4.0);

SELECT * FROM st_ch WHERE sname='홍길동';
SELECT * FROM student WHERE sname='홍길동';
ROLLBACK;

--이제는 1학년만 삽입할 수 있다.
CREATE VIEW st_ch
AS SELECT sno, sname, syear, avr
   FROM student
   WHERE syear=1
   WITH CHECK OPTION CONSTRAINT view_st_ch_ck;
    
INSERT INTO st_ch
VALUES ('000001', '홍길동', 2, 4.0);
    
CREATE VIEW st_ch2
AS SELECT sno, sname, syear, avr
   FROM student
   WHERE syear=1
   WITH READ ONLY CONSTRAINT view_st_ch2_ck;    
    
INSERT INTO st_ch2
VALUES ('000001', '홍길동', 1, 4.0);    
    
    
    
    
    
    
  
  
  
  
  
  
  
  


























