# 42646 - Lv.2 더 맵게

import heapq

def solution(scoville, k):
  heap = []
  for num in scoville:
    heapq.heappush(heap, num)
    cnt = 0
    while heap[0] < k:
      try:
        heapq.heappush(heap, heapq.heappop(heap) + (heapq.heappop(heap) * 2))
        except IndexError:
          return -1
        
        cnt += 1
        return cnt
      
