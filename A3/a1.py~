#!bin/user/python
#This is just remebering GOD before starting: JOY BABA LOKNATH,JOY SHREE GANESHA, JOY SHREE KRISHNA
#the only difference in this submission for "Assignment 1b" is the handling of EOF and stderror
#modified for Assignment 3 now r command works differently..as we are told to remove previous graph when rgen send "r"
import sys
line=raw_input()
flag=0
y=[]
s={}
V={}
E=()
ver=set()
def find_intersection(x11,y11,x12,y12,x21,y21,x22,y22):
   try:
		
	m1=c1=m2=c2=0
	inter_x=inter_y=0

	if((x12-x11)!=0 and (x22-x21)!=0):
		m1=(y12-y11)/(x12-x11)
		c1=y11-m1*x11
		m2=(y22-y21)/(x22-x21)
		c2=y21-m2*x21
		if((m1-m2)!=0):        		
			inter_x=(c2-c1)/(m1-m2)
			inter_y=m1*inter_x+c1
			str1=str(x11)+","+str(y11)
			str2=str(x12)+","+str(y12)
			str3=str(x21)+","+str(y21)
			str4=str(x22)+","+str(y22)
			str5=str(inter_x)+","+str(inter_y)
			if(V!={}):			
				 
				 for m in V.keys():
				  if str5 not in ver:
					find_intersection.count+=1		
				        find_intersection.v5=str(find_intersection.count)		 
					V[find_intersection.v5]=(inter_x,inter_y)
					ver.add(str5)
					
 				  if str1 not in ver:
					find_intersection.count+=1
					find_intersection.v1=str(find_intersection.count)
					V[find_intersection.v1]=(x11,y11)
					ver.add(str1)
					
                                  if str2 not in ver:
					find_intersection.count+=1
					find_intersection.v2=str(find_intersection.count)
					V[find_intersection.v2]=(x12,y12)
					ver.add(str2)
					
				  if str3 not in ver:
					find_intersection.count+=1
					find_intersection.v3=str(find_intersection.count)
					V[find_intersection.v3]=(x21,y21)
					ver.add(str3)
					
				  if str4 not in ver:
					find_intersection.count+=1
					find_intersection.v4=str(find_intersection.count)
					V[find_intersection.v4]=(x22,y22)
			          	ver.add(str4)
					
					
		        else:
				  
	                	  find_intersection.count+=1
				  find_intersection.v1=str(find_intersection.count)
				  V[find_intersection.v1]=(x11,y11)
				  ver.add(str1)
				  
				  find_intersection.count+=1
				  find_intersection.v2=str(find_intersection.count)
				  V[find_intersection.v2]=(x12,y12)
				  ver.add(str2)
				  
				  find_intersection.count+=1
				  find_intersection.v3=str(find_intersection.count)
				  V[find_intersection.v3]=(x21,y21)
			          ver.add(str3)
				  
			 	  find_intersection.count+=1
				  find_intersection.v4=str(find_intersection.count)
				  V[find_intersection.v4]=(x22,y22)
				  ver.add(str4)
				  
				  find_intersection.count+=1
				  find_intersection.v5=str(find_intersection.count)
				  V[find_intersection.v5]=(inter_x,inter_y)
				  ver.add(str5)
				  
	
			E.add("<"+find_intersection.v5+","+find_intersection.v1+">")
			E.add("<"+find_intersection.v5+","+find_intersection.v2+">")
			E.add("<"+find_intersection.v5+","+find_intersection.v3+">")
			E.add("<"+find_intersection.v5+","+find_intersection.v4+">")
	if(x12==x11 and x21!=x22 and abs(y12-y11)>=abs(y22-y21)):
		m2=(y22-y21)/(x22-x21)
		c2=y21-m2*x21
					
		inter_x=x12
		
		inter_y=m2*x12+c2
		str1=str(x11)+","+str(y11)
		str2=str(x12)+","+str(y12)
		str3=str(x21)+","+str(y21)
		str4=str(x22)+","+str(y22)
		str5=str(inter_x)+","+str(inter_y)
		if(V!={}):
		   
		   for m in V.keys():
				  if str5 not in ver:
					find_intersection.count+=1		
				        find_intersection.v5=str(find_intersection.count)		 
					V[find_intersection.v5]=(inter_x,inter_y)
					ver.add(str5)
					
 				  if str1 not in ver:
					find_intersection.count+=1
					find_intersection.v1=str(find_intersection.count)
					V[find_intersection.v1]=(x11,y11)
					ver.add(str1)
					
                                  if str2 not in ver:
					find_intersection.count+=1
					find_intersection.v2=str(find_intersection.count)
					V[find_intersection.v2]=(x12,y12)
					ver.add(str2)
					
				  if str3 not in ver:
					find_intersection.count+=1
					find_intersection.v3=str(find_intersection.count)
					V[find_intersection.v3]=(x21,y21)
					ver.add(str3)
					
				  if str4 not in ver:
					find_intersection.count+=1
					find_intersection.v4=str(find_intersection.count)
					V[find_intersection.v4]=(x22,y22)
			          	ver.add(str4)
					
					
		else:
				  
	                	  find_intersection.count+=1
				  find_intersection.v1=str(find_intersection.count)
				  V[find_intersection.v1]=(x11,y11)
				  ver.add(str1)
				  
				  find_intersection.count+=1
				  find_intersection.v2=str(find_intersection.count)
				  V[find_intersection.v2]=(x12,y12)
				  ver.add(str2)
				  
				  find_intersection.count+=1
				  find_intersection.v3=str(find_intersection.count)
				  V[find_intersection.v3]=(x21,y21)
			          ver.add(str3)
				  
			 	  find_intersection.count+=1
				  find_intersection.v4=str(find_intersection.count)
				  V[find_intersection.v4]=(x22,y22)
				  ver.add(str4)
				  
				  find_intersection.count+=1
				  find_intersection.v5=str(find_intersection.count)
				  V[find_intersection.v5]=(inter_x,inter_y)
				  ver.add(str5)
				
	
		E.add("<"+find_intersection.v5+","+find_intersection.v1+">")
		E.add("<"+find_intersection.v5+","+find_intersection.v2+">")
		E.add("<"+find_intersection.v5+","+find_intersection.v3+">")
		E.add("<"+find_intersection.v5+","+find_intersection.v4+">")		
	if(x21==x22 and x11!=x12 and abs(y22-y21)>=abs(y12-y11)):
		
		m1=(y12-y11)/(x12-x11)
		c1=y11-m1*x11
		print x21
		print x22			
		inter_x=x21
		inter_y=m1*x21+c1
		str1=str(x11)+","+str(y11)
		str2=str(x12)+","+str(y12)
		str3=str(x21)+","+str(y21)
		str4=str(x22)+","+str(y22)
		str5=str(inter_x)+","+str(inter_y)
		if(V!={}):
		   for m in V.keys():
				  if str5 not in ver:
					find_intersection.count+=1		
				        find_intersection.v5=str(find_intersection.count)		 
					V[find_intersection.v5]=(inter_x,inter_y)
					ver.add(str5)
					
 				  if str1 not in ver:
					find_intersection.count+=1
					find_intersection.v1=str(find_intersection.count)
					V[find_intersection.v1]=(x11,y11)
					ver.add(str1)
					
                                  if str2 not in ver:
					find_intersection.count+=1
					find_intersection.v2=str(find_intersection.count)
					V[find_intersection.v2]=(x12,y12)
					ver.add(str2)
					
				  if str3 not in ver:
					find_intersection.count+=1
					find_intersection.v3=str(find_intersection.count)
					V[find_intersection.v3]=(x21,y21)
					ver.add(str3)
					
				  if str4 not in ver:
					find_intersection.count+=1
					find_intersection.v4=str(find_intersection.count)
					V[find_intersection.v4]=(x22,y22)
			          	ver.add(str4)
					
					
		else:
				  
	                	  find_intersection.count+=1
				  find_intersection.v1=str(find_intersection.count)
				  V[find_intersection.v1]=(x11,y11)
				  ver.add(str1)
				  
				  find_intersection.count+=1
				  find_intersection.v2=str(find_intersection.count)
				  V[find_intersection.v2]=(x12,y12)
				  ver.add(str2)
				  
				  find_intersection.count+=1
				  find_intersection.v3=str(find_intersection.count)
				  V[find_intersection.v3]=(x21,y21)
			          ver.add(str3)
				  
			 	  find_intersection.count+=1
				  find_intersection.v4=str(find_intersection.count)
				  V[find_intersection.v4]=(x22,y22)
				  ver.add(str4)
				  
				  find_intersection.count+=1
				  find_intersection.v5=str(find_intersection.count)
				  V[find_intersection.v5]=(inter_x,inter_y)
				  ver.add(str5)
				  
	
		E.add("<"+find_intersection.v5+","+find_intersection.v1+">")
		E.add("<"+find_intersection.v5+","+find_intersection.v2+">")
		E.add("<"+find_intersection.v5+","+find_intersection.v3+">")
		E.add("<"+find_intersection.v5+","+find_intersection.v4+">")

	if(y12==y11 and y21!=y22 and abs(x12-x11)>=abs(x22-x21)):
				
		m2=(y22-y21)/(x22-x21)
		c2=y21-m2*x21
		inter_y=y11
		inter_x=(inter_y-c2/m2)
		str1=str(x11)+","+str(y11)
		str2=str(x12)+","+str(y12)
		str3=str(x21)+","+str(y21)
		str4=str(x22)+","+str(y22)
		str5=str(inter_x)+","+str(inter_y)
		if(V!={}):
		   for m in V.keys():
				  if str5 not in ver:
					find_intersection.count+=1		
				        find_intersection.v5=str(find_intersection.count)		 
					V[find_intersection.v5]=(inter_x,inter_y)
					ver.add(str5)
					
 				  if str1 not in ver:
					find_intersection.count+=1
					find_intersection.v1=str(find_intersection.count)
					V[find_intersection.v1]=(x11,y11)
					ver.add(str1)
					
                                  if str2 not in ver:
					find_intersection.count+=1
					find_intersection.v2=str(find_intersection.count)
					V[find_intersection.v2]=(x12,y12)
					ver.add(str2)
					
				  if str3 not in ver:
					find_intersection.count+=1
					find_intersection.v3=str(find_intersection.count)
					V[find_intersection.v3]=(x21,y21)
					ver.add(str3)
					
				  if str4 not in ver:
					find_intersection.count+=1
					find_intersection.v4=str(find_intersection.count)
					V[find_intersection.v4]=(x22,y22)
			          	ver.add(str4)
					
					
		else:
				  
	                	  find_intersection.count+=1
				  find_intersection.v1=str(find_intersection.count)
				  V[find_intersection.v1]=(x11,y11)
				  ver.add(str1)
				  
				  find_intersection.count+=1
				  find_intersection.v2=str(find_intersection.count)
				  V[find_intersection.v2]=(x12,y12)
				  ver.add(str2)
				  
				  find_intersection.count+=1
				  find_intersection.v3=str(find_intersection.count)
				  V[find_intersection.v3]=(x21,y21)
			          ver.add(str3)
				  
			 	  find_intersection.count+=1
				  find_intersection.v4=str(find_intersection.count)
				  V[find_intersection.v4]=(x22,y22)
				  ver.add(str4)
				  
				  find_intersection.count+=1
				  find_intersection.v5=str(find_intersection.count)
				  V[find_intersection.v5]=(inter_x,inter_y)
				  ver.add(str5)
				  
	
		E.add("<"+find_intersection.v5+","+find_intersection.v1+">")
		E.add("<"+find_intersection.v5+","+find_intersection.v2+">")
		E.add("<"+find_intersection.v5+","+find_intersection.v3+">")
		E.add("<"+find_intersection.v5+","+find_intersection.v4+">")

	if(y22==y21 and y11!=y12 and abs(x22-x21)>=abs(x11-x12)):
				
		m1=(y12-y11)/(x12-x11)
		c1=y11-m1*x11
		inter_y=y22
		inter_x=(inter_y-c1/m1)
		str1=str(x11)+","+str(y11)
		str2=str(x12)+","+str(y12)
		str3=str(x21)+","+str(y21)
		str4=str(x22)+","+str(y22)
		str5=str(inter_x)+","+str(inter_y)
		if(V!={}):
		   for m in V.keys():
				  if str5 not in ver:
					find_intersection.count+=1		
				        find_intersection.v5=str(find_intersection.count)		 
					V[find_intersection.v5]=(inter_x,inter_y)
					ver.add(str5)
					
 				  if str1 not in ver:
					find_intersection.count+=1
					find_intersection.v1=str(find_intersection.count)
					V[find_intersection.v1]=(x11,y11)
					ver.add(str1)
					
                                  if str2 not in ver:
					find_intersection.count+=1
					find_intersection.v2=str(find_intersection.count)
					V[find_intersection.v2]=(x12,y12)
					ver.add(str2)
					
				  if str3 not in ver:
					find_intersection.count+=1
					find_intersection.v3=str(find_intersection.count)
					V[find_intersection.v3]=(x21,y21)
					ver.add(str3)
					
				  if str4 not in ver:
					find_intersection.count+=1
					find_intersection.v4=str(find_intersection.count)
					V[find_intersection.v4]=(x22,y22)
			          	ver.add(str4)
					
					
		else:
				  
	                	  find_intersection.count+=1
				  find_intersection.v1=str(find_intersection.count)
				  V[find_intersection.v1]=(x11,y11)
				  ver.add(str1)
				  
				  find_intersection.count+=1
				  find_intersection.v2=str(find_intersection.count)
				  V[find_intersection.v2]=(x12,y12)
				  ver.add(str2)
				  
				  find_intersection.count+=1
				  find_intersection.v3=str(find_intersection.count)
				  V[find_intersection.v3]=(x21,y21)
			          ver.add(str3)
				  
			 	  find_intersection.count+=1
				  find_intersection.v4=str(find_intersection.count)
				  V[find_intersection.v4]=(x22,y22)
				  ver.add(str4)
				  
				  find_intersection.count+=1
				  find_intersection.v5=str(find_intersection.count)
				  V[find_intersection.v5]=(inter_x,inter_y)
				  ver.add(str5)
				  
	
		E.add("<"+find_intersection.v5+","+find_intersection.v1+">")
		E.add("<"+find_intersection.v5+","+find_intersection.v2+">")
		E.add("<"+find_intersection.v5+","+find_intersection.v3+">")
		E.add("<"+find_intersection.v5+","+find_intersection.v4+">")
	
	else:
		return
		
   except:
	print >> sys.stderr, 'Error: Your input were not in correct format'

