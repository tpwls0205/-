# 파이썬의 자료구조형 자료형
# 1) 리스트 : [1, 2, 3, 4]
#         순서가 있는 선형구조
#         삽입, 삭제
# 2) 튜플 : (1, 2, 3, 4)
#         순서가 있는 선형구조
#         읽기 전용 리스트
# 3) 셋 : {1, 2, 3, 4}
#         집합, 순서가 없음
#         숫자 중복이 안됨
# 4) 딕셔너리 : 맵
#         키 : 값

# a = [1,2,3]
# print(a)
# print(type(a))
# print(a[0])
# a = ['홍길동', '임꺽정', '장길산', '차돌바위', '일지매', '전우치']
# print(a[1:3])
# b = ['Henry', 'Albert', 'James']
# c = a+b
# print(c)
# print(b*3)
# b[1] = 'Alex'
# print(b)
# del b[1]
# print(b)
# b.remove('Henry')
# print(b)

# a = [1,2,3]
# print(a)
# a.append(4)
# print(a)
# a.append(9)
# a.append(7)
# print(a)
# a.sort()
# print(a)
# a.reverse()
# print(a)

# a = [1, 2, 3, 1, 1, 3, 7]
# print(a.count(1))

# 튜플 : 읽기 전용 리스트
# a = (1, 2, 3)
# print(a)
# print(type(a))
# # del a[0] -> 예외가 발생
# print(a[1])
# b = (4,5,6)
# c = a+b
# print(c)
# print(b*2)

# 셋 : 집합, 순서가 없다, 중복허용 안됨
# a = {1, 2, 3}
# print(a, type(a))
# b = {2, 3, 4, 5}
# # c = a+b -> 예외가 발생
# print(a&b) # 교집합
# print(a|b) # 합집합
# print(a-b) # 차집합
# print(a.intersection(b)) # 교집합
# print(a.union(b)) # 합집합
# print(a.difference(b)) # 차집합

# a = 10
# b = 20
# a, b = b, a
# print(a, b)

# 리스트 <-> 튜플 <-> 셋 간의 자유로운 상호변환
# a = ('홍길동', '임꺽정')
# print(a, type(a))
# # a.append("장길산") 튜플은 삽입이 안됨
# l = list(a)
# print(l, type(l))
# l.append("장길산")
# a = tuple(l)
# print(a, type(a))

# a = ['홍길동', '임꺽정', '홍길동']
# print(a, type(a))
# s = set(a)
# print(s, type(s))
# a = list(s)
# print(a, type(a))

# 딕셔너리 : 검색에 최적화
# a = {"name" : "홍길동", "age" : 24, "height" : 174.3}
# print(a, type(a))
# print(a["name"])
# print(a["age"])
# print(a["height"])
#
# b = {}
# c = set()
# print(b, type(b))
# print(c, type(c))
# b["이름"] = "홍길동"
# print(b)
#
# a = ['홍길동', 24, 174.5]
# b = ['임꺽정', 33, 189.5]
# c = ['장길산', 34, 175.6]
# d = {}
# d["Hong"] = a
# d["Lim"] = b
# d["Jang"] = c
# print(d["Jang"])