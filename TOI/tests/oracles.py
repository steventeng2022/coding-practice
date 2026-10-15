import contextlib,heapq,io,itertools,json,math,random,sys,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
TOI=ROOT
tasks=json.loads((TOI/'manifest.json').read_text(encoding='utf-8'))
tasks={t['id'].split('/')[-1]:t for t in tasks if t['python']}
namespaces={}
for name,t in tasks.items():
 ns={'__name__':'tested_module'}
 exec(compile((TOI/t['python']).read_text(encoding='utf-8'),t['python'],'exec'),ns)
 namespaces[name]=ns
rng=random.Random(20261016)
counts={}
failures=[]
def check(name,inp,expected):
 old=sys.stdin
 sys.stdin=io.TextIOWrapper(io.BytesIO(inp.encode()),encoding='utf-8')
 out=io.StringIO()
 try:
  with contextlib.redirect_stdout(out):namespaces[name]['main']()
  actual=out.getvalue()
 except Exception as error:actual=type(error).__name__+': '+str(error)
 finally:sys.stdin=old
 counts[name]=counts.get(name,0)+1
 if actual.split()!=str(expected).split():
  failures.append({'name':name,'input':inp,'expected':str(expected),'actual':actual})
  if len(failures)>20:raise RuntimeError(failures[-1])

def lines(*rows):return '\n'.join(' '.join(map(str,r)) if isinstance(r,(tuple,list)) else str(r) for r in rows)+'\n'
def bfs_grid(a,m,n,start):
 seen={start};q=[start]
 for p in q:
  r,c=divmod(p,n)
  for rr,cc in ((r-1,c),(r+1,c),(r,c-1),(r,c+1)):
   to=rr*n+cc
   if 0<=rr<m and 0<=cc<n and a[to] and to not in seen:seen.add(to);q.append(to)
 return seen

