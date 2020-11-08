# try:
#     print(4/0)
# except ZeroDivisionError as e:
#     print(e)

# try:
#     f = open("없는 파일.txt", "r")
# except FileNotFoundError as e:
#     print(str(e))
# else:
#     data = f.read()
#     f.close()

try:
    f = open('없는 파일.txt', 'r')
except FileNotFoundError as e:
    print(str(e))
finally:
    print("finally 구문 실행")
    f.close()