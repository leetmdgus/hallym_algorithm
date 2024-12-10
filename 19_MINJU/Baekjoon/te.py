from collections import defaultdict

def process_requests(n, r, q, numbers, requests):
    results = []
    count = defaultdict(int)  # 현재 윈도우 내 번호별 개수

    def calculate_score(x):
        """x번째 사람의 점수를 계산"""
        left = max(0, x - r)
        right = min(n, x + r + 1)
        score = count[numbers[x]] - 1  # 같은 번호지만 본인은 제외
        return max(0, score)

    for req in requests:
        if req[0] == 1:  # 번호 변경 요청
            x, y = req[1] - 1, req[2]
            old_number = numbers[x]
            numbers[x] = y
            count[old_number] -= 1
            count[y] += 1
        elif req[0] == 2:  # 점수 계산 요청
            x = req[1] - 1
            results.append(calculate_score(x))

    return results

# 입력 처리
n, r, q = map(int, input().split())
numbers = list(map(int, input().split()))
requests = []
for _ in range(q):
    request = list(map(int, input().split()))
    requests.append(request)

# 요청 처리 및 결과 출력
results = process_requests(n, r, q, numbers, requests)
print("\n".join(map(str, results)))