def main():
 # Exhaustive lexicographic oracle for constrained words.
 from functools import lru_cache
 for a,b,c in itertools.product(range(5),repeat=3):
  if not a+b+c:continue
  for k in range(1,4):
   @lru_cache(None)
   def best(count,prev,run):
    if not sum(count):return ''
    for d in (2,1,0):
     if count[d] and (d!=prev or run<k):
      nxt=list(count);nxt[d]-=1
      suffix=best(tuple(nxt),d,run+1 if d==prev else 1)
      if suffix is not None:return chr(65+d)+suffix
    return None
   answer=best((a,b,c),-1,0)
   check('BABA',lines((a,b,c,k)),answer if answer is not None else 'No Solution')
 for trial in range(120):
  n=rng.randint(1,8);m=rng.randint(0,30);a=[rng.randint(0,20) for _ in range(n)]
  heap=[-(x-i) for i,x in enumerate(a) if x>i];heapq.heapify(heap);ans=0
  for _ in range(m):
   if not heap:break
   v=-heapq.heappop(heap);ans+=v
   if v>1:heapq.heappush(heap,1-v)
  check('Mining',lines((n,m),a),ans)
  h,w=rng.randint(1,4),rng.randint(1,4);g=[[rng.randrange(2) for _ in range(w)] for _ in range(h)]
  rectangles=[(0,0)]
  for r1 in range(h):
   for r2 in range(r1,h):
    for c1 in range(w):
     for c2 in range(c1,w):
      cells=[r*w+c for r in range(r1,r2+1) for c in range(c1,c2+1)]
      if all(g[p//w][p%w] for p in cells):rectangles.append((sum(1<<p for p in cells),len(cells)))
  for k in (1,2):
   answer=max(v for _,v in rectangles)
   if k==2:answer=max(x+y for mask,x in rectangles for mask2,y in rectangles if not mask&mask2)
   check('Plant2',lines((h,w,k),*g),answer)
  n=rng.randint(2,10);points=[(rng.randint(-5,5),rng.randint(-5,5)) for _ in range(n)]
  answer=sum(x+xx>=0 and y+yy>=0 for i,(x,y) in enumerate(points) for xx,yy in points[i+1:])
  check('Singing',lines(n,*points),answer)
  values=[rng.randint(-2,5) for _ in range(n)];low,high=sorted((rng.randint(-2,5),rng.randint(-2,5)))
  answer=sum(min(values[i:j])==low and max(values[i:j])==high for i in range(n) for j in range(i+1,n+1))
  check('Ski',lines((n,low,high),values),answer)
  a=[rng.randint(1,10) for _ in range(n)];k=rng.randint(1,6)
  answer=[next((j+1 for j in range(i+1,n) if a[j]>=a[i]+k),-1) for i in range(n)]
  check('Stocks',lines((n,k),a),' '.join(map(str,answer)))
  # One-dimensional weighted LCS checked against a full table.
  a,b=[rng.randint(1,9) for _ in range(n)],[rng.randint(1,9) for _ in range(n)]
  dp=[[0]*(n+1) for _ in range(n+1)]
  for i in range(1,n+1):
   for j in range(1,n+1):dp[i][j]=max(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]+min(a[i-1],b[j-1]))
  check('Pipe',lines(n,a,b),dp[n][n])
  # Partitioned 0/1 knapsack oracle: enumerate every subset.
  groups=rng.randint(1,3);budget=rng.randint(1,15);cap=rng.randint(1,3)
  menu=[[(rng.randint(1,budget),rng.randint(1,10)) for _ in range(rng.randint(1,3))] for _ in range(groups)]
  flat=[(i,c,v) for i,g in enumerate(menu) for c,v in g];answer=0
  for mask in range(1<<len(flat)):
   chosen=[item for i,item in enumerate(flat) if mask>>i&1]
   if sum(c for _,c,_ in chosen)<=budget and all(sum(i==g for i,_,_ in chosen)<=cap for g in range(groups)):
    answer=max(answer,sum(v for _,_,v in chosen))
  rows=[(groups,budget,cap)]
  for g in menu:rows+=[len(g),*g]
  check('Buffet',lines(*rows),answer)
  # Bridges checked by physically removing each edge and counting reachable beads.
  n=rng.randint(3,10);edges={(i,rng.randrange(i)) for i in range(1,n)}
  edges={tuple(sorted(e)) for e in edges}
  for _ in range(n):
   a,b=sorted(rng.sample(range(n),2));edges.add((a,b))
  edges=sorted(edges);answers=[]
  for removed in edges:
   graph=[[] for _ in range(n)]
   for a,b in edges:
    if (a,b)!=removed:graph[a].append(b);graph[b].append(a)
   seen={0};queue=[0]
   for u in queue:
    for v in graph[u]:
     if v not in seen:seen.add(v);queue.append(v)
   answers.append(len(seen))
  check('BeadedCharm',lines((n,len(edges),len(edges)),*edges,*edges),' '.join(map(str,answers)))
  # Dial shortest paths versus independent heap Dijkstra.
  rows,cols=rng.randint(2,5),rng.randint(2,5);g=[rng.choice([-1,0,0,1,3,9]) for _ in range(rows*cols)];g[0]=g[-1]=0
  distance={(0,d):0 for d in range(4)};pq=[(0,0,d) for d in range(4)];heapq.heapify(pq);answer=-1
  while pq:
   cost,p,d=heapq.heappop(pq)
   if distance[p,d]!=cost:continue
   if p==len(g)-1:answer=cost;break
   r,c=divmod(p,cols)
   for nd,(rr,cc) in enumerate(((r,c+1),(r+1,c),(r,c-1),(r-1,c))):
    np=rr*cols+cc
    if 0<=rr<rows and 0<=cc<cols and g[np]>=0:
     nc=cost+g[np]+(d!=nd)
     if nc<distance.get((np,nd),10**9):distance[np,nd]=nc;heapq.heappush(pq,(nc,np,nd))
  check('Driving',lines((rows,cols),*[g[i*cols:(i+1)*cols] for i in range(rows)]),answer)
  # Install order uniqueness, by enumerating topological permutations.
  n=rng.randint(2,6);order=rng.sample(range(n),n)
  edges=[(order[i],order[j]) for i in range(n) for j in range(i+1,n) if rng.random()<0.3]
  ways=0
  for perm in itertools.permutations(range(n)):
   pos={v:i for i,v in enumerate(perm)}
   if all(pos[a]<pos[b] for a,b in edges):ways+=1
   if ways>1:break
  check('Dependency',lines((n,len(edges)),*[(a+1,b+1) for a,b in edges]),int(ways>1))
  # Tiny XOR systems checked by enumerating all room choices.
  n=rng.randint(1,6);clues=[]
  for _ in range(rng.randint(1,12)):
   a,b=rng.randrange(n),rng.randrange(n);sa,sb=rng.choice('LR'),rng.choice('LR');r=rng.choice('SD');clues.append((a,sa,b,sb,r))
  valid=any(all((((mask>>a&1)^(sa=='R'))^((mask>>b&1)^(sb=='R')))==(r=='D') for a,sa,b,sb,r in clues) for mask in range(1<<n))
  check('A3-Escape',lines((n,len(clues)),*[f'{a+1}{sa} {b+1}{sb} {r}' for a,sa,b,sb,r in clues]),'Easy Peasy' if valid else 'Impossible')
  # Permutation rank for small complete populations.
  m=rng.randint(2,7);n=rng.randint(1,m);perm=tuple(rng.sample(range(1,m+1),n))
  answer=sum(p<perm for p in itertools.permutations(range(1,m+1),n))
  check('Permutation',lines((n,m),perm),answer)
  # Dynamic averages including negative updates; compare direct arithmetic.
  n=rng.randint(1,20);q=20;initial=[rng.randint(0,500) for _ in range(n)]
  columns={'A':initial[:],'B':[500-x for x in initial]};ops=[];answers=[]
  for _ in range(q):
   col=rng.choice('AB')
   if rng.random()<0.5:
    index=rng.randrange(n);delta=rng.randint(-600,600);columns[col][index]+=delta;ops.append((1,index+1,delta,col))
   else:
    l=rng.randrange(n);r=rng.randrange(l+1,n+1);a=columns[col][l:r];total=sum(a);answers.append(sum(x*len(a)>total for x in a));ops.append((2,l+1,r,col))
  check('BeatAverage',lines((n,q),initial,*ops),' '.join(map(str,answers)))
  # Greedy scheduling checked against every possible order.
  n=rng.randint(1,7);jobs=[(rng.randint(1,20),rng.randint(1,10)) for _ in range(n)]
  answer=min(sum(sum(a for a,_ in p[i:])*b for i,(_,b) in enumerate(p)) for p in itertools.permutations(jobs))
  check('Building',lines(n,*jobs),answer)
 # Cycle propagation: explicit edge-case fixtures.
 check('sheet','2 2\n=A1+1 2\n=A1+B1 =B1+3\n','ERROR 2\nERROR 5')
 check('sheet','1 3\n1 =A1+A1 =B1+9\n','1 2 11')
 check('sheet','1 3\n=B1+1 =A1+1 =B1+1\n','ERROR ERROR ERROR')
 # All valid low-bit OR/AND pairs, with exhaustive x/y reference.
 grouped={}
 for x in range(32):
  for y in range(32):grouped.setdefault((x|y,x&y),[]).append(abs(x-y))
 for (a,b),values in grouped.items():check('Encryption',lines(1,(a,b)),f'{max(values)} {min(values)}')
 report={'seed':20261016,'python_oracle_cases':counts,'total':sum(counts.values()),'failures':failures}

 print(json.dumps(report,ensure_ascii=False,indent=2))
 if failures:raise SystemExit(1)

if __name__=='__main__':main()
