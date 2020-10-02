import json
import os

f = open('dic.json')
dic = json.load(f)

for k, v in dic.items():
	name = '{} {}'.format(len(v), k)
	os.mkdir(name)
	os.chdir(name)
	for x in v:
		p = x[1]
		number = x[0][1:]
		p = p.replace('\r\n', '\n').replace('\u03c0', 'pi').replace('\u2212', '-').replace('\u2217', '*').replace('\u2192', '->').replace('\u203d','?!')
		try:
			f = open(number, "w")
			f.write(p)
			f.close()
		except Exception as e:
			print(f"From {name}, Number is {x[0]}")
			print(e)
	os.chdir('..')	
	
