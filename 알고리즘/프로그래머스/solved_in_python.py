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
