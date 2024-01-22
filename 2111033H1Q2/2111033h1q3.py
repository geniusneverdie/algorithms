n=int(input())
if n>=0:
    print(n)
else:
    n=-n
    print(-min(n//10,(n//100*10+n%10)))