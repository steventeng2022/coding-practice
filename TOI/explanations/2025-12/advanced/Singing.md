# 3-唱歌對決

2025/12/22~2025/12/26 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Singing.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Singing.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202512/Singing.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

將歌手依第一指標降序排列。固定左端歌手 i，右指標往左移，剔除第一指標相加仍為負者；留下的候選用 Fenwick 樹統計第二指標。查詢第二指標至少 −B[i] 的候選人數，累加即可。第二指標先座標壓縮。

## 正確性

對固定 i，排序使第一指標合格者在一段連續區間內。隨 i 向右，第一指標不增，右界只會向左，故雙指標不漏解。Fenwick 樹恰好維護尚未配對且第一指標合格的歌手，扣掉第二指標小於門檻者後，正好剩下兩條件都滿足的組合。每對只在較左者處計數一次。

## 複雜度

時間 O(N log N)，空間 O(N)。

## 實作注意

條件是相加大於等於 0，等號必須保留；組合數最多達 N(N−1)/2，C++ 答案需用 64 位元。

[C++ 程式](../../../cpp/2025-12/advanced/Singing.cpp)

[Python 程式](../../../python/2025-12/advanced/Singing.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
