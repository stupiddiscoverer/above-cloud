import _thread
import sys
import time

def C(i):
    with open('c:/users/children/desktop/atommm.txt','a',encoding='utf-8') as f:
        print('opened and sleeping ',i)
        time.sleep(1)
        print('writing:'+str(i))
        f.write(str(i)+'*****\n')
#先打开文件，再写入，仍然没有覆盖，说明写入是原子性操作

if __name__ == '__main__':
    try:
        i = 0
        while i<4:
            _thread.start_new_thread(C,(i,))
            print('start thread',i)
            i += 1
    except Exception as e:
        print(e)

    time.sleep(20)