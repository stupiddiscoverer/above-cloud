# txt = ''
# with open('c:/users/children/desktop/最终.txt',encoding = 'utf-8') as f:
#     for line in f:
#         for a in line:
#             if a == '\n':
#                 txt += ' '
#             txt += a
#     f.close()

# print(txt)
# with open('c:/users/children/desktop/最终.txt','w') as f:
#     f.write(txt)
#     f.close()
heroList = []
with open('c:/users/children/desktop/最终.txt',encoding = 'utf-8') as f:
    for line in f:
        txt = ''
        tup = []
        for a in line:
            if a == ' ' or a == '+':
                if txt == '':
                    continue
                tup.append(txt)
                txt = ''
                continue
            txt += a
        if tup == []:
            continue
        heroList.append(tup)
    f.close()

# fetterList = []
# for hero in heroList:
#     j = -1
#     while hero[j][1] != "费":
#         has = 0
#         for fetter in fetterList:
#             if fetter[0] == hero[j]: #hero[j]羁绊名,fetter[0]存放羁绊名，后面是英雄名
#                 fetter.append(hero[0]) #hero[0]英雄名
#                 has += 1
#                 break
#         if has == 0:
#             x = [hero[j],hero[0]]
#             fetterList.append(x)
#         j -= 1

number = []
with open('c:/users/children/desktop/数量.txt',encoding='utf-8') as f:
    for line in f:
        num = []
        txt = ''
        i = 0
        for a in line:
            if a == ' ' or a == '\n':
                if txt == '':
                    continue
                if i == 0:
                    num.append(txt)
                    i = 1
                else:
                    num.append(int(txt))
                txt = ''
            txt += a
        number.append(num)

def C(n,nList,i):
    if n<1:
        D(nList)
        return
    while i<58:
        nList.append(heroList[i])
        i += 1
        C(n-1,nList,i)
        nList.remove(nList[-1])
    return

def D(nList):
    nFetter = []
    fets = 0
    sfet = 0
    for hero in nList:
        i = 0
        for a in hero:
            i += 1
            if i<3:
                continue
            sfet += 1
            no = True
            for fet in nFetter:
                if a == fet[0]:
                    fet[1] += 1
                    no = False
                    break
            if no == True:
                nFetter.append([a,1])

    for a in nFetter:
        for b in number:
            if a[0] == b[0]:
                i = 0
                for x in b:
                    if i == 0:
                        i = 1
                        continue
                    if a[1] >= x:
                        i += 1
                        continue
                    break
                if i>1:
                    fets += b[i-1]
                break
    allTxt = ''

    if fets == sfet:
        txt = '羁绊数：'+str(fets)+' '
        for a in nFetter:
            for b in a:
                allTxt += str(b)+' '
            allTxt += ' '
        allTxt += '\n'
        for a in nList:
            txt += a[0]+' '
        allTxt += txt+'\n'
        print(allTxt)
        with open('c:/users/children/desktop/hero789.txt','a',encoding='utf-8') as f:
            f.write(allTxt)
    return

C(9,[],0)