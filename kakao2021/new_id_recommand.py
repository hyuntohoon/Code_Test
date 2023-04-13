import re

def combine_dots(input_id):
    pattern = re.compile(r'\.{2,}')
    return pattern.sub('.', input_id)

def solution(new_id):
    answer = ''
    new_id = new_id.lower()
    new_id = re.sub('[^a-z0-9-_.]', '', new_id)
    new_id = combine_dots(new_id)
    if new_id[0] == '.':
        new_id = new_id[1:]
        if len(new_id) == 0:
            new_id = "aaa"
    if new_id[-1] == '.':
        new_id = new_id[:-1]
    if len(new_id) == 0:
        new_id = "a"
    if len(new_id) > 15:
        new_id = new_id[:15]
        if new_id[14] == ".":
            new_id = new_id[:14]
    if len(new_id) < 3:
        last_char = new_id[len(new_id)-1]
        new_id += last_char
        if len(new_id) < 3:
            last_char = new_id[len(new_id)-1]
            new_id += last_char
    answer = new_id
    return answer



'''
1. 모두 소문자
2. 허용 문자 소문자, 숫자, 빼기, 밑줄, 마침표
3. ".." 두개 이상 => 하나로
4. "." 처음과 끝은 제거
5. 빈 문자열 => "a" 추가
6. 길이 16이상 => 15길이까지만 보이기, 제거 후 끝에 "." 존재시 "." 삭제
7. 길이가 2자 이하 => 길이가 3이 될 때까지 반복

구현 
1. => lower함수
2. 정규화
3. find 함수?
4. 처음과 끝 확인
5. 빈문자열 insert a
6. length 체크 + 끝 확인
7. 길이 체크 후 문자 추가
'''