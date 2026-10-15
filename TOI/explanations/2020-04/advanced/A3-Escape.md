# 3-迷宮逃離

2020/04/27~2020/05/04 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202004/A3-Escape.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202004/A3-Escape.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202004/A3-Escape.odp)

## 解題思路

每房間恰好破壞一座雕像，故只需一個布林變數表示左雕像，右雕像狀態為其反值。每條線索轉為兩房間變數的 XOR 關係，使用帶奇偶權重的並查集維護；同集合內若新關係與既有關係矛盾，就無解。

## 正確性

parity[u] 表示 u 與其集合根的狀態差。合併不同根時，將根間差值設為已知路徑差再 xor 所需關係，即可使新線索成立並保留全部舊線索。同根時其差值已被決定，只有相等的新關係可接受。所有線索無矛盾時，每個集合自由選一個根狀態即可構造完整解。

## 複雜度

時間 O((N+T)α(N))，空間 O(N)，另計輸入。按集合大小合併使遞迴 find 深度維持 O(log N)。

## 實作注意

L/R 的差異要先轉成同一種房間變數。每間房的兩座雕像必須相反；不是一般的任意二元選擇。

[C++ 程式](../../../cpp/2020-04/advanced/A3-Escape.cpp)

[Python 程式](../../../python/2020-04/advanced/A3-Escape.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
