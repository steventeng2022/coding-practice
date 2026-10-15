# 3-取締違規

2025/03/17~2025/03/21 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Police.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Police.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202503/Police.odp)

## 解題思路

每個閉區間 [L,R] 的違規數量在差分陣列 L 加 A、R+1 減 A。由小到大取前綴和，得到每個位置的總違規數；只在嚴格變大時更新最佳位置。

## 正確性

單個區間對前綴和在 L 前貢獻 0、L 到 R 貢獻 A、R 後回到 0，所以所有區間相加得到每點真實數量。由小到大且同分不更新，保留最早的最大值位置。

## 複雜度

時間 O(N+M)，空間 O(M)，另計輸入。

## 實作注意

區間包含右端，因此減量位置是 R+1。平手取最小位置，更新條件需用 >。

[C++ 程式](../../../cpp/2025-03/advanced/Police.cpp)

[Python 程式](../../../python/2025-03/advanced/Police.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
