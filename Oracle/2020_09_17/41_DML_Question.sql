1) 일반 화학 과목을 수강하는 학생의 성적을 4.5만점 기준으로 수정하세요
UPDATE STUDENT
 SET AVR = (AVR/8) * 9
 WHERE 
 

2) 화학과 교수의 과목 중에 학점이 3학점 미만인 과목을 모두 3학점으로
   수정한 다음 이를 확인하세요
3) 학생의 기말고사 성적을 모두 st_score 테이블에 저장하세요.
  st_score테이블 구조는 직접 파악해 보세요