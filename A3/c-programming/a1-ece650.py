#!/usr/bin/python
#
import sys

#################################################################
class Street:
   StreetNum = 0

   def __init__(self, name, points,intersection,ind):
      self.name = name
      self.cord = points
      self.intersec=intersection
      self.index=ind
      Street.StreetNum += 1

class Vertex:
   VertexNum=0
   def __init__(self,number, point):
      self.num=number
      self.cord=point
      Vertex.VertexNum+=1

class Edge:
   EdgeNum=0
   def __init__(self, number,x,y):
	self.num=number
	self.u=x
	self.v=y
	Edge.EdgeNum+=1
##################################################################
def readname(command):
  second=0
  index=0
  ii=[0]
  for char in command:
	index+=1	
	if char=='"':
		ii.extend([index])
		second+=1
	if second==2:
		break
  c=command[ii[1]:index-1]
  return c
##################################################################
def Findcord(point):
  index=0
  i_1=0
  i_2=0
  p=[]
  count=0
  errorflag=0
  digitflag=0
  for char in point:
	index=index+1
	if char.isdigit()==True and digitflag==0:
	   digitflag=1
	   if point[index-2]=='-':
		i_1=index-2
	   else:
		i_1=index-1
	if char.isdigit()==False and digitflag==1:
		i_2=index-1
		x=point[i_1:i_2]
		x1=float(x)
		p.append(x1)
		i_1=0
		i_2=0
		digitflag=0
		count+=1
  if count > 2:
	print >> sys.stderr, "Error: coordination points must be 2 by 2"
 	errorflag=1
  return (p,errorflag)

##################################################################
def readpoints(command):
  second=0  
  index=0
  p=[]
  error=0
  y1=0
  for char in command:
  	index+=1
	if char=='"':
		second+=1
	if second==2:
		break
#index points to the second " in the command
#now we should start reading the points
  indexpoint=index
  i_1=0
  i_2=0
  for char in command[indexpoint:]:
	index+=1
	if char=="(":
		i_1=index-1		
	if char==")" and i_1!=0:
		i_2=index
	if (i_1!=0 and i_2!=0):
		point=command[i_1:i_2]	
		i_1=0
		i_1=0
		i_2=0
		(x1,y1)=Findcord(point)
		p.append(x1)
	if y1==1:
		error=1
	if char=='\n':
		break
  return (p,error)
##################################################################
def check(Name,StreetAll):
  no=1
  index=0
  for Street in StreetAll:
	index+=1
	if Street.name==Name:
	    no=0
	    break	
  return (index-1, no)
##################################################################
def checkvertex(point,VertexAll):
  no=0
  index=0
  for vertex in VertexAll:
        index+=1
        if vertex.cord==point:
            no=1
            break
  if no==1:
	a=vertex.num
  else:
	a=0
  return (a, no)
##################################################################
def check_edge(x, y, EdgeAll):
  no=0
  for edge in EdgeAll:
        if (edge.u==x and edge.v==y) or (edge.u==y and edge.v==x):
            no=1
            break
  return no

##################################################################
def find_min(a,b):
  if a > b:
	y=b
  else:
	y=a
  return y
##################################################################
def find_max(a,b):
   if a > b:
	y=a
   else:
	y=b
   return y
##################################################################
def inside_check(x1,x2,x3,x4,x):
  if x >= find_min(x1,x2) and x <= find_max(x1,x2):
	if x >=find_min(x3,x4) and x <=find_max(x3,x4):
		a=1
	else:
		a=0
  else:
	a=0
  return a

##################################################################
def intersect(cord1,cord2):
  n1=len(cord1)
  n2=len(cord2)
  flag=0
  st1vertex=[] #intersection i is between st1vertex[i] and vertex[i+1]
  st2vertex=[] 
  intersect=[]
 # print cord1
  for i in range(0,n1-1):
	for j in range(0,n2-1):
	    [x1,y1]=cord1[i]
	    [x2,y2]=cord1[i+1]
	    [x3,y3]=cord2[j]
	    [x4,y4]=cord2[j+1]
	    if x1!=x2 and x3!=x4:
		 	m=(y1-y2)/(x1-x2)-(y3-y4)/(x3-x4)
			if m!=0:					
				x=(y3-y1+x1*((y1-y2)/(x1-x2))-x3*((y3-y4)/(x3-x4)))/m
			else:
				flag=1
	    elif x1!=x2:
			x=x3
	    elif x3!=x4:
	    		x=x1
	    else:
		    if x1==x3:
		        x=x1
		    else:
			flag=1
	    if flag==0:
		    if y1!=y2 and y3!=y4:
			m=(x3-x4)/(y3-y4)-(x1-x2)/(y1-y2)
			if m!=0:
				y=(x1-x3+y3*((x3-x4)/(y3-y4))-y1*((x1-x2)/(y1-y2)))/m
			else:
				flag=1	
		    elif y1!=y2:
			y=y3
		    elif y3!=y4:		
	    		y=y1
		    else:
		 	if y1==y3:
				y=y1
				flag=1
	    if flag==0:
			a=inside_check(x1,x2,x3,x4,x)
			b=inside_check(y1,y2,y3,y4,y)
			if a==1 and b==1:	
			    intersect.append([x,y])
			    st1vertex.append(i)
			    st2vertex.append(j)
	    flag=0
 # print(st1vertex, st2vertex, intersect)
 # st1vertex.append(-2000)
 # st2vertex.append(-2000)
  return (st1vertex, st2vertex, intersect)
