import os
import requests     #导入requests包
import time

def search(txt):
	result = ''
	coin = '<p>　　费用：'
	fetter = '<p>　　羁绊：'
	count = 0
	for a in txt:
		if count == 8:
			if a == '<':
				count = 0
				result = result + ' '
				continue
			result = result + a
			continue
		if a == coin[count]:
			count = count+1
		else:
			if a == fetter[count]:
				count = count+1
			else:
				count = 0
	return result
		
if __name__ == '__main__':
	url = 'https://gl.ali213.net/html/2020-9/489139_'
	try:
		allHero = ""
		i = 2
		while i<59:
			url_x = url + str(i) + '.html'
			print(url_x)
			i = i+1
			html = requests.get(url_x, timeout=200).content
			txt = str(html,'utf-8')
			allHero = allHero + str(i-1)+'号' +search(txt)
			print(allHero)
		with open('c:/users/children/desktop/所有英雄羁绊.txt','w') as f:
			f.write(allHero)
			f.close()
	except Exception as e:
		print(e)
	time.sleep(10)