# 1-島嶼

2025/06/09~2025/06/13 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Island.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Island.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202506/Island.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

先洪水填色標記第一座島的所有陸地，再以這些格子共同作為 BFS 起點，向海面逐層擴展。首次遇到尚未標記的陸地時，擴展過的海格層數就是所需填海數量。

## 正確性

第一座島內移動不需要填海，故所有島格距離均為 0。BFS 每穿過一層海面增加一次填海數，因此第一次接觸另一座島時使用的海格數最少。入隊即標記，確保各格最多處理一次。

## 複雜度

時間 O(NM)，空間 O(NM)。

## 實作注意

抵達第二座島的陸地不應再算一格海；應從第一島全部格子出發，而非僅從某一個起點出發。

[C++ 程式](../../../cpp/2025-06/advanced/Island.cpp)

[Python 程式](../../../python/2025-06/advanced/Island.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
