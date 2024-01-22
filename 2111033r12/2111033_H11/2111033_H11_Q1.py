import random

def is_prime(i, m=2):
    if i==1:
        return False
    if i==2:
        return True
    while m**2 <=i:

        if not i%m:
            return False
        m+=1

    return True


def fingerCompute(ls, match, p):
    # return s match的指纹

    f1 = f2 = 0
    od = len(match)
    for c in range(len(match)):
        f1 += pow(2, len(match)-c-1, p) * (ord(ls[c])-65) % p
        f2 += pow(2, len(match) - c - 1, p) * (ord(match[c])-65) % p
        # f2 += (ord(match[c])-65) % p
    return f1, f2


def _match(s, match):
    while True:
        p = random.randint(1, 1e5)
        if is_prime(p):
           break
    f1, f2 = fingerCompute(s, match, p)
    wp = pow(2,len(match),p)
    for j in range(len(s)-len(match)):
        if f1 == f2:
            return True, j
        f1 = ( 2 * f1 - wp * (ord(s[j])-65) + ord(s[j+len(match)])-65 ) % p

    return  False, -1

def _print(x,mat):
    a, b = _match(list(x), list(mat))
    print("X:",x,'\nmatch:', mat)
    print(f'match是否在x中被匹配:{a}')
    if a:
        print('在x中的位置:', b)


if __name__ == '__main__':
    # print([(x, is_prime(x)) for x in range(1, 101)])
    # x = 'asdjwfhsdvhxcuic'
    # m = 'qwe'
    # _print(x, m)
    # x = 'asdawxadsdaswxas '
    # m = 'xas'
    # _print(x, m)
    # x = 'asdawxasdsdaswxas '
    # m = 'xas'
    # _print(x, m)
    print("请输入...")
    x = input("X=")
    m =  input("match=")
    _print(x, m)