def replace(ck,cv):
   try:	
	flag1=0	
	if(s!={}):	
		for key1 in s.keys():
			if key1==ck:		
				s[key1]=[cv]
				flag1=1				
				break			
		if(flag1==0):	
			print >> sys.stderr, 'Error:The street name you mentioned to change is not present'
	else:
		print >> sys.stderr, 'Error: The Street List is Empty'
   except: 
	print >> sys.stderr, 'Error: You are Have missplaced input format'
	
	
def remove():
    try:	

	
	if(s!={}):
		for key2 in s.keys():		
				del s[key2]	        	
			
		
	else:
		print >> sys.stderr, "Error: The Street List is Empty"
    except:
	print >> sys.stderr, "Error: You are trying to missplaced input format"
def graph():
     try:
    	point=[]
	if(s!={}):	
		for key3 in s.keys():
			street=[]
	                p=""       
			street.append(s[key3])	
			for k in range(0,len(street)):
				temp=street[k]
				
                        	for l in range(0,len(temp[k])):
                         		if(temp[k][l].find('(')==0 or temp[k][l].find(')')==0) :   
						gurbage=0
					elif(temp[k][l].find(" ")==0):
						p=p+","
					else:
						p=p+temp[k][l]	
						
			
			point.append(p.split(','))
		
		for c in range(0,len(point),1):
						
			for d in range(0,len(point[c])-2,2):
								
				x11=float(point[c][d])
				y11=float(point[c][d+1])
				x12=float(point[c][d+2])
				y12=float(point[c][d+3])
				for f in range(c+1,len(point),1):
						
					for h in range(0,len(point[f])-2,2):				 
						 							
						x21=float(point[f][h])
						y21=float(point[f][h+1])
						x22=float(point[f][h+2])
						y22=float(point[f][h+3])
						#find_intersection.count=-1
						find_intersection(x11,y11,x12,y12,x21,y21,x22,y22)
				
	else:
		print >> sys.stderr, 'Error: You did not enter the Street Names and Points yet'
     except:
	print >> sys.stderr, 'Error: Not a Valid Specification found'	

