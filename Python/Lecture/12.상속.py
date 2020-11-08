# python은 클래스가 static이다
class HousePark:
    lastname = "박"  # 클래스 소속 변수

    def __init__(self, name):
        self.fullname = self.lastname + name  # self.fullname : 객체 멤버 변수

    def travel(self, where):
        print("%s, %s 여행을 가다" % (self.fullname, where))

    def love(self, other):
        print("%s, %s 사랑에 빠졌네" % (self.fullname, other.fullname))

    def __add__(self, other):
        print("%s, %s 결혼했네" % (self.fullname, other.fullname))

    def __sub__(self, other):
        print("__sub__ 하면 %s, %s 이렇게 나옵니다" % (self.fullname, other.fullname))


class HouseKim(HousePark):
    lastname = "김"

    def travel(self, where, day):
        print("%s, %s 여행 %d일 가네." % (self.fullname, where, day))


pey = HousePark("보영")
juliet = HouseKim("태희")
pey.love(juliet)
pey + juliet
