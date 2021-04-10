# 두개뽑아서 더하기

def solution(numbers):
answer = [];
for i in range(len(numbers)):
    for j in range(i+1, len(numbers)):
        answer.append(numbers[i] + numbers[j])
return sorted(list(set(answer)))


# 2016년

def solution(a, b):
    answer = ''
    months = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    days = ['FRI', 'SAT', 'SUN', 'MON', 'TUE', 'WED', 'THU']
    return days[(sum(months[:a-1])+b-1)%7]


# 완주하지 못한 선수

import collections

def solution(participant, completion):
    answer = collections.Counter(participant) - collections.Counter(completion)
    print(collections.Counter(participant))
    print(collections.Counter(completion))
    print(answer)
    return list(answer.keys())[0]


# k번째 수

def solution(array, commands):
    answer = []
    for i in range(commands):
        a = array[i[0]-1:i[1]]
        a.sort()
        answer.append(a[i[2]-1])
    return answer

# 가운데 글자 가져오기

def solution(s):
    answer = ''
    if len(s) % 2 == 0:
        return s[int(len(s)/2)-1] + s[int(len(s)/2)]
    else:
        return s[int(len(s)/2)]

# 같은 숫자는 싫어

def no_continuous(s):
    result = []
    for c in s:
        if (len(result) == 0) or (result[-1] != c):
            result.append(c)
    return result

# 두정수 사이의 합


def solution(a, b):
    return sum(range(min(a,b),max(a,b)+1))


# 문자열 내 마음대로 정렬하기

def solution(strings, n):
    answer = []
    for i in range(len(strings)):
        strings[i] = strings[i][n] + strings[i]
    strings.sort()
    for j in range(len(strings)):
        answer.append(strings[j][1:])
    return answer

# 폰켓몬

def solution(nums):
    answer = 0
    if int(len(nums)/2) > len(set(nums)):
        return len(set(nums))
    else:
        return int(len(nums)/2)

# 문자열 내 p와 y의 개수

def solution(s):
    answer = True
    p_count = 0
    y_count = 0
    for i in s.lower():
        if i == 'p':
            p_count += 1
        if i == 'y':
            y_count += 1
    if p_count == y_count:
        return True
    else:
        return False

# 소수찾기

def solution(n):
    answer = 0
    prime = [0 for i in range(n+1)]
    prime[0] = 1
    prime[1] = 1
    for i in range(2,n+1):
        for j in range(i*2,n+1,i):
            prime[j] = 1
    for i in range(n+1):
        if prime[i] == 0:
            answer += 1
    return answer

# 시저 암호

def solution(s, n):
    s = list(s)
    for i in range(len(s)):
        if s[i].isupper():
            s[i]=chr((ord(s[i])-ord('A')+ n)%26+ord('A'))
        elif s[i].islower():
            s[i]=chr((ord(s[i])-ord('a')+ n)%26+ord('a'))

    return "".join(s)   


# 약수의 합

def solution(n):
    return sum([i for i in range(1,n+1) if n%i==0])

# 소수 만들기

from itertools import combinations
def solution(nums):
    answer = 0
    nums.sort()
    prime = sum(nums[-3:])
    a = [0 for i in range(prime+1)]
    a[0] = 1
    a[1] = 1
    for i in range(2, prime+1):
        for j in range(i*2, prime+1 ,i):
            a[j] = 1
    result = list(combinations(nums,3))
    for i in result:
        if a[sum(i)] == 0:
            answer += 1
    return answer

# 프린터

import math
def solution(priorities, location):
    answer = 0
    cur = 0
    while 1:
        max_el = max(priorities)
        if(cur == len(priorities)):
            cur = 0
            continue
        if priorities[cur] < max_el:
            cur += 1
            continue
        if priorities[cur] == max_el:
            if(cur == location):
                break;
            priorities[cur] = 0
            answer += 1
            cur += 1
            continue
    return answer + 1