##################################################################
def output(intersec,cord,index,VertexNumber):
			  n1=len(index)
 			  n2=len(cord)
			 # VertexNumber=len(VertexAll)+1
			  EdgeNumber=len(EdgeAll)+1	
			  for i in range(0,n1):	#sort according to index
				for j in range(0,n1-i-1):
					if index[j+1]<index[j]:
						a=index[j+1]
						b=index[j]
						index[j+1]=b
						index[j]=a
						a=intersec[j+1]
						b=intersec[j]
						intersec[j+1]=b
	   					intersec[j]=a
	   		  for j in range(0,len(index)):
		   		 for i in range(0,len(index)-1):
					if index[i]==index[i+1] and index[i]>-1:
						[x1,y1]=intersec[i]
						[x2,y2]=intersec[i+1]
					   	if x1==x2 and y1==y2:
							index.pop(i)
							intersec.pop(i)
							index.extend([-1000])
							intersec.extend("A")
					   	else:
							[a,b]=cord[index[i]]
							r1=(x1-a)*(x1-a)+(y1-b)*(y1-b)
							r2=(x2-a)*(x2-a)+(y2-b)*(y2-b)
							if r1>r2:
		   						a=intersec[i+1]
                       				 		intersec[i+1]=intersec[i]
                  				        	intersec[i]=a
		
######################constructing verteices######################!!!!!!!!!!!#############
			  p1=cord
			  count=0
		          flag_middle_vertex_i=0			  
			  index.insert(len(index),-2000)
			  index1=[]	
			  intersec1=[]
			  for k in index: 
				if k>-1:
					index1.extend([k])
					intersec1.extend([intersec[count]])
				count+=1
		      	  count=0			
			  intersec=intersec1
			  index1.insert(len(index1),-2000)
			  index=index1
			  for point in intersec:
			  	[useless, notexist]=checkvertex(point, VertexAll)
				[vertex_index, notexist_old]=checkvertex(point, VertexAll_old)
				if notexist_old==1:
					vertex_id=vertex_index
				elif notexist==0:
					vertex_id=VertexNumber
					VertexNumber+=1
				if notexist==0:
					v=Vertex(vertex_id, point)
					VertexAll.append(v)
				
				k1=index1[count]
			  	[useless, notexist]=checkvertex(p1[k1], VertexAll)
			  	[vertex_index, notexist_old]=checkvertex(p1[k1], VertexAll_old)
				if notexist_old==1:
					vertex_id=vertex_index
				elif notexist==0:
					vertex_id=VertexNumber
					VertexNumber+=1
				if notexist==0:
					v=Vertex(vertex_id, p1[k1])
					VertexAll.append(v)
					
                                [useless, notexist]=checkvertex(p1[k1+1], VertexAll)
                                [vertex_index, notexist_old]=checkvertex(p1[k1+1], VertexAll_old)
 				if notexist_old==1:
					vertex_id=vertex_index
				elif notexist==0:
					vertex_id=VertexNumber
					VertexNumber+=1
				if notexist==0:
                                        v=Vertex(vertex_id, p1[k1+1])
                                        VertexAll.append(v)
####################################################################Edges################################
				
				if flag_middle_vertex_i==0:	
					if index1[count]!=index1[count+1]:
						flag_middle_vertex=0
						[u,no]=checkvertex(p1[k1], VertexAll)
						[v,no]=checkvertex(point, VertexAll)	
						notexist=check_edge(u, v, EdgeAll)
						if notexist==0 and u!=v:
							e=Edge(EdgeNumber,u,v)	#first edge on street i
							EdgeNumber+=1
							EdgeAll.append(e)
					        [w,no]=checkvertex(p1[k1+1], VertexAll)
						notexist=check_edge(v,w, EdgeAll)
						if notexist==0 and w!=v:			
                                                	e=Edge(EdgeNumber,v,w)       
                                                	EdgeNumber+=1
                                                	EdgeAll.append(e)
					elif index1[count]==index1[count+1]:
						flag_middle_vertex=1
					        [u,no]=checkvertex(p1[k1], VertexAll)
                                                [v,no]=checkvertex(point, VertexAll)
                                                notexist=check_edge(u,v, EdgeAll)
                                                if notexist==0 and v!=u:
                                                        e=Edge(EdgeNumber,u,v)        
                                                        EdgeNumber+=1
                                                        EdgeAll.append(e)	
				elif flag_middle_vertex_i==1:
                                        if index1[count]!=index1[count+1]:
						flag_middle_vertex=0
                                                [u,no]=checkvertex(previous_point,VertexAll)
                                                [v,no]=checkvertex(point, VertexAll)
                                                notexist=check_edge(u,v, EdgeAll)
                                                if notexist==0 and u!=v:
                                                        e=Edge(EdgeNumber,u,v)        #first edge on street i
                                                        EdgeNumber+=1
                                                        EdgeAll.append(e)
                                                [w,no]=checkvertex(p1[k1+1], VertexAll)
                                                notexist=check_edge(v,w, EdgeAll)
                                                if notexist==0 and v!=w:
                                                        e=Edge(EdgeNumber,v,w)
                                                        EdgeNumber+=1
                                                        EdgeAll.append(e)
                                        elif index1[count]==index1[count+1]:
                                                flag_middle_vertex=1
                                                [u,no]=checkvertex(previous_point,VertexAll)
                                                [v,no]=checkvertex(point, VertexAll)
                                                notexist=check_edge(u,v, EdgeAll)
                                                if notexist==0 and u!=v:
                                                        e=Edge(EdgeNumber,u,v)
                                                        EdgeNumber+=1
                                                        EdgeAll.append(e)
				flag_middle_vertex_i=flag_middle_vertex
