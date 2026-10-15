# 2-社團

2025/12/22~2025/12/26 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Club.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Club.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Club.odp)

## 解題思路

每名學生的三個志願先轉成集合，再將集合中的各社團計數加一。另存原社團順序以便輸出。

## 正確性

集合保證同一名學生對同一社團最多貢獻一次；不同學生各自累加，因此統計值就是填寫該社團的人數。依原順序輸出即符合要求。

## 複雜度

期望時間 O(N+M)，額外空間 O(M)，另計輸入。

## 實作注意

同一學生可能重複填同一社團，不能直接把三個志願逐項加一。

[C++ 程式](../../../cpp/2025-12/beginner/Club.cpp)

[Python 程式](../../../python/2025-12/beginner/Club.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
