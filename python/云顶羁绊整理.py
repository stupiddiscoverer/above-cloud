import time

try:
    txt1 = ''
    with open('c:/users/children/desktop/云顶.txt',encoding = 'utf-8') as f:
        for line in f:
            txt1 = txt1 + line

    txt2 = ''
    with open('c:/users/children/desktop/所有英雄羁绊.txt',encoding = 'utf-8') as f:
        for line in f:
            txt2 = line

    txt3 = ''
    i = 0
    while i<59:
        i += 1
        t1 = '第'+str(i)+'页：'
        t2 = str(i)+'号'
        len1 = 4
        len2 = 2
        if i>9:
            len1 += 1
            len2 += 1
        count1 = 0
        count2 = 0
        blank = 0
        for a in txt1:
            if count1 == len1:
                if a == '第':
                    break
                txt3 += a
                continue 
            if a == t1[count1]:
                count1 += 1
            else:
                count1 = 0
        txt3 += ' '
        for a in txt2:
            if count2 == len2:
                if a == ' ':
                    blank += 1
                if blank == 2:
                    blank = 0
                    break
                txt3 += a
                continue
            if a == t2[count2]:
                count2 += 1
            else:
                count2 = 0
        txt3 += '\n'
    print(txt3)
    with open('c:/users/children/desktop/最终.txt','w') as f:
        f.write(txt3)
        f.close()
        
except Exception as e:
    print(e)

time.sleep(3)