###################################################################################
				count+=1
		 		previous_point=point
			  return VertexNumber
##################################################################
Cont=True
notexist=0
StreetAll=[]
VertexAll=[]
EdgeAll=[]
VertexAll_old=[]
VertexNumber=1
EdgeNumber=1

while Cont== True:
	try:
		command= raw_input() 
	except (EOFError):
		break
	
	if command[0]=='a':
		Name=readname(command)
		(Points,error)=readpoints(command)
		[index, notexist]=check(Name, StreetAll)
		if notexist==1 and error==0:
	           St=Street(Name, Points,[],[])
		   StreetAll.append(St)
		elif error==0:
 		   print >> sys.stderr, "Errot: Street","'", Name,"'", "already exists, use commands 'c' or 'r' to modify it"

	elif command[0]=='c':
                Name=readname(command)
                (Points,error)=readpoints(command)
               	[index, notexist]=check(Name, StreetAll)
		if notexist==0 and error==0:
		   StreetAll[index].cord=Points
		else:
		   print >> sys.stderr, "Error: 'c' specified for a street that does not exist. Street","'", Name,"'", "does not exists"
		   notexist=0
	
	elif command[0]=='r':
                #Name=readname(command)
		#[index, notexist]=check(Name, StreetAll)
		#if notexist==0:
		for st in StreetAll:		 
		  	st.interSec=[]
			st.index=[]


		   #Street.StreetNum-=1	
        	#else:
                 #  print >> sys.stderr, "Error: 'r' used for a street that does not exist. Street", "'", Name,"'", "does not exists"
                  # notexist=0
	elif command[0]=='g':
		Stcount=Street.StreetNum
		for St in StreetAll:
			St.intersec=[]
			St.index=[]
		VertexAll_old.extend(VertexAll)
		VertexAll=[]
		EdgeAll=[]
		intersec_self=[]
		index_self=[]
                for i in range(0,Stcount):
		   for j in range (i+1,Stcount):
			  [index1, index2, intersec_i_j] =intersect(StreetAll[i].cord, StreetAll[j].cord)	#intersec_i_j means intersection of streets i and j
			  if len(index1)!=0:
			  	a=StreetAll[i].intersec
			  	a.extend(intersec_i_j)
			  	StreetAll[i].intersec=a
			 	b=StreetAll[j].intersec
			  	b.extend(intersec_i_j)
			  	StreetAll[j].intersec=b
			  	a=StreetAll[i].index
			  	a.extend(index1)
			  	StreetAll[i].index=a
			  	b=StreetAll[j].index
			  	b.extend(index2)
			  	StreetAll[j].index=b
		
		for St in StreetAll:	#self intersection part
		   n1=len(St.cord)
		   p=St.cord
		   if n1>2:
		     for i in range(0, n1-1):
		   	for j in range(i+1, n1-1):
				[index1, index2, intersec_i] =intersect(p[i:i+2],p[j:j+2])
				kount=0
				for point in intersec_i:
					if point!=p[i+1] or point!=p[j]:
						intersec_self.extend([point])
						intersec_self.extend([point])
						index_self.extend([i])
						index_self.extend([j])
					kount+=1
				a=St.intersec
			  	a.extend(intersec_self)
			  	St.intersec=a
			  	a=St.index
			  	a.extend(index_self)
			  	St.index=a
		        intersec_self=[]
			index_self=[]
		#################################################
		for St in StreetAll:
			VertexNumber=output(St.intersec,St.cord, St.index, VertexNumber)
		countv =0	
		stredge="E {"	
		for vertex in VertexAll:
			[x,y]=vertex.cord
			countv+=1;
		print "V",countv
		n=len(EdgeAll)
		if n!=0:
			for i in range(0,n-1):
				edge=EdgeAll[i]
				edge.u-=1
				edge.v-=1
				stredge+="<"+str(edge.u)+","+str(edge.v)+">"+","
			edge=EdgeAll[n-1]
			edge.u-=1
			edge.v-=1
			stredge+="<"+str(edge.u)+","+str(edge.v)+">"+"}"
		print stredge				   	      
	else:
 		print >> sys.stderr, 'Error: command not defined'
		
