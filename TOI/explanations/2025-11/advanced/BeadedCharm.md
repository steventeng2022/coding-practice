# 3-串珠吊飾

2025/11/10~2025/11/14 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/BeadedCharm.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/BeadedCharm.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202511/BeadedCharm.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

將掛點 0 作為 DFS 根，求 tin、low 與子樹大小。樹邊 (父,子) 若滿足 low[子]>tin[父] 就是橋；切斷時掉落的恰是子節點那側的整棵子樹。非橋被切斷仍存在替代路徑，不會掉落。使用顯式堆疊，避免 Python 深遞迴。

## 正確性

low[子] 記錄子樹能經非父邊返回的最早祖先；大於父的進入時間，代表沒有任何替代邊可跨過此樹邊，因此它是橋。切橋後不含根 0 的部分正好是該子樹，其大小由 DFS 回溯累加；根所在部分剩 N−子樹大小。

## 複雜度

時間 O(N+M+Q)，空間 O(N+M)，另計輸入輸出。

## 實作注意

所有詢問獨立，不應真的刪邊。根固定為吊飾掛點 0；應扣掉橋的子節點子樹，不是任意選較小的連通塊。

[C++ 程式](../../../cpp/2025-11/advanced/BeadedCharm.cpp)

[Python 程式](../../../python/2025-11/advanced/BeadedCharm.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