while True:
	find_intersection.count=-1
	try:
	  x=line.splitlines()		
		
	  for i in range(0,len(x)):
		
		y.append(x[i])
                for j in range(0,len(y)):
	        	
			if(y[j][0]=='a'):
				r=y[j].index('"')+1
				l=y[j].index('(')-2	        
        			key=y[j][r:l]
                                for key1 in s.keys():
				  if key1==key:
				    print >> sys.stderr, "Error: This is already present"		 
	                            break	
				
				value=y[j][l+2:len(y[j])]
				s[key]=[value]
			
			elif(y[j][0]=='c'):
				r=y[j].index('"')+1
				l=y[j].index('(')-2	        
        			key=y[j][r:l]
				value=y[j][l+2:len(y[j])]
				replace(key,value)

			elif(y[j][0]=='r'):
				remove()
			elif(y[j][0]=='g'):
				#find_intersection.count=-1
				V={}
				E=set()		
				ver=set()		
				graph()
				print "V",find_intersection.count+1				
				Eout=list(E)		
				edge="E {"
				for e in range(0,len(Eout)):
					if e == len(Eout)-1:
						edge+=Eout[e]+"}"
					else:
						edge+=Eout[e]+","
				
				print edge
			else:
				print >> sys.stderr, 'Error: Wrong Command'
	        
	  line=raw_input()
          y=[]
	except EOFError:	
		sys.exit(0)
        except:
	        print >> sys.stderr, 'Error: You Did not enter input in a valid way'
                  
	  	line=raw_input()
                y=[]


