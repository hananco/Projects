# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
#
# import  json
# from urllib.request import urlopen
# def jsonUrl():
#     with open("C:/Users/hanan/PycharmProjects/pythonProject7/j.json") as f:
#         jsonObject = json.load(f)
#     jsonObject["key6"]="hi!"
#     newData =dict(name ="hanan",lastName = "hanan")
#     jsonObject.update(newData)
#
#     with open("C:/Users/hanan/PycharmProjects/pythonProject7/j.json",'w') as f:
#         json.dump(jsonObject,f, indent=2)
#
#     with open("C:/Users/hanan/PycharmProjects/pythonProject7/j.json") as f:
#         jsonObject = json.load(f)
#         print(jsonObject)
#
#
# def fib(n):
#     a,b=0,1
#
#     for i in range(n):
#         a,b=b,a+b
#     print(b)
#
# def checkFib(number):
#     a,b=0,1
#     while b < number:
#         a, b = b, a + b
#         if b == number:
#             print("fib")
#
# import requests
# def fatch():
#     response = requests.get('https://randomuser.me/api')
#     if 199< response.status_code < 300:
#         print(response.json())
#         first_name =response.json()['results'][0]['name']['first']
#         last_name =response.json()['results'][0]['name']['last']
#         loc = response.json()['results'][0]['location']['city']
#         print(f'full name :{first_name} {last_name}')
#     else:
#         print("ERROR")
#
# def listComprehension():
#     squares =[ i**2  for i in range(1,6) if i%2 ==0]
#     print(squares)
#
#     yearsMove =[("h" ,200),("a",100),("e",250)]
#     moveBigerThen200 = [(titel,year) for(titel,year) in yearsMove if year < 250 ]
#     print(moveBigerThen200)
#
#     A =[1,3,5,7]
#     B = [2,4,6,8]
#     cartesian_product = [a*b for a in A for b in B]
#     print(cartesian_product)
#
#     my_dict ={a:b for a,b in zip(A,B)}
#     print(my_dict )
#
#
#     m = [1,1,1,2,3,5,5,6]
#     my_set = {n for n in m }#do aset in list
#     print(my_set)
#
#
#     for number in  yieldSquer(A):
#         print(number,end='  ')
#
# def yieldSquer(A):
#     for i in range(len(A)):
#         yield A[i]**2
#
# def f(func):
#     def wrapper(*args ,**kwargs):
#         print("Started")
#         val = func(*args ,**kwargs)
#         print("Ended")
#         return val
#     return wrapper
#
# @f
# def addDicotators(x,y):
#     return x+y
#
# @f
# def f1(a,b):
#     print(a,b)
#
# def reversList():
#     a=[x for x in range(10)]
#     b=[x *5 if x %3==0  else x for x in range(10)]
#     c=list (reversed(b))
#     d=a[len(a):0:-1]
#     e=a[-1:0:-2]
#     e+=b[1:-1:3]
#
# def findingMaxChar(find, listLetter):
#     listWord = list(listLetter.split(" "))
#     sum =0
#     index =0
#     maxSum ={'index':0,"sumOfLetter": 0 }
#     for word in listWord:
#         for letter in range(len(word)):
#             if word[letter] == find:
#                 sum += 1
#         if sum > maxSum["sumOfLetter"]:
#             maxSum.update({'index' : index , 'sumOfLetter':sum})
#
#         sum = 0
#         index +=1
#     if maxSum["sumOfLetter"] > 0:
#         print(listWord, (maxSum["index"], maxSum["sumOfLetter"]))
#     else:
#         print("didnt  find this letter")
#
#
# def maxLetter2(find,listLetter):
#     listLetter=listLetter.replace(' ','')
#     sum = 0
#     index = 0
#     maxSum = {'index': 0, "sumOfLetter": 0}
#     for x in range(len(listLetter)):
#         if listLetter[x] == find:
#             sum +=1
#             if sum == 1:
#                 index = x
#     if sum > maxSum["sumOfLetter"]:
#         maxSum.update({'index' : index , 'sumOfLetter':sum})
#     print(listLetter, maxSum)
#
# def maxLetterInSentens(sentens):
#     dicLetter ={}
#     maxSum =0
#
#     listLetter = sentens.replace(' ', '')
#     for letter in listLetter:
#         dicLetter.setdefault(letter, 0)
#         dicLetter[letter] += 1
#     sum = 0
#     for letter ,sum in dicLetter.items() :
#         if sum >maxSum:
#             maxSum = sum
#             maxLetter = letter
#     print(maxLetter , maxSum)



if __name__ == '__main__':

    #jsonUrl()
    #fib(5 )
    #checkFib(20)
    #fatch()
    #listComprehension()
    # print(addDicotators(4,5))
    # f1("hi you" , 9)
    # reversList()
    sentens = "hanan cohen"

    # findingMaxChar("h" , sentens)
    # findingMaxChar2("a" , sentens)
    # maxLetterInSentens(sentens)

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
